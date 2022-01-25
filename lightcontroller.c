#pragma config(Motor,  port2,           rightMotor,    tmotorVex393, openLoop)
#pragma config(Motor,  port3,           leftMotor,     tmotorVex393, openLoop)
#pragma config(Sensor,in1,lightSensor,sensorReflection)

/*
 * main program checks the light sensor for values
 * and converts the value so that lots of light = lots of speed
 * and less light = less speed
 */
task main ()
{
	int sensor_value;
	int adjusted_sensor_value,motorspeed;
	sensor_value = SensorValue(lightSensor);
	//writeDebugStream("%d\n",sensor_value);

	while (true) {
		sensor_value = SensorValue(lightSensor);
		// invert sensor value to be scaled from -1000 to 1000 where -1000 is dark and 1000 is light
		adjusted_sensor_value = -sensor_value + 1000;
		// set a floor for reoriented, throwing out values less than 0
		if (adjusted_sensor_value < 0) {
				adjusted_sensor_value = 0;
		}
		// use fraction of adjusted value to map to 0-127 motor range
		motorspeed = (float)adjusted_sensor_value/1000.0 * 127;
		writeDebugStream("%d\n",motorspeed);
		motor[leftMotor]  = motorspeed;
    motor[rightMotor] = motorspeed;
	}

}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
