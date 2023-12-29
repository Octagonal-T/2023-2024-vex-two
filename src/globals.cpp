#include "main.h"
#include "globals.h"
#include "lemlib/api.hpp"

//global port definitions
#define LEFT_FRONT_MOTOR 1
#define LEFT_BACK_MOTOR 2
#define RIGHT_FRONT_MOTOR 3
#define RIGHT_BACK_MOTOR 4

#define INTAKE_DISTANCE 19
#define INERTIAL_SENSOR 20

//controller
pros::Controller controller (pros::E_CONTROLLER_MASTER);

//drivetrain motors
pros::Motor left_front_motor (LEFT_FRONT_MOTOR, pros::E_MOTOR_GEAR_600, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor left_back_motor (LEFT_BACK_MOTOR, pros::E_MOTOR_GEAR_600, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor right_front_motor (RIGHT_FRONT_MOTOR, pros::E_MOTOR_GEAR_600, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor right_back_motor (RIGHT_BACK_MOTOR, pros::E_MOTOR_GEAR_600, false, pros::E_MOTOR_ENCODER_DEGREES);

//drivetrain motor groups
pros::MotorGroup left_side_motors({left_front_motor, left_back_motor});
pros::MotorGroup right_side_motors({right_front_motor, right_back_motor});

//sensors
pros::IMU inertial (INERTIAL_SENSOR);

//lemlib settings
lemlib::Drivetrain_t drivetrain {
  &left_side_motors,
  &right_side_motors,
  13, //TRACK WIDTH, TODO
  3.25,
  400
};

lemlib::ChassisController_t lateralPID {

};

lemlib::ChassisController_t rotationalPID {

};