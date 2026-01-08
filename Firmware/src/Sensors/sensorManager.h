#pragma once
#include "imu_bmi088.h"

struct SensorData
{
    float accel[3];
    float gyro[3];
    float mag[3];
    float pressure;
    float altitude;
    // add more
};

class Sensors
{
public:
    void initAll();
    void updateAll();
    SensorData getData() const; // return combined readings

private:
    IMU_BMI088 imu;
    // add more
    SensorData data;
};
