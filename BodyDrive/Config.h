#define LEFT_SERVO_PIN 3
#define RIGHT_SERVO_PIN 2

#define SIDE_TO_SIDE_MOTOR_R_PWM_PIN 13
#define SIDE_TO_SIDE_MOTOR_L_PWM_PIN 12

#define SIDE_TO_SIDE_TILT_PID_KP 14
#define SIDE_TO_SIDE_TILT_PID_Ki 0
#define SIDE_TO_SIDE_TILT_PID_KD 0
#define SIDE_TO_SIDE_TILT_PID_DT 20

#define SIDE_TO_SIDE_STABILITY_PID_KP 0.5
#define SIDE_TO_SIDE_STABILITY_PID_Ki 0
#define SIDE_TO_SIDE_STABILITY_PID_KD 0.01
#define SIDE_TO_SIDE_STABILITY_PID_DT 20

#define MAX_SIDE_TO_SIDE_TILT 20
#define SIDE_TO_SIDE_SPEED 3

#define FLYWHEEL_SPIN_MOTOR_R_PWM_PIN 11
#define FLYWHEEL_SPIN_MOTOR_L_PWM_PIN 10

#define DOME_MOTOR_IN3_PIN 8
#define DOME_MOTOR_IN4_PIN 9

#define MAIN_DRIVE_MOTOR_PID_KP 5
#define MAIN_DRIVE_MOTOR_PID_Ki 0
#define MAIN_DRIVE_MOTOR_PID_KD 0
#define MAIN_DRIVE_MOTOR_PID_DT 20

#define MAIN_DRIVE_MOTOR_R_PWM_PIN 6
#define MAIN_DRIVE_MOTOR_L_PWM_PIN 4

#define FLYWHEEL_SPIN_AND_MAIN_DRIVE_ENABLE_PIN 32
#define SIDE_TO_SIDE_ENABLE_PIN 52

#define SIDE_TO_SIDE_POT_PIN A1
#define BATTERY_VOLTAGE_PIN A0

#define DOME_SPEED 20
#define MAX_DOME_TILT_X 14      // Maximum angle to tilt the dome in the X axis ** - MAX IS 18
#define MAX_DOME_TILT_Y  15      // Maximum angle to tilt the dome in the Y axis ** - MAX IS 20
#define DOME_X_SPEED 0.7          // Speed of side to side domemovement, higher == faster
#define DOME_Y_SPEED 0.4          // Spead of front to back dome movement, higher == faster

// #define PID_INTEGER
