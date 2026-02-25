#include <Arduino.h>
#include "Sensors/sensorManager.h"
#include "Sensors/imu_bmi088.h"

Sensors sensors(SPI, 10, 9); // configure csAccel, csGyro pins

void setup()
{
    Serial.begin(115200);

    sensors.initAll();
    // rc.init();
    // actuators.init();
    // estimator.init();
    // controller.init();
}

void loop()
{
    sensors.updateAll();
    // rc.update();

    // estimator.update(sensors.data);
    // controller.update(rc.commands, estimator.state);
    // mixer.mix(controller.output);
    // actuators.write(mixer.outputs);
}
