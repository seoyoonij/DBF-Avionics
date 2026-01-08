#include "sensorManager.h"

void Sensors::init()
{
    imu.begin();
    // add more
}

void Sensors::update()
{
    imu.read(data.accel, data.gyro);
    // add more
}
