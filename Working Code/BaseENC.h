int BaseENC(int t, int p1, int p2)
{
	SensorValue[RightENC] = 0;
	SensorValue[LeftENC] = 0;

	while( abs(SensorValue[RightENC]) <= abs(t) )
	{
		base(p1, p2);
		if(abs(SensorValue[LeftENC]) <= abs(t))
		{
			base(0,p2);
		}
	}
	base(0,0);
	wait1Msec(75);
	return 0;
}
