#ifndef ROBOLIB_H_
#define ROBOLIB_H_

// h file

// this is the forward
int forward(float x)
{
	for(;x > 0; x = x - 1)
	{
		float delay;
		delay = 65;
		motor[right] = 100;
		motor[left] = 100;
		wait10Msec(delay);
	}
	return 0;
}
// end forward

// this is the backwards

int backwards(float x)
{
	for(;x > 0; x = x - 1)
	{
		float delay;
		delay = 65;
		motor[right] = -100;
		motor[left] = -100;
		wait10Msec(delay);
	}
	return 0;
}
// end backwards

// this is the turn
int turn( char t , float x )
{
	for(;x > 0; x = x - 1)
	{
		// this is the right turn
		if( t == 'r' )
		{
			float delay;
			delay = 65;
			motor[right] = -100;
			motor[left] = 100;
			wait10Msec(delay);
		}
		// this is the left turn
		else if( t == 'l')
		{
			float delay;
			delay = 65;
			motor[right] = 100;
			motor[left] = -100;
			wait10Msec(delay);
		}
		else
		{
		}
	}
	return 0;
}

#endif /* ROBOLIB_H_ */
