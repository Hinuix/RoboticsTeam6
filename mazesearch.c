#pragma config(Sensor,in1,lightSensor,sensorReflection)
#pragma config(Motor, port4, myServo, tmotorServoStandard, openLoop)
#pragma config(Motor,  port2,           rightMotor,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           leftMotor,     tmotorVex393_MC29, openLoop)
#pragma config(Sensor, dgtl10, bumpLeft,       sensorTouch)
#pragma config(Sensor, dgtl11, bumpRight,      sensorTouch)
#pragma config(Sensor, dgtl1,  sonarInput,        sensorSONAR_cm)

#define ServoWaitTime 750
#define nSamples 3
#define MotorTurnTime 710
#define ForwardTurn 65
#define BackwardTurn -55
#define MotorForwardTime 700
#define MotorForwardSpeed 60
#define MotorReverseTime 700
#define MotorReverseSpeed -60

/*
 * stopMovement: sets the motion of the robot's wheels to zero
 * paramters: none
*/
void stopMovement() {
	motor[leftMotor] = motor[rightMotor] = 0;
}

/*
 * sampleDistance: samples nSamples times and returns the average reading
 * of the ultrasonic sensor
 * paramters: none
 * returns (int) avg / nSamples
*/
int sampleDistance() {
	int avg = 0;
	for (int i = 0; i < nSamples; i++) {
		avg += SensorValue(sonarInput); // Sample Sonar
	}
	return avg / nSamples;
}

/*
 * lookRight: measure the distance to the right of the robot
 * by moving the light sensor via the servo assembly to the right
 * side of the robot and calling sampleDistance() to get a reading
 * from the ultrasonic sensor
 * paramters: none
 * returns (int) distance
*/
int lookRight() {
	// Variable Declarations
	int distance;

	// Functionality
	motor[myServo] = -127;
	wait1Msec(ServoWaitTime);
	distance = sampleDistance();
	motor[myServo] = 0;
	wait1Msec(ServoWaitTime);
	return distance;
}

/*
 * lookLeft: measure the distance to the right of the robot
 * by moving the light sensor via the servo assembly to the left
 * side of the robot and calling sampleDistance() to get a reading
 * from the ultrasonic sensor
 * paramters: none
 * returns (int) distance
*/
int lookLeft() {
	// Variable Declarations
	int distance;

	// Functionality
	motor[myServo] = 127;
	wait1Msec(ServoWaitTime);
	distance = sampleDistance();
	motor[myServo] = 0;
	wait1Msec(ServoWaitTime);
	return distance;
}

/*
 * lookFoward: measures the distance forward by first looking left
 * to calibrate the forward measurement and then resamples the distance
 * and returns that value
 * paramters: none
 * returns (int) distance
*/
int lookForward() {
	// Variable Declarations
	int distance;

	// Functionality
	distance = lookLeft();
	distance = sampleDistance();
	return distance;
}

/*
 * moveForward: sets the motion of the robot to
 * the set MotorForwardSpeed constant for MotorForwardTime milliseconds
 * and then stops
 * paramters: none
*/void moveForward() {
	motor[leftMotor] = motor[rightMotor] = MotorForwardSpeed;
	wait1Msec(MotorForwardTime);
	stopMovement();
}

/*
 * turnRight: sets the motion of the left motor to the constant
 * ForwardTurn and sets the motion of the right motor to BackwardTurn
 * and then stops motion by calling stopMovement()
 * paramters: none
*/
void turnRight() {
	motor[leftMotor] = ForwardTurn;
	motor[rightMotor] = BackwardTurn;
	wait1Msec(MotorTurnTime);
	stopMovement();
}

/*
 * turnLeft: sets the motion of the right motor to the constant
 * ForwardTurn and sets the motion of the left motor to BackwardTurn
 * and then stops motion by calling stopMovement()
 * paramters: none
*/
void turnLeft() {
	motor[leftMotor] = BackwardTurn;
	motor[rightMotor] = ForwardTurn;
	wait1Msec(MotorTurnTime);
	stopMovement();
}

/*
 * moveReverse: sets the motion of the robot to
 * the set MotorReverseSpeed constant for MotorReverseTime milliseconds
 * and then stops
 * paramters: none
*/
void moveReverse() {
	motor[leftMotor] = motor[rightMotor] = MotorReverseSpeed;
	wait1Msec(MotorReverseTime);
	stopMovement();
}

task main()
{
	// Maze Search Algorithm
	while (true) {
		// Uncomment to test Calibration of ultrasonic sensor
		// and the right and left DC motors
		/*
		writeDebugStream("Right Distance: %d\n", lookRight());
		writeDebugStream("Front Distance: %d\n", lookForward());
		writeDebugStream("Left Distance: %d\n", lookLeft());
		sleep(3000);
		moveForward();
		wait1Msec(1000);
		turnLeft();
		wait1Msec(1000);
		turnRight();
		wait1Msec(1000);
		moveReverse();
		sleep(10000);
		*/
		// END CALIBRATION CODE

		// BEGIN MAZE TRAVERSAL ALGORITHM
	}
}
