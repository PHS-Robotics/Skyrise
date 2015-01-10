#ifndef base_H_
#define base_H_

int base(int r, int l){

	motor(RightT) = r;
	motor(RightB) = r;

	motor(LeftT) = l;
	motor(LeftB) = l;

	return 0;
}
#endif
