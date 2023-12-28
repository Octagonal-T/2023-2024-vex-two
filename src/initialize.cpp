#include "main.h"
#include "globals.h"

void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, "Hello PROS User!");

}

void disabled() {}

void competition_initialize() {}