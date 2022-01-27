#pragma config(Sensor, dgtl1,  s_input,        sensorSONAR_cm)
#pragma config(Sensor, dgtl9,  jmpAutoReverse, sensorTouch)
#pragma config(Sensor, dgtl10, bumpLeft,       sensorTouch)
#pragma config(Sensor, dgtl11, bumpRight,      sensorTouch)
#pragma config(Sensor, dgtl12, jmpAuto,        sensorTouch)
#pragma config(Motor,  port2,           rightMotor,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           leftMotor,     tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*----------------------------------------------------------------------------------------------------*\
|*                                    - Single Joystick Control -                                     *|
|*                                      ROBOTC on VEX 2.0 Cortex                                      *|
|*                                                                                                    *|
|*  This program uses a single joystick, either right or left (this is configurable below) to drive   *|
|*  the robot.                                                                                        *|
|*                                                                                                    *|
|*                                        ROBOT CONFIGURATION                                         *|
|*    NOTES:                                                                                          *|
|*    1)  Ch1 is the X axis and Ch2 is the Y axis for the RIGHT joystick.                             *|
|*    2)  Ch3 is the Y axis and Ch4 is the X axis for the LEFT joystick.                              *|
|*                                                                                                    *|
|*    MOTORS & SENSORS:                                                                               *|
|*    [I/O Port]              [Name]              [Type]              [Description]                   *|
|*    Motor - Port 2          rightMotor          VEX Motor           Right motor                     *|
|*    Motor - Port 3          leftMotor           VEX Motor           Left motor                      *|
\*----------------------------------------------------------------------------------------------------*/

//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++
task main ()
{
//int x = 0;
//int y = 0;
	int distance;

  while(true)
  {

    while(SensorValue[jmpAuto] == 1)
    	{
    		// Get distance measurement from sensor
    		distance = SensorValue(s_input);
    		writeDebugStream("%d\n",distance);

    		// loop if closing on an object
    		while (distance < 50 && distance > -1) {
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

			if(SensorValue[bumpLeft] == 1 || SensorValue[bumpRight] == 1)
				{
				motor[leftMotor]  = -75;
	      motor[rightMotor] = -75;
	      wait1Msec(500);

	      if(SensorValue[bumpLeft] == 1)
	      	{
		    	motor[leftMotor] = -75;
		      motor[rightMotor]= 75;
		      }
	      else
	      	{
		      motor[leftMotor] = 75;
		      motor[rightMotor]= -75;
		      }

	      wait1Msec(500);
        wait1Msec(random[2000]+1);
        motor[leftMotor]  = 0;
	      motor[rightMotor] = 0;
	      wait1Msec(250);
        }

        motor[leftMotor]  = 75 + (10 - random[21] );
        motor[rightMotor] = 75;
      	wait1Msec(100);
      }

    motor[leftMotor]  = 0;
    motor[rightMotor] = 0;
    }
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
