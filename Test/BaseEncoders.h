#ifndef baseencoders_H_
#define baseencoders_H_

#include "base.h"
// Function that clears the encoders
int ClearBaseEncoders() {
	SensorValue[RightENC] = 0;
	SensorValue[LeftENC] = 0;
	return 0;
}

int WheelSize = 13;


// Function that controls the drive base with relation to the encoders
int DriveENC(char w, int p, int d)
{

	int Power2;
	ClearBaseEncoders();

	// When the function is told to M(move) it converts distance to revolution needed to turn
	if(w == 'm' || w == 'M')
	{
		// convert distance to degrees to turn the shaft
		((d/WheelSize)*90) = d;
		// Left Power is the same as right power
		Power2 = p;
	}
	if(w == 't' || w == 'T'){
		// Left power is different than right power when we want to turn
		Power2 = -(p);
	}

	while(SensorValue[RightENC] <= d || SensorValue[LeftENC] <= d)
	{
		if(SensorValue[RightENC] <= d && SensorValue[LeftENC] <= d)
		{
			base( (p), (Power2) );
			wait1msec(75);
		}
		if( !(SensorValue[RightENC] <= d && SensorValue[LeftENC] <= d) )
		{
			break; //Goto BreakPoint1;
		}
	}
	// BreakPoint1:
	while(SensorValue[RightENC] <= d || SensorValue[LeftENC] <= d)
	{
		// if one wheel is less turns than the other this code is supposed to fix that
		if(SensorValue[RightENC] <= d)
		{
			base( (p), 0 );
			wait1msec(75);
		}
		if(SensorValue[LeftENC] <= d)
		{
			base( 0, (Power2) );
			wait1msec(75);
		}
		if( !(SensorValue[RightENC] <= d && SensorValue[LeftENC] <= d) )
		{
			break; // goto BreakPoint2;
		}
		// BreakPoint2:
		ClearBaseEncoders();
		return 0;
	}
	return 0;
}

#endif
