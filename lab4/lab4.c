/* SE 185 Lab 4 Wrapper Program */

#include <stdio.h>
#include <math.h>

#define TRUE 1

/* Put your function prototypes here */
double mag(double x2, double y2, double z2);
int minutes(int t);
int seconds(int t);
int millis(int t);
int main(void) {
    /* DO NOT MODIFY THESE VARIABLE DECLARATIONS */
	int t;
	double  ax, ay, az; 
	while (TRUE) {
		scanf("%d,%lf,%lf,%lf", &t, &ax, &ay, &az);	

/* CODE SECTION 0
		printf("Echoing output: %8.3lf, %7.4lf, %7.4lf, %7.4lf\n", (double)t / 1000, ax, ay, az); */

/* 	CODE SECTION 1 
		printf("At %d ms, the acceleration's magnitude was: %lf\n", 
			t, mag(ax, ay, az)); */ 
/* 	CODE SECTION 2*/
		printf("At %d minutes, %d seconds, and %d milliseconds it was: %lf\n", 
		minutes(t), seconds(t), millis(t), mag(ax,ay,az)); 

	}

return 0;
}

/* Put your functions here */
double mag(double x2, double y2, double z2){
	/* 	CODE SECTION 1 */ 
	double sqrtX = pow(x2, 2);
	double sqrtY = pow(y2, 2);
	double sqrtZ = pow(z2, 2);
	return sqrt(sqrtX + sqrtY + sqrtZ);
}
int minutes(int t){
	t = (int) t / 1000;
	t = (int) t / 60;
	return (int) t;
}
int seconds(int t){
	t = (int) t / 1000;
	int mt = (int) t / 60;
	if (t > 60){
		t = (int) t - (mt * 60);
	}
	return (int) t;
}
int millis(int t){
	int st = (int) t / 1000;
	if (t > 1000){
		t = (int) t - (st * 1000);
	}
	return t;
}
	