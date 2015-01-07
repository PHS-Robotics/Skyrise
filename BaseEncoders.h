#ifndef baseencoders_H_
#define baseencoders_H_


// Function that clears the encoders
int ClearBaseEncoders() {
	SensorValue[RightENC] = 0;
	SensorValue[LeftENC] = 0;
	return 0;
}




// Function that controls the drive base with relation to the encoders
int DriveENC(char WhatToDo, int Power, int DistOrAng){

	int Power2;
	ClearBaseEncoders();

	// When the function is told to M(move) it converts distance to revolution needed to turn
	if(WhatToDo == m || WhatToDo == M)
	{
		// convert distance to degrees to turn the shaft
		((DistOrAngle/WheelSize)*90)= DistOrAngle;
		// Left Power is the same as right power
		Power2 = Power;
	}
	If(WhatToDo == t || WhatToDo == T){
		// Left power is different than right power when we want to turn
		Power2 = -(Power);
	}

	while(SensorValue[RightEnc] <= DisOrAng || SensorValue[LeftENC] <= DistOrAngle)
	{
		if(SensorValue[RightEnc] <= DisOrAng && SensorValue[LeftENC] <= DistOrAngle)
		{
			base( (Power), (Power2) );
			wait1msec(75);
		}
		if( !(SensorValue[RightEnc] <= DisOrAng && SensorValue[LeftENC] <= DistOrAngle) )
		{
			break;
		}
	}
	while(SensorValue[RightEnc] <= DisOrAng || SensorValue[LeftENC] <= DistOrAngle)
	{
		// if one wheel is less turns than the other this code is supposed to fix that
		if(SensorValue[RightEnc] <= DisOrAng)
		{
			base( (Power), 0 );
			wait1msec(75);
		}
		if(SensorValue[LeftENC] <= DistOrAngle)
		{
			base( 0, (Power2) );
			wait1msec(75);
		}
		if( !(SensorValue[RightEnc] <= DisOrAng && SensorValue[LeftENC] <= DistOrAngle) )
		{
			break;
		}
		ClearBaseEncoders();
		return 0;

	}

#endif
