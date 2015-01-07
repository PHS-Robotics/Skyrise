#ifndef lift_H_
#define lift_H_

int lift(int right, int left){

	motor(LiftR1) = right;
	motor(LiftR2) = right;

	motor(LiftL1)= left;
	motor(LiftL2)= left;

	return 0;
}
#endif
