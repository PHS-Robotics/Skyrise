#pragma config(Sensor, dgtl2,  wheelr,         sensorQuadEncoder)
#pragma config(Sensor, dgtl4,  wheell,         sensorQuadEncoder)
#pragma config(Sensor, dgtl6,  ultrasonic,     sensorSONAR_cm)
#pragma config(Motor,  port2,           right1,        tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port3,           right2,        tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port4,           left1,         tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port5,           left2,         tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port6,           lift1,         tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port7,           lift2,         tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port8,           claw,          tmotorServoContinuousRotation, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!
// this is the code for the compitition robot --Adam C.

#include"RoboHeader.h"

void pre_auton()
{
	SensorValue(wheelr) = 0;
	SensorValue(wheell) = 0;
}

task autonomous()
{
	// values
	int forward = 180;
	int timetotop = 200;
	int OETurn = 180;
	int clawop = 1*10;

	while(true)
	{
		// foward
		turnbot(forward, 127, 127);

		// grab cube
		motor(claw) =127;
		wait1Msec(clawop);
		motor(claw) = 0;

		//turn 180
		turnbot(OETurn, 127, -127);

		// back
		turnbot(forward, 127, 127);

		// put cube on small post
		// turn 90*
		turnbot(90, -127, 127);
		// Put lift to top
		lift(127);
		wait1Msec(timetotop);
		// move base forward a little than stop base
		motors(127,127);
		wait1Msec(10);
		motors(0,0);
		// open claw
		motor(claw) = -127;
		wait1Msec(clawop);
		motor(claw) = 0;
		// lower lift
		lift(-127);
		wait1Msec(timetotop);
		// AutonomousCodePlaceholderForTesting();  // Remove this function call once you have "real" code.
	}
}


task usercontrol()
{
	// this is the user controled code the right joystick is the drive control
	// the left joystick (up and down) is the lift control
	// 5U and 5D are the claw control
	// -- Adam C.
	while (true)
	{
		motors(vexRT(Ch1) - vexRT[Ch2],vexRT(Ch1) + vexRT[Ch2]);
		lift(vexRT(Ch3));

		// Claw control
		if( vexRT(Btn5U) == 1 ){
			motor[claw] = 127;
		}
		else if(vexRT(Btn5D) == 1){
			motor[claw] = -127;
		}
		else if(vexRT(Btn5D) == 0 || vexRT(Btn5D) == 0){
			motor[claw] = 0;
		}
		//				UserControlCodePlaceholderForTesting(); // Remove this function call once you have "real" code.
	}
}
