/* SE 185 Lab 4 Wrapper Program */

#include <stdio.h>
#include <math.h>

#define TRUE 1

/* Put your function prototypes here */
int main(void){
    /* DO NOT MODIFY THESE VARIABLE DECLARATIONS */
	int a1, a2, a3, a4; 
	int counti = 0;
	while (TRUE) {
		scanf("%d,%d,%d,%d", &a1, &a2, &a3, &a4);
		if (a1 == 1){
			counti += 1;
		}
		if (a2 == 1){
			counti += 1;
		}
		if (a3 == 1){
			counti += 1;
		}
		if (a4 == 1){
			counti += 1;
		}
		printf("Being pressed:%d\n", counti);
		counti = 0;
		fflush(stdout); 
/* CODE SECTION 0
		printf("Echoing output: %8.3lf, %7.4lf, %7.4lf, %7.4lf\n", (double)t / 1000, ax, ay, az); */

/* 	CODE SECTION 1 
		printf("At %d ms, the acceleration's magnitude was: %lf\n", 
			t, mag(ax, ay, az)); */ 
/* 	CODE SECTION 2
		printf("At %d minutes, %d seconds, and %d milliseconds it was: %lf\n", 
		minutes(t), seconds(t), millis(t), mag(ax,ay,az)); */

	}

return 0;
}

/* Put your functions here */

	