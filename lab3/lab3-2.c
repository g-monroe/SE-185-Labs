// SE 185: Lab 3
// Problem 2: Simple Arithmetic

#include <stdio.h>

int main()
{
	int a = (6427 + 1725);
	int b = (6971 * 3925) - 95;
	double c = 79 + 12 / 5;
	double d = 3640.0 / 107.9;
	int e = (22 / 3) * 3;
	int f = 22 / (3 * 3);
	double g = 22 / (3 * 3);
	double h = 22 /  3* 3;
	double i = (22.0 / 3) * 3.0;
	int j = 22.0 / (3 * 3.0);
	double k = 22.0 / 3.0 * 3.0;
	double l = (23.567 * 23.567) / (4 * 3.14159);
	double m = (3.28084 * 14);
	double n = (76 - 32) * .5556;
	printf(" a:%d\n b:%d\n c:%.2f\n d:%.2f\n e:%d\n f:%d\n g:%.2f\n h:%.2f\n i:%.2f\n j:%d\n k:%.2f\n l:%.2f\n m:%.2f\n n:%.2f\n", a, b, c, d, e, f, g, h, i, j, k, l, m, n);
	
	return 0;
}