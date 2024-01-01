#include "main.h"
#include "globals.h"
#include "lemlib/api.hpp"
#include "initialize.h"

int gameTime = 0;

void update_controller_screen_fn(){ //update the controller screen
	while(true){ //infinite loop
		//print drivetrain temp info
		controller.print(0, 0, "Left motor temps: %d %d %d",
			left_font_motor.get_temperature(),
			left_back_motor_bottom.get_temperature(),
			left_back_motor_top.get_temperature()
		);
		controller.print(1, 0, "Right motor temps: %d %d %d",
			right_font_motor.get_temperature(),
			right_back_motor_bottom.get_temperature(),
			right_back_motor_top.get_temperature()
		);

		//# of secs passed = num of ticks / 50, because each tick is 20 ms, and 1000 ms = 1 second
		int seconds = floor(gameTime / 50);
		//# of mins passed = num of seconds / 60, because 60 seconds = 1 minute
    int mins = floor(seconds / 60);
		//if 1:35 minutes has passed, rumble controller
    if(seconds == 95) controller.rumble("..");
		//set seconds to the remainder
		seconds = seconds - (mins*60);
		//print game time
		controller.print(2, 0, "Game Time: %d:%d", mins, seconds);
		//delay task
		pros::delay(250);
	}
}

void opcontrol() {
	pros::Task update_controller_screen (update_controller_screen); //create task to update controller screen
	while (true) {
		int throttle = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
		int turn = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
		chassis.curvature(throttle, turn, 1);


		if(pros::competition::is_connected() && !pros::competition::is_autonomous()){
			gameTime++;
		}
		pros::delay(20);
	}
}
