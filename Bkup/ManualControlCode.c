#include "RoboInclude.c"

while(1 != 0)
{
	base( (vexRT(Ch2)) , (vexRT(Ch3)) );


	// Lift Control Code for the left
	if(vexRT(Btn5U) == 1)
	{
		lift(0,127);
	}
	else if( vexRT(Btn5D) ==1)
	{
		lift(0,-127);
	}
	else
	{
		lift(0,0);
	}


	// Lift control Code for the right
	if(vexRT(Btn6U) == 1)
	{
		lift(127,0);
	}
	else if( vexRT(Btn6D) ==1)
	{
		lift(-127,0);
	}
	else
	{
		lift(0,0);
	}


	//Minilift control code
	if(vexRT(Btn7U) == 1)
	{
		motor(minilift) = 127;
	}
	else if( vexRT(Btn7D) ==1)
	{
		motor(minilift) = -127;
	}
	else
	{
		lift(0,0);
	}
}
