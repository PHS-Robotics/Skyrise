while(1 != 0)
{
	// adding Xmtr2 to the end of a vexRT input uses the partner controler --Hopefully
	base( (vexRT(Ch2)) , (vexRT(Ch3)) );


	// Lift Control Code for the left
	if(vexRT(Btn5UXmtr2) == 1)
	{
		lift(0,127);
	}
	else if( vexRT(Btn5DXmtr2) ==1)
	{
		lift(0,-127);
	}
	else
	{
		lift(0,0);
	}


	// Lift control Code for the right
	if(vexRT(Btn6UXmtr2) == 1)
	{
		lift(127,0);
	}
	else if( vexRT(Btn6DXmtr2) ==1)
	{
		lift(-127,0);
	}
	else
	{
		lift(0,0);
	}


	//Minilift control code
	motor(minilift) = vexRT(Ch2Xmtr2);

}
