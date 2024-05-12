#include <Arduino.h>
#include "waterpump.h"
#include "waterpumpmgr.h"


const int sensor1Pin = A0;  
const int pump1Pin = 10;  
const int sensorOnOffPin = 2;  
WaterPumpMgr::waterPumpMgr waterPumpMgr;
WaterPump::WaterPump waterPumps[6];


void setup() {
    Serial.begin(9600); // open the serial port at 9600 bps:
    waterPumps[0].sensorPin=A0;
    waterPumps[0].pumpPin=10;
    
}

void loop() {
  float read=waterPumpMgr.calcSoilHumid(waterPumps[0].sensorPin,sensorOnOffPin);
 // waterPumpMgr.water(read,pump1Pin);

  delay(5000);
}
