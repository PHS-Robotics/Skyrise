#pragma config(Sensor, dgtl7,  rightenc,       sensorQuadEncoder)
#pragma config(Sensor, dgtl9,  leftenc,        sensorQuadEncoder)
#pragma config(Sensor, dgtl11, sonar,          sensorSONAR_cm)
#pragma config(Motor,  port2,           right,         tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port3,           left,          tmotorServoContinuousRotation, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	int A=0;

	while(true){
		motor(right) = 127;
		motor(left) = 127;
		wait1Msec(75);

		if(SensorValue[sonar] <= 50){
			A = 1;
		}
		while(A == 1){

			SensorValue[rightenc] = 0;
			SensorValue[leftenc]  = 0;

			if(SensorValue[rightenc] < 1080){
				motor(right) = 127;
				wait1Msec(75);
			}

			if(SensorValue[leftenc] < 1080){
				motor(left) = -127;
				wait1Msec(75);
			}

			if(SensorValue[sonar] > 50)
			{
				A = 0;
			}
			motor(left && right) = 0;
		}
	}
}
