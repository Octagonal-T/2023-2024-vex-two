//include files
#include "main.h"
#include "globals.h"
#include "lemlib/api.hpp"

//global port definitions
//CHANGE THESE NUMBERS TO ITS CORRESPONDING SUBSYSTEM
#define LEFT_FRONT_MOTOR 1
#define LEFT_BACK_MOTOR_BOTTOM 2
#define LEFT_BACK_MOTOR_TOP 3
#define RIGHT_FRONT_MOTOR 4
#define RIGHT_BACK_MOTOR_BOTTOM 5
#define RIGHT_BACK_MOTOR_TOP 6

#define INTAKE 7
#define SLAPPER 8

#define INTAKE_DISTANCE 19
#define INERTIAL_SENSOR 20

#define ENCODER_HORIZONTAL_ONE 1
#define ENCODER_HORIZONTAL_TWO 2

//controller
pros::Controller controller (pros::E_CONTROLLER_MASTER);

//drivetrain motors
pros::Motor left_front_motor (LEFT_FRONT_MOTOR, pros::E_MOTOR_GEAR_600, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor left_back_motor_bottom (LEFT_BACK_MOTOR_BOTTOM, pros::E_MOTOR_GEAR_600, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor left_back_motor_top (LEFT_BACK_MOTOR_TOP, pros::E_MOTOR_GEAR_600, false, pros::E_MOTOR_ENCODER_DEGREES);

pros::Motor right_front_motor (RIGHT_FRONT_MOTOR, pros::E_MOTOR_GEAR_600, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor right_back_motor_bottom (RIGHT_BACK_MOTOR_BOTTOM, pros::E_MOTOR_GEAR_600, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor right_back_motor_top (RIGHT_BACK_MOTOR_TOP, pros::E_MOTOR_GEAR_600, false, pros::E_MOTOR_ENCODER_DEGREES);


//drivetrain motor groups
pros::MotorGroup left_side_motors({left_front_motor, left_back_motor_bottom, left_back_motor_top});
pros::MotorGroup right_side_motors({right_front_motor, right_back_motor_bottom, right_back_motor_top});

//motors

pros::Motor intake (INTAKE, pros::E_MOTOR_GEAR_600, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor slapper (SLAPPER, pros::E_MOTOR_GEAR_100, false, pros::E_MOTOR_ENCODER_DEGREES);

//sensors
pros::IMU inertial (INERTIAL_SENSOR);
pros::Distance intake_distance (INTAKE_DISTANCE);
pros::ADIEncoder horizontal_encoder (ENCODER_HORIZONTAL_ONE, ENCODER_HORIZONTAL_TWO);

//lemlib settings
lemlib::TrackingWheel left_side_trackingwheel (&left_side_motors, 3.25, 6.5, 400);
lemlib::TrackingWheel right_side_trackingwheel (&right_side_motors, 3.25, 6.5, 400);
lemlib::TrackingWheel horizontal_trackingwheel (&horizontal_encoder, 2.75, 0, 1); //DISTANCE TO DO

lemlib::OdomSensors sensors (&left_side_trackingwheel, &right_side_trackingwheel, &horizontal_trackingwheel, nullptr, &inertial);

lemlib::Drivetrain drivetrain (&left_side_motors, &right_side_motors, 13, 3.25, 400, 0); //track width and chase power to do


lemlib::ControllerSettings lateralPID (
  0.1,
  0.1,
  0.1,
  2,
  1,
  1,
  1,
  1,
  1
);

lemlib::ControllerSettings rotationalPID (
  0.1,
  0.1,
  0.1,
  2,
  1,
  1,
  1,
  1,
  1
);

lemlib::Chassis chassis (drivetrain, lateralPID, rotationalPID, sensors);