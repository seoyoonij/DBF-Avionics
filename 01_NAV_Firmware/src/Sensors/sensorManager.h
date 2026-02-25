#pragma once
#include "imu_BMI088.h"
#include "mag_LIS3MDL.h"
// add more

struct SensorData
{
    float accel[3];
    float gyro[3];
    float tempC;
    float mag[3];
    float pressure;
    float altitude;
    // add more
};

class Sensors
{
public:
    Sensors(SPIClass &spi, uint8_t csAccel, uint8_t csGyro);
    void initAll();
    void updateAll();
    SensorData getData() const; // return combined readings

private:
    IMU_BMI088 imuSensor;
    mag_LIS3MDL magSensor;
    // add more
    SensorData data;

    bool sensorErrorFlag = false;
};
