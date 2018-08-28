/* SE 185 Lab 5 Wrapper Program */

#include <stdio.h>
#include <math.h>

#define TRUE 1

/* Put your lab 4 functions prototypes here, as well as the prototype for lab 5 */
double mag(double x2, double y2, double z2);
void findDirection(double gxInput, double gyInput, double gzInput, double tole);
void outputDirection(int oldd, int neww);
int d;
int d2;
int main(void) {
	int t, b1, b2, b3, b4;
	double ax, ay, az, gx, gy, gz; 	
	printf("%d %d",d,d2);
	while (TRUE) {
		fflush(stdout);//Flush Code
		scanf("%d, %lf, %lf, %lf, %lf, %lf, %lf, %d, %d, %d, %d", &t, &ax, &ay, &az, &gx, &gy, &gz, &b1, &b2, &b3, &b4 );//Grab Input
	    d2=d;//set old orientation.
		findDirection(gx, gy, gz, 0);//Find Direction which the controller is facing.
		outputDirection(d2, d);//Output Result.
		if (b1!=0){//Close when Triangle is pressed
			return 0;
		}
	}


    return 0;
}

double mag(double x2, double y2, double z2){
	/* 	CODE SECTION 1 */ 
	double sqrtX = pow(x2, 2);
	double sqrtY = pow(y2, 2);
	double sqrtZ = pow(z2, 2);
	return sqrt(sqrtX + sqrtY + sqrtZ);
}
void findDirection(double gxInput, double gyInput, double gzInput, double tole){
	if (gxInput >= 0.014300 && gxInput <= 0.20600){//Top
		if (gyInput >= 0.973900 && gyInput <= 0.995640){
			if (gzInput >= 0.193300 && gzInput <= 0.206687){
				d=1;
			}
		}
	}
	if (gxInput >= 0.014300 && gxInput <= 0.17600){//Bottom
		if (gyInput <= -0.700000 && gyInput >= -0.723900){
			if (gzInput <= -0.720000 && gzInput >= -0.730000){
				d=2;
			}
		}
	}
	if (gxInput >= 0.962000 && gxInput <= 0.99800){//Left
		if (gyInput >= -0.340100 && gyInput <= 0.040500){
			if (gzInput >= 0.221000 && gzInput <= 0.268000){
				d=3;
			}
		}
	}
	if (gxInput <= -0.902000 && gxInput >= -0.99800){//Right
		if (gyInput <= -0.000277 && gyInput >= -0.158900){
			if (gzInput >= 0.21000 && gzInput <= 0.368000){
				d=4;
			}
		}
	}
}
void outputDirection(int oldd, int neww){
	if (oldd!=neww){
		if (neww==1){
			printf("TOP\n");
		}
		if(neww==2){
			printf("BOTTOM\n");
		}
		if(neww==3){
			printf("LEFT\n");
		}
		if(neww==4){
			printf("RIGHT\n");
		}
	}
}

	