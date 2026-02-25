#pragma once
#include <Adafruit_LIS3MDL.h>
#include <Wire.h>

class mag_LIS3MDL
{

public:
    mag_LIS3MDL(uint8_t i2cAddr = LIS3MDL_I2CADDR_DEFAULT, TwoWire &wire = Wire);

    bool begin();
    bool read(float magOut[3]);

private:
    // store pin config within mag object
    TwoWire &_wire;
    uint8_t _i2cAddr;

    // magnetometer object
    Adafruit_LIS3MDL mag;
};
