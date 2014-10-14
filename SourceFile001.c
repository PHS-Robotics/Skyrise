#pragma config(Sensor, dgtl7,  rightenc,       sensorQuadEncoder)
#pragma config(Sensor, dgtl9,  leftenc,        sensorQuadEncoder)
#pragma config(Sensor, dgtl11, sonar,          sensorSONAR_cm)
#pragma config(Motor,  port2,           right,         tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port3,           left,          tmotorServoContinuousRotation, openLoop)

task main()
{
	while(true){
		motor(right) = 127;
		motor(left) = 127;

		if(SensorValue[sonar] <= 25){
			break;
		}
	}


}
