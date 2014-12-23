#pragma config(Motor,  port2,           RightT,        tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port3,           RightB,        tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port4,           LeftT,         tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port5,           LeftB,         tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port6,           LiftR1,        tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port7,           LiftR2,        tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port8,           LiftL1,        tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port9,           LiftL2,        tmotorServoContinuousRotation, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "RoboInclude.h"
task main()
{
	while(1 != 0)
	{

		base( (vexRT(Ch2)) , (vexRT(Ch3)) );

		if(vexRT(Btn5U) == 1)
		{
			lift(127,127);
		}
		else if( vexRT(Btn5D) ==1)
		{
			lift(-127,-127);
		}
		else
		{
			lift(0,0);
		}
	}
}
