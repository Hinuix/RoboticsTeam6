#pragma config(Sensor, dgtl1,  button,         sensorTouch)
#pragma config(Motor,  port2,           shoulder,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           elbow,         tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#define SHOULDER_SPEED 100

void changeState(int state) {
	if (state == 0) {
		// STOP
		motor[elbow] = 0;
	} else if (state == 1) {
		// FORWARD
		motor[elbow] = SHOULDER_SPEED;
	} else if (state == 2) {
		// REVERSE
		motor[elbow] = -SHOULDER_SPEED;
	}
}

task main()
{
	int state = 0;

	while (true) {
		if (SensorValue(button) == 1) {
			state += 1;
			state %= 3;
			changeState(state);
			wait1Msec(200);
		}
	}

}