#pragma config(Motor,  port1,           LeftB,         tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           minilift,      tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port3,           LeftT,         tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port4,           RightB,        tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port5,           RightT,        tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port6,           LiftR1,        tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port7,           LiftR2,        tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port8,           LiftL1,        tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port9,           LiftL2,        tmotorServoContinuousRotation, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!
#include "lift.h"
#include "base.h"
/////////////////////////////////////////////////////////////////////////////////////////
//
//                          Pre-Autonomous Functions
//
// You may want to perform some actions before the competition starts. Do them in the
// following function.
//
/////////////////////////////////////////////////////////////////////////////////////////

void pre_auton()
{
	// Set bStopTasksBetweenModes to false if you want to keep user created tasks running between
	// Autonomous and Tele-Op modes. You will need to manage all user created tasks if set to false.
	bStopTasksBetweenModes = true;

	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 Autonomous Task
//
// This task is used to control your robot during the autonomous phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task autonomous()
{
	AutonomousCodePlaceholderForTesting();
	// .....................................................................................
	// Insert user code here.
	// .....................................................................................


}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 User Control Task
//
// This task is used to control your robot during the user control phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task usercontrol()
{
	// User control code here, inside the loop

	while (true)
	{
		{
			//base( (vexRT(Ch2)) , (vexRT(Ch3)) );
				base( (vexRT(Ch3)) , (vexRT(Ch2)) );


			// Lift Control Code for the left
			if(vexRT(Btn5U) == 1)

			{
				motor(LiftL1)= -127;
				motor(LiftL2)= -127;
			}
			else if(vexRT(Btn5D) == 1)

			{
				motor(LiftL1)= 127;
				motor(LiftL2)= 127;
			}
			else
			{
				lift(0,0);
			}


			// Lift control Code for the right
			if(vexRT(Btn6U) == 1)
			{
				motor(LiftR1) = 127;
				motor(LiftR2) = 127;
			}
			else if( vexRT(Btn6D) ==1)
			{
				motor(LiftR1) = -127;
				motor(LiftR2) = -127;
			}
			else
			{
				motor(LiftR1) = 0;
				motor(LiftR2) = 0;
				motor(LiftR1) = 0;
				motor(LiftR2) = 0;
			}

			//Minilift control code
			if(vexRT(Btn7U) == 1)
			{
				motor(minilift) = 127;
			}
			else if( vexRT(Btn7D) == 1)
			{
				motor(minilift) = -127;
			}
			else
			{
				motor(minilift) = 0;
			}
		}
	}
}