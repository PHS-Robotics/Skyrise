#include "RoboInclude.c"

// Fuses
bool isEnchoderOnLift = !(TRUE);
int LiftMotorRevsToTop = 360*5;
int LiftTimeToTop = 50;
int WheelSize = 5;
bool isLiftTop = FALSE;


// Not a Fuse
bool isAutoEnabled == FALSE;

task main()
{
	// Turn me into a compitition template!!!!!!
	while(1 != 0)
	{
		if(isAUtoEnabled == FALSE)
		{
			#include "ManualControlCode.c"
			// #include"ManualControlCodeBETA.c"
		}
		if(isAutoEnabled == TRUE)
		{
			#include "AutoCode.c"
		}
	}
}
