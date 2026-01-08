#pragma once
#include <BMI088.h>
#include <SPI.h>

class SPIClass;

class IMU_BMI088
{
public:
    IMU_BMI088(SPIClass &spi, uint8_t cs_accel, uint8_t cs_gyro);

    bool begin();
    void read(float accelOut[3], float gyroOut[3]);
    float readTempC();

private:
    SPIClass &_spi;
    uint8_t _csAccel;
    uint8_t _csGyro;

    Bmi088Accel accel;
    Bmi088Gyro gyro;
};