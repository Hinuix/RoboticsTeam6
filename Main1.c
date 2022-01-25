/**************************************************************************
*           MAIN1
*  Pauses for 2 seconds then prints 'Hello World' to the debug stream
*  to display the debug stream:
*      -download the program to the cortex
*      -in the Robot menu select debugger
*      -go back to Robot; then go to the debugger window and select debug stream
*
***************************************************************************/


task main()
{
	wait1Msec(2000);
	writeDebugStream("Hello World");

}
