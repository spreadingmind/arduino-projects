## Arduino projects

Contains very basic yet actually working scripts for Arduino. 

### Requirements
- Arduino IDE or any other development platform
- Arduino UNO / Leonardo 

### Installing dependencies
Some scripts use external libraries that should be installed and compiled before uploading on Arduino.
Using Arduino software, they could be installed right in the IDE. 


### Scripts

#### Alcohol sensor

Measures alcohol concentration in the air and converts to approximate blood concentration using a formula from [this tutorial](http://wiki.seeedstudio.com/Grove-Gas_Sensor-MQ3/).

The correctness of a formula is under question so I'm still working on getting right numbers for concentration.

Dispaly shows 5 levels of drunkness:

- SOBR = you are sober
- BEER = you had one to several beers
- VODK = you had a vodka
- DRNK = you are very drunk


Modules:

    - MQ3 Flying Fish sensor
    - TM1637 4-digit display

Before running this script, you should calibrate the sensor and set R0 variable to a resistance value you get from your sensor. 

See the tutorial above on how to calibrate the device.

[MQ3 Datasheet](https://raw.githubusercontent.com/SeeedDocument/Grove-Gas_Sensor-MQ3/master/res/MQ-3.pdf)


### Temperature-humidity sensor

Shows temperature and humidity in following format

- `CE: number in C`
- `HU: number in %`

Modules:

    - DH11 Temperature/Humidity sensor
    - TM1637 4-digit display

[DH11 Datasheet](http://www.circuitbasics.com/wp-content/uploads/2015/11/DHT11-Datasheet.pdf)