Work in Progress. Feel free to add details/reminders as you go.

## <1> Sensor manager  

    1. Complete 9 DoF IMU sensor fusion: (or if im using barometer and more sensors anyways, should i just try to merge them all at once, instead of merging the 9 dof imu first then do the merging and filtering again later with other sensor data? or is this approach cleaner and more logical)
        (1) Read data from sensors
        - BMI088: gyro + accel ---v
        - LIS3MDL: mag 
        - BMP390: barom

        (2) Synchronize data
        - consider sampling rate of each --> interpolate slower one

        (3) Sensor fusion
        - filters: complementary/ Madgwich/ Mahony
        - compute roll, pitch, yaw from accel+gyro+mag

        (4) Filtering
        - High-G and vibration: low-pass filter on accel and mag to reduce noise

    2. Complete drivers for all sensors 

## <2> RC input manager

## <3> Shared data structs in types.h
    1. ControlInput
    2. SensorData
    3. StateEstimate
    4. ControlOuput
    5. ActuatorOuput

## <4> Attitude/ State estimator interface

## <5> Control module interface

## <6> Actuator manager + mixer

## <7> Fancy math & Algorithm magic

## <8> Redundancy, Debuggablility
    1. Timing/scheduler
    2. Logging --> TELEMETRY
    3. Failsafe
    4. Health monitoring

## <9> Telemetry
    1. Package data and trasmit
    2. Ground station setup
