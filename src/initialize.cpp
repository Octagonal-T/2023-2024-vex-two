#include "main.h"
#include "globals.h"
#include "lemlib/api.hpp"

  
void initialize() {
  pros::lcd::initialize();
  chassis.calibrate();
}

void disabled() {

}

void competition_initialize() {
	
}