#include "sensorManager.h"

void Sensors::initAll()
{
    imu.begin();
    // add more
}

void Sensors::updateAll()
{
    imu.read(data.accel, data.gyro);
    // add more
}
