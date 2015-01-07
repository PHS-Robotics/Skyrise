#ifndef liftcontrol_H_
#define liftcontrol_H_


int LiftControl(bool UpOrDown)
{
	if(isEnchoderOnLift == 1)
	{
		// TODO
	}



	if(isEnchoderOnLift == 0)
	{
		if(UpOrDown == TRUE)
		{
			// If the lift is at the top we should do nothing if told to raise the lift
			if(isLiftTop == True)
			{
				return 0;
			}

			// If the lift is at the bottom we should raise it if told to
			if(isLiftTop == False)
			{
				lift(127, 127);
				wait1msec(LiftTimeToTop);
				lift(0, 0);
				isLiftTop == TRUE
				return 0;
			}

			if(UpOrDown == FALSE)
			{
				// If the lift is not at the top then we should not lower it any more
				if(isLiftTop == FALSE)
				{
					return 0;
				}

				// If the lift is at the top than we should lower it if told to
				if(isLiftTop == TRUE)
				{
					lift(-127, -127);
					wait1msec(LiftTimeToTop);
					lift(0, 0);
					isLiftTop == FALSE
					return 0;
				}
			}
		}

		{


#endif
