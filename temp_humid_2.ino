#include <dht.h>
#include "SevenSegmentTM1637.h"

dht DHT;
#define DHT11_PIN 7

const byte PIN_CLK = 9;
const byte PIN_DIO = 8;
SevenSegmentTM1637    display(PIN_CLK, PIN_DIO);

void setup(){
  Serial.begin(9600);
  display.begin();           
  display.setBacklight(100);
  display.print("HI");
  delay(1000);
}

void loop()
{
  display.clear();
  display.setColonOn(true);


  int chk = DHT.read11(DHT11_PIN);
  int temp = DHT.temperature;
  int humid = DHT.humidity;

  Serial.println("-----------------------");
  Serial.print("Temperature = ");  
  Serial.println(temp);              

  Serial.print("Humidity = ");
  Serial.println(humid);
  Serial.println("-----------------------");

  String t = "CE" + String(temp);
  String h = "HU" + String(humid);

  display.print(t);
  
  delay(1000);
  display.clear();
                       
  display.print(h);

  delay(3000);
}
