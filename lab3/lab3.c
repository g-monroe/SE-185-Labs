// SE 185: Lab 3
// Problem 1: Mysterious Output

#include <stdio.h>

int main()
{
	int integerResult;
	double decimalResult;
	
	decimalResult = 77 / 5;
	printf("The value of 77/5 is %lf\n", decimalResult);

	integerResult = 2 + 3;
	printf("The value of 2+3 is %d\n", integerResult);

	decimalResult = 1.0 / 22.0;
	printf("The value 1.0/22.0 is %d\n", decimalResult);
	
	return 0;
}