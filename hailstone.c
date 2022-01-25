
/*
 * hailstone returns an int n/2 if n is even
 * and return 3*n + 1 if n is odd
 */
int hailstone(int n){
	if (n % 2 == 0) {
		return n/2;
	}
	return 3*n + 1;
}

/*
 * main is a tester function for hailstone program
 * to show the function works
 */
task main()
{
	int n = 7;
	while (n != 1){
		writeDebugStream("%d\n",n);
		n = hailstone(n);
	}
	writeDebugStream("%d\n",n);
}
