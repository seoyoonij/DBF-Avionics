# DBF-Avionics

Folder Dependency: \
     [NAV] drivers → services → estimation → [FMU] → control → actuators \

    - struct-based data, no global variables
    - keep it modular and readable

**NAV Firmware:** \
    src/ \
    ├── main.cpp \

    ├── drivers/           # Hardware-specific
    │   ├── sensors/
    │   │   ├── imu_bmi088.cpp
    │   │   ├── imu_bmi088.h
    │   │   ├── mag_lis3mdl.cpp
    │   │   └── mag_lis3mdl.h

    ├── services/          # Orchestration
    │   ├── sensor_manager.cpp
    │   ├── sensor_manager.h

    ├── estimation/        # Algorithm magic
    │   ├── attitude_estimator.cpp
    │   ├── attitude_estimator.h
    │   ├── position_estimator.cpp
    │   ├── position_estimator.h
    │   ├── ekf.cpp
    │   └── ekf.h

    ├── comm/        # Link with FMU
    │   ├── nav_link.cpp

    ├── core/
    │   ├── types.h        # Shared structs
    │   ├── config.h
    │   └── math_utils.h

**FMU Firmware:** \
    src/ \
    ├── main.cpp \

    ├── drivers/           # Hardware-specific
    │   ├── rc/
    │   │   ├── rc_sbus.cpp
    │   │   └── rc_sbus.h
    │   └── actuators/
    │       ├── pwm_out.cpp
    │       └── pwm_out.h

    ├── services/          # Orchestration
    │   ├── rc_manager.cpp
    │   ├── rc_manager.h
    │   ├── actuator_manager.cpp
    │   └── actuator_manager.h

    ├── control/           # Control laws
    │   ├── pid.cpp
    │   ├── pid.h
    │   ├── flight_controller.cpp
    │   └── flight_controller.h

    ├── mixing/
    │   ├── mixer.cpp
    │   └── mixer.h

    ├── comm/        # Link with NAV
    │   ├── nav_link.cpp

    ├── core/
    │   ├── types.h        # Shared structs
    │   ├── config.h
    │   └── math_utils.h
