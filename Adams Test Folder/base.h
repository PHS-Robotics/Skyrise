#ifndef base_H_
#define base_H_

/*
This code allows you to control
the base motors by useing 1 function
instead of 4 funtions

USE it by base(right motor speed, left motor speed);

PS. you can only use one letter vars to exchange info from MAIN to .h files
but you can use any int var in base();
*/

int base(int r, int l){

	motor(RightT) = r;
	motor(RightB) = r;

	motor(LeftT) = l;
	motor(LeftB) = l;

	return 0;
}
#endif
