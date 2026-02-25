#ifndef PID_CONTROLLER_H
#define PId_CONTROLLER_H

// referred to Phil's Lab #6

typedef struct
{
    // Controller gain
    float Kp;
    float Ki;
    float Kd;

    // LPF time constant for D-term (to suppress amplified HF noise from D-term)
    float tau;

    // Output clamp limits
    float limMin;
    float limMax;

    // Sampling time (sec)
    float T;

    // Controller "memoryt"
    float integrator;
    float prevError;
    float differentiator;
    float prevMeas;

    // Controller output
    float out;

} PIDController;

void PIDController_Init(PIDController *pid);
float PIDController_Update(PIDController *pid, float setpoint, float meas);

#endif