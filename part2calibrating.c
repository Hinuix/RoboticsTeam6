+
#pragma config(Sensor,in1,lightSensor,sensorReflection)
#pragma config(Motor, port4, my_servo, tmotorServoStandard, openLoop)
#pragma config(Sensor,in2,POT,sensorPotentiometer)

task main()
{
	while (true) {
		// Set servo to initial position and wait for it to get there
		motor[my_servo] = 50;
		sleep(500);
		writeDebugStream("%d\n",SensorValue(POT));
		sleep(100000);
	}
}
