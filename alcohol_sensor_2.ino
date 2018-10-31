#include "SevenSegmentTM1637.h"

const byte PIN_CLK = 9;
const byte PIN_DIO = 8;
SevenSegmentTM1637    display(PIN_CLK, PIN_DIO);

const int ANALOG_PIN = 0;
const float R0 = 0.40; // actual board resistance in clean air

void setup() {
  display.begin();
  //set the diplay to maximum brightness
  display.setBacklight(100);
  display.print("ALCO");
  Serial.begin(9600);
  delay(1000);
}

void loop() {
  delay(1000);
  display.clear();

  int concentration = readAlcohol();
  
  float sensorVolts = getVolts(concentration);
  float ratio = getRsR0Ratio(sensorVolts);
  float bac = getBAC(ratio);
  
  Serial.println("--------------");
  Serial.print("Sensor volts = ");
  Serial.print(sensorVolts);
  Serial.println("V");
  
  Serial.print("Rs/R0 ratio= ");
  Serial.println(ratio);
  
  Serial.print("BAC= ");
  Serial.println(bac);
 

  Serial.println("--------------");
  printConcentration(concentration);
  printDrunkLevel(concentration);
  delay(100);
  display.print(concentration);
  displayAlco(concentration);
}

// measurement

int readAlcohol() {
  int val = 0;
  for (int i=0; i <= 5; i++){
      int current = analogRead(ANALOG_PIN);
      val += current;
      delay(10);
  }
  return val / 5;
}


// calculations

float getVolts(int resist) {
  float volts = float(resist) / 1024.0 * 5.0;
  return volts;
}


float getRsR0Ratio(float volts) {
  float RS_gas = (5.0 - volts) / volts;
  float ratio = RS_gas/R0;
  return ratio;
}

// BAC in mg/L
float getBAC (float ratio) {
  // formula got from polynomial regressoin based on 
  // device datasheet values
  float bac = 0.1895*ratio*ratio - 0.8617*ratio + 1.0792;
  return bac;
}


// printing helpers

void printConcentration(int value) {
  Serial.print("Alcohol Concentration : ");
  Serial.println(value);
//  Serial.println(" mg/l");
}

void displayAlco(int value) {
  if (value < 200) {
    display.print(value);
    delay(1000);
    display.print("SOBR");
  }
  if (value >= 200 && value < 350) {
    display.print(value);
    delay(1000);
    display.print("BEER");
  }
  if (value >= 350 && value < 450) {
    display.print(value);
    delay(1000);
    display.print("UODK");
  }
  if (value > 450) {
    display.print(value);
    delay(1000);
    display.print("DRNK");
  }
}

void printDrunkLevel(int value) {
  if (value < 200) {
    Serial.println("You are sober.");
  }
  if (value >= 200 && value < 280) {
    Serial.println("You had a beer.");
  }
  if (value >= 280 && value < 350) {
    Serial.println("Two or more beers.");
  }
  if (value >= 350 && value < 450) {
    Serial.println("I smell Vodka!");
  }
  if (value > 450) {
    Serial.println("You are drunk!");
  }
}
