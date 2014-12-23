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
	bStopTasksBetweenModes = true;
}

task autonomous()
{
	motors(127,127);
wait1msec(2000);
motors(0,0);
}

task usercontrol()
{
	// this is the user controled code the right joystick is the drive control
	// the left joystick (up and down) is the lift control
	// 5U and 5D are the claw comotor
	// -- Adam C.
	while (true)
	{
		//	motors(	(vexRT(Ch1) + vexRT[Ch2]) , (vexRT(Ch1) - vexRT[Ch2]));

		motors((vexRT(Ch2)),(vexRT(Ch3)));
		/*
		motor(right1) = -vexRT(Ch2);
		motor(right2) = vexRT(Ch2);
		motor(left1) = -vexRT(Ch3);
		motor(left2) = vexRT(Ch3);
		*/

		if( vexRT(Btn5U) == 1 ){
			motor[claw] = 127;
		}
		else if(vexRT(Btn5D) == 1){
			motor[claw] = -127;
		}
		else {
			motor[claw] = 0;
		}


		if( vexRT(Btn7U) == 1 ){
			motor[lift2] = 127;
		}
		else if(vexRT(Btn7D) == 1){
			motor[lift2] = -127;
		}
		else {
			motor[lift2] = 0;
		}


		if( vexRT(Btn8U) == 1 ){
			motor[lift1] = 127;
		}
		else if(vexRT(Btn8D) == 1){
			motor[lift1] = -127;
		}
		else {
			motor[lift1] = 0;
		}
	}
}
