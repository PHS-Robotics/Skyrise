#pragma config(Sensor, dgtl2,  wheell,         sensorQuadEncoder)
#pragma config(Sensor, dgtl4,  wheelr,         sensorQuadEncoder)
#pragma config(Sensor, dgtl6,  ultrasonic,     sensorSONAR_cm)
#pragma config(Motor,  port2,           right1,        tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port3,           right2,        tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port4,           left1,         tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port5,           left2,         tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port6,           lift1,         tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port7,           lift2,         tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port8,           claw,          tmotorServoContinuousRotation, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//
#include"RoboHeader.h"


task main()
{
	// values
	int exelock = 0;
	int forward = 360*1;
	int timetotop = 200;
	int OETurn = 360*2;
	int clawop = 1*10;

	while(true)
	{
		// foward
		exelock = 1;
		turnbot(forward, 127, 127);

		while(exelock == 1)
		{
			wait1Msec(200);
		}

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