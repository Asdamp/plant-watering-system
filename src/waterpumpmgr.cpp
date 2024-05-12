#include "waterpumpmgr.h"
#include <Arduino.h>

using namespace WaterPumpMgr;


bool waterPumpMgr::water(float sensorValue, int pumpNumber)
{
    if (sensorValue >= 2.00 /*&& sensorValue <= 1.52*/)
    {                                   
        digitalWrite(pumpNumber, LOW);  
        delay(20000);                  
        digitalWrite(pumpNumber, HIGH); 
        return true;
    }
    else
    {
        return false;
    }
}
//1.05 water
//1.62 ouitside

float waterPumpMgr::calcSoilHumid(int sensorPin, int gndPin)
{
    pinMode(gndPin, OUTPUT);
    digitalWrite(gndPin, LOW);
    delay(3000);
    int sensorReading=analogRead(sensorPin);
    float measuredValue = (float(sensorReading) / 1023.0) * 5;
    Serial.print("Soil moisture sensor ");
    Serial.print(sensorPin);
    Serial.print(" value: ");
    Serial.print(measuredValue);
    Serial.println(" V"); // print voltage
    Serial.println(sensorReading);
    // turn off the sensor
    pinMode(gndPin, INPUT);

    return measuredValue;
}