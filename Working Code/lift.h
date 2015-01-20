#ifndef lift_H_
#define lift_H_

/*
This code allows you to control
the lift motors by useing 1 function
instead of 4 funtions

USE it by lift(right motor speeds, left motor speeds);

PS. you can only use one letter vars to exchange info from MAIN to .h files
but you can use any int var in lift();
*/

int lift(int r, int l){

	motor(right) = right;
	motor(left)= left;
	wait1Msec(50*10);
}
#endif
