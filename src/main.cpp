#include "main.h"
#include "globals.h"
#include "lemlib/api.hpp"
#include "initialize.h"

int gameTime = 0;

void update_controller_screen(){
	controller.print(0, 0, "Left motor temps: %d %d %d", left_font_motor.get_temperature(), left_back_motor_bottom.get_temperature(), left_back_motor_top.get_temperature());
}

void opcontrol() {
	while (true) {
		
	}
}
