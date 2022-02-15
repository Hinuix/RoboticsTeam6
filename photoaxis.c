#pragma config(Sensor,in1,lightSensor,sensorReflection)
#pragma config(Motor, port4, my_servo, tmotorServoStandard, openLoop)
#pragma config(Sensor,in2,POT,sensorPotentiometer)
#pragma config(Motor,  port2,           rightMotor,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           leftMotor,     tmotorVex393_MC29, openLoop)
#pragma config(Sensor, dgtl10, bumpLeft,       sensorTouch)
#pragma config(Sensor, dgtl11, bumpRight,      sensorTouch)
#pragma config(Sensor, dgtl1,  s_input,        sensorSONAR_cm)

int findLight() {
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
	writeDebugStream("Min Light Value: %d | Min Index: %d\n",min,minIndex);
	if (min < 300) {
		return minIndex;
	} else {
		return NULL;
	}
}

task main()
{
	int distance;
	int lightPosition;
	//writeDebugStream("%d\n",findLight());
	while (true) {
			motor[leftMotor] = motor[rightMotor] = 0;
			lightPosition = findLight();
			if (lightPosition != NULL) {
				//turn towards light
				if (lightPosition < 0) {
					// negative / turn right
				  motor[leftMotor]  = 75;
	    		motor[rightMotor] = -75;
				} else {
					// positive / turn left
				  motor[leftMotor]  = -75;
	    		motor[rightMotor] = 75;
				}
				sleep(abs(lightPosition)*2);
				motor[leftMotor] = motor[rightMotor] = 0;
				sleep(500);
				motor[leftMotor]  = 75;
	    	motor[rightMotor] = 75;
				sleep(700);
				motor[leftMotor] = motor[rightMotor] = 0;
			} else {
				// wander
				// Get distance measurement from sensor
    		distance = SensorValue(s_input);
    		writeDebugStream("%d\n",distance);

    		// loop if closing on an object
    		while (distance < 75 && distance > -1) {
    			// backward motion
    			motor[leftMotor]  = -75;
	    		motor[rightMotor] = -75;
    			wait1Msec(200);
    			// turn left
    			motor[leftMotor]  = -75;
	    		motor[rightMotor] = 75;
	    		wait1Msec(200);
	    		// resample the distance value
	    		distance = SensorValue(s_input);
    		}

				if(SensorValue[bumpLeft] == 1 || SensorValue[bumpRight] == 1) {
					motor[leftMotor]  = -75;
	      	motor[rightMotor] = -75;
	      	wait1Msec(500);

	      	if(SensorValue[bumpLeft] == 1) {
		   		 	motor[leftMotor] = -75;
		     	 	motor[rightMotor]= 75;
		    	} else {
		     	 	motor[leftMotor] = 75;
		      	motor[rightMotor]= -75;
		    	}

	      	wait1Msec(500);
        	wait1Msec(random[2000]+1);
        	motor[leftMotor]  = 0;
	      	motor[rightMotor] = 0;
	      	wait1Msec(275);
    		}

    		motor[leftMotor]  = 75 + (10 - random[21] );
    		motor[rightMotor] = 75;
    		wait1Msec(400);
			}
	}
	/*
  while(true) {
	}
	*/
}
