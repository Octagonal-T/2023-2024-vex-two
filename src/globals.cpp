#include "main.h"
#include "globals.h"

//GLOBAL PORT DEFINITIONS
#define LEFT_DRIVE_MOTOR 1

//GLOBAL PROS OBJECT DEFINITIONS
pros::Motor leftDrive (LEFT_DRIVE_MOTOR, pros::E_MOTOR_GEAR_600, false, pros::E_MOTOR_ENCODER_DEGREES);