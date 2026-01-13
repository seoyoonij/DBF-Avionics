#include "mag_LIS3MDL.h"

mag_LIS3MDL::mag_LIS3MDL(uint8_t i2cAddr, TwoWire &wire) : _i2cAddr(i2cAddr), _wire(wire)
{
}

bool mag_LIS3MDL::begin()
{
    if (mag.begin_I2C(_i2cAddr, &_wire))
    {
        return false;
    }
    // optional: add configuration methods

    return true;
}

bool mag_LIS3MDL::read(float magOut[3])
{
    sensors_event_t event;
    if (!mag.getEvent(&event))
    {
        return false;
    }
    magOut[0] = event.magnetic.x;
    magOut[1] = event.magnetic.y;
    magOut[2] = event.magnetic.z;
    return true;
}