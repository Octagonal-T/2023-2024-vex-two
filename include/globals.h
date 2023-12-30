#include "main.h"
#include "lemlib/api.hpp"

#ifndef GLOBALS_H_
#define GLOBALS_H_

extern pros::Controller controller;

extern pros::Motor left_font_motor;
extern pros::Motor left_back_motor_bottom;
extern pros::Motor left_back_motor_top;
extern pros::Motor right_font_motor;
extern pros::Motor right_back_motor_bottom;
extern pros::Motor right_back_motor_top;


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