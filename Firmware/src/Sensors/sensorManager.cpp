#include "sensorManager.h"

Sensors::Sensors(SPIClass &spi, uint8_t csAccel, uint8_t csGyro)
    : imuSensor(spi, csAccel, csGyro)
{
}

void Sensors::initAll()
{
    imuSensor.begin();
    magSensor.begin();
    // add more
}

void Sensors::updateAll()
{
    bool allOk = true;
    allOk &= imuSensor.read(data.accel, data.gyro);
    allOk &= imuSensor.readTempC(data.tempC);
    allOk &= magSensor.read(data.mag);
    // add more

    // error handling
    if (!allOk)
    {
        sensorErrorFlag = true;
        Serial.println("Sensor read failed");
    }
}
