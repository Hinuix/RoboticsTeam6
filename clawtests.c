#pragma config(Motor,  port4,           claw,          tmotorServoStandard, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	while (true) {
		motor[claw] = 0;
		wait1Msec(1000);
		motor[claw] = -127;
		wait1Msec(2000);
		motor[claw] = 65;
		wait1Msec(2000);
	}
}