#pragma config(Sensor,in1,lightSensor,sensorReflection)
#pragma config(Motor, port4, my_servo, tmotorServoStandard, openLoop)
#pragma config(Sensor,in2,POT,sensorPotentiometer)

task main()
{
	while (true) {
		// Set servo to initial position and wait for it to get there
		motor[my_servo] = -127;
		sleep(1000);

		// Declare some variables for later
		int min = 2000;
		int minIndex = -1;
		int sensorValue;
		// loop through possible positions for light sensor
		for (int i = -127; i < 128; i+=5) {
			// set position
			motor[my_servo] = i;
			sleep(20);
			// take reading
			sensorValue = SensorValue(lightSensor);
			// adjust position of the strongest light source if needed
			if (sensorValue < min) {
				min = sensorValue;
				minIndex = i;
			}
		}
		motor[my_servo] = minIndex;
		sleep(1000);
		writeDebugStream("%d\n",SensorValue(POT));
		sleep(20000);
	}


}
