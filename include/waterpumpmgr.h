#include <Arduino.h>
namespace WaterPumpMgr
{
    class waterPumpMgr
    {
    public:
        bool water(float sensorValue, int pumpNumber);
        float calcSoilHumid(int sensorPin, int gndPin);
    };
}