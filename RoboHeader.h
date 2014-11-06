#ifndef RoboHeader_H
#define RoboHeader_H


//motor function motors(right value, left value);
int motors(int valuer, int valuel)
{
	motor(right1) = -valuer;
	motor(right2) = valuer;
	motor(left1) = -valuel;
	motor(left2) = valuel;
	return 0;
}

//lift auto lift lift(power);
int lift(int power)
{
	motor(lift1) = power;
	motor(lift2) = -power;
	return 0;
}

// turn the robot turn(angle, right power, left power);
int turnbot(int angle, int rightp, int leftp)
{
	SensorValue(wheelr) = 0;
	SensorValue(wheell) = 0;
	int update = 0;
	for(; update == 0;)
	{

		if(SensorValue(wheelr) > angle)
		{
			motors(rightp, 0);
			wait1Msec(50);
		}

		if(SensorValue(wheell) > angle)
		{
			motors(0, leftp);
			wait1Msec(50);
		}

		if(SensorValue(wheelr) > angle && SensorValue(wheell) > angle)
		{
			update = 1;
		}
	}
	motors(0,0);
	return 0;
}

#endif /* RoboHeader_H */`
