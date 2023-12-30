#include "main.h"
#include "lemlib/api.hpp"
#ifdef GLOBALS_H_
#define GLOBALS_H_

extern pros::MotorGroup left_side_motors;
extern pros::MotorGroup right_side_motors;

extern pros::Motor intake;
extern pros::Motor slapper;

extern pros::IMU inertial;
extern pros::Distance intake_distance;
extern pros::ADIEncoder horizontal_encoder;

//lemlib objects

extern lemlib::Chassis chassis;

#endif