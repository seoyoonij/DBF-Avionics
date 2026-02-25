#include "imu_BMI088.h"

IMU_BMI088::IMU_BMI088(SPIClass &spi, uint8_t cs_accel, uint8_t cs_gyro)
    : _spi(spi), _csAccel(cs_accel), _csGyro(cs_gyro), accel(spi, cs_accel), gyro(spi, cs_gyro)
{
}

bool IMU_BMI088::begin()
{
    if (accel.begin() <= 0)
        return false;
    if (gyro.begin() <= 0)
        return false;
    return true;
}

bool IMU_BMI088::read(float accelOut[3], float gyroOut[3])
{
    accel.readSensor();
    accelOut[0] = accel.getAccelX_mss();
    accelOut[1] = accel.getAccelY_mss();
    accelOut[2] = accel.getAccelZ_mss();

    gyro.readSensor();
    gyroOut[0] = gyro.getGyroX_rads();
    gyroOut[1] = gyro.getGyroY_rads();
    gyroOut[2] = gyro.getGyroZ_rads();

    return true;
}

bool IMU_BMI088::readTempC(float &temp)
{
    temp = accel.getTemperature_C();
    return true;
}