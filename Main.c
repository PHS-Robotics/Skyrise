#include "RoboInclude.c"

// Fuses
bool isEnchoderOnLift = !(TRUE);
int LiftMotorRevsToTop = 360*5;
int LiftTimeToTop = 50;
int WheelSize = 5;
bool isLiftTop = FALSE;
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

		// TODO add code for lift top and lift bottom and also add code for cube claw lift
	}
}
