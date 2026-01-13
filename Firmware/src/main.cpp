#include <Arduino.h>
#include "Sensors/sensorManager.h"
#include "Sensors/imu_bmi088.h"

Sensors sensors;

void setup()
{
    Serial.begin(115200);

    sensors.initAll();
}

void loop()
{
    sensors.updateAll();
}
