DBF Avionics

Folder Dependency (one-directional):
    drivers → services → estimation → control → actuators

Firmware Structure: 
    src/
    ├── main.cpp

    ├── drivers/           # Hardware-specific
    │   ├── sensors/
    │   │   ├── imu_bmi088.cpp
    │   │   ├── imu_bmi088.h
    │   │   ├── mag_lis3mdl.cpp
    │   │   └── mag_lis3mdl.h
    │   ├── rc/
    │   │   ├── rc_sbus.cpp
    │   │   └── rc_sbus.h
    │   └── actuators/
    │       ├── pwm_out.cpp
    │       └── pwm_out.h

    ├── services/          # Orchestration
    │   ├── sensor_manager.cpp
    │   ├── sensor_manager.h
    │   ├── rc_manager.cpp
    │   ├── rc_manager.h
    │   ├── actuator_manager.cpp
    │   └── actuator_manager.h

    ├── estimation/        # Algorithm magic
    │   ├── attitude_estimator.cpp
    │   ├── attitude_estimator.h
    │   └── state_estimator.h

    ├── control/           # Control laws
    │   ├── pid.cpp
    │   ├── pid.h
    │   ├── flight_controller.cpp
    │   └── flight_controller.h

    ├── mixing/
    │   ├── mixer.cpp
    │   └── mixer.h

    ├── common/
    │   ├── types.h        # Shared structs
    │   ├── config.h
    │   └── math_utils.h
