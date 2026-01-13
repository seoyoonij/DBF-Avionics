
## 9 DoF IMU sensor fusion 

1. Read data from sensors
    - BMI088: gyro + accel ---v
    - LIS3MDL: mag 
    - BMP390: barom

2. Synchronize data
    - consider sampling rate of each --> interpolate slower one

3. Sensor fusion
    - filters: complementary/ Madgwich/ Mahony
    - compute roll, pitch, yaw from accel+gyro+mag
    - advance to EKF

4. Filtering
- High-G and vibration: low-pass filter on accel and mag to reduce noise
