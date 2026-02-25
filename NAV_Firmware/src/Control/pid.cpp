#include "pid.h"

void PIDController_Init(PIDController *pid)
{

    // Clear controller variables
    pid->integrator = 0.0f;
    pid->prevError = 0.0f;

    pid->differentiator = 0.0f;
    pid->prevMeas = 0.0f;

    pid->out = 0.0f;
}

float PIDController_Update(PIDController *pid, float setpoint, float meas)
{
    // Error signal
    float error = setpoint - meas;
    // Proportional
    float proportional = pid->Kp * error;
    // Integral
    float integrator = pid->integrator + (0.5f * pid->T * (error + pid->prevError));

    /* Anti-wind-up via dynamic integrator clamping (to prevent I-term from saturating the output) */
    float limMinInt, limMaxInt;

    // Compute integrator limits
    if (pid->limMax > proportional)
    {
        limMaxInt = pid->limMax - proportional;
    }
    else
    {
        limMaxInt = 0.0f;
    }

    if (pid->limMin < proportional)
    {
        limMinInt = pid->limMin - proportional;
    }
    else
    {
        limMinInt = 0.0f;
    }

    // Clamp integrator
    if (pid->integrator > limMaxInt)
    {
        pid->integrator = limMaxInt;
    }
    else if (pid->integrator < limMinInt)
    {
        pid->integrator = limMinInt;
    }

    // Derivative (band-limited differentiation + deriv-on-measurement to suppress "kicks")
    pid->differentiator = (2.0f * pid->Kd * (meas - pid->prevMeas) + (2.0f * pid->tau - pid->T * pid->differentiator) / (2.0f * pid->tau + pid->T));

    // Compute output and apply limits
    pid->out = proportional + pid->integrator + pid->differentiator;

    if (pid->out > pid->limMax)
    {
        pid->out = pid->limMax;
    }
    else if (pid->out < pid->limMin)
    {
        pid->out = pid->limMin;
    }

    // Store for prev error and meas
    pid->prevError = error;
    pid->prevMeas = meas;

    return pid->out;
}
