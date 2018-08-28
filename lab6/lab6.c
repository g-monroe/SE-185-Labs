/* SE 185 Lab 5 Wrapper Program 
Gavin Monroe
Fletcher Smith
*/

#include <stdio.h>
#include <math.h>

#define TRUE 1

/* Put your lab 4 functions prototypes here, as well as the prototype for lab 5 */
double mag(double x2, double y2, double z2);
void findFall(double ayInput);
void outputInfo(int oldd, int neww, double tm, double aTime);
void calcTime(int tm, int on);
void calcDistance(int tm, int on);

//Detect Change Vars
int d;
int d2;

//Distance & Time
double dist;
double dist2;
int start = 0;
int beforeTime;
double afterTime;

int main(void) {
	int t;
	double ax, ay, az; 	
	while (TRUE) {
		fflush(stdout);//Flush Code
		scanf("%d, %lf, %lf, %lf", &t, &ax, &ay, &az );//Grab Input
    
		d2=d;//set old orientation.
    
    findFall(mag(ax, ay, az));//Find Direction which the controller is facing.
		outputInfo(d2, d, t, afterTime);//Output Result.
    calcTime(t, d);//Output dots
    calcDistance(t, d);//Get Distance
    
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
void calcTime(int tm, int on){
	int varTime = tm % 100;
  if (varTime == 0 && on == 1){
      printf(".");
  }
  if (varTime == 0 && on == 2){
      printf("!");
  }
}
void calcDistance(int tm, int on){
  if (on == 2){
  	double sec = tm - beforeTime;
  	sec = sec / 1000;
  	afterTime = sec;
  	double v = 9.8;
    dist = v * sec;
	dist2 = 0.5 * (v * pow(sec, 2));
  }
}
void findFall(double ayInput){
  if (ayInput != 0 && start == 0){
    start = 1;
    d = 1;
  }
  if (ayInput  >= 0.5 && start == 1 && d==1){
    d = 2;
  }
  if (ayInput  < 0.5 && start == 1 && d == 2){
    d = 3;
  }
}
void outputInfo(int oldd, int neww, double tm, double aTime){
	if (oldd!=neww){
		if (neww==1){
			printf("Ok, I'm now receiving data.\nI'm Waiting");
		}
		if(neww==2){
			beforeTime = tm;
			printf("");
		}
		if(neww==3){
			double dist3 = (dist + dist2) / 2;
			int perc = ((dist2 - dist) / dist3) * 100;
			printf("\nCompensating for air resistance, the fall was %3.3lf meters.\nThis is %d%% less than computed before.", dist, perc);
		}
		if(neww==4){
			printf("RIGHT\n");
		}
	}
}
	