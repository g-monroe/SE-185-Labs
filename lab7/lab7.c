// SE 185 lab7.c
//
// This is the outline for your program
// Please implement the functions given by the prototypes below and
// complete the main function to make the program complete.
// You must implement the functions which are prototyped below exactly
//  as they are requested.

#include <stdio.h>
#include <math.h>
#include <string.h>
#define PI 3.141592653589

//NO GLOBAL VARIABLES ALLOWED


//PRE: Arguments must point to double variables or int variables as appropriate
//This function scans a line of DS4 data, and returns
//  True when left button is pressed
//  False Otherwise
//POST: it modifies its arguments to return values read from the input line.
int read_line(double* g_x, double* g_y, double* g_z, int* time, int* Button_T, int* Button_X, int* Button_S, int* Button_C);

// PRE: -1.0 <= x_mag <= 1.0
// This function computes the roll of the DS4 in radians
// if x_mag outside of -1 to 1, treat it as if it were 1 or -1
// POST: -PI/2 <= return value <= PI/2
double roll(double x_mag);

// PRE: -1.0 <= y_mag <= 1.0
// This function computes the pitch of the DS4 in radians
// if y_mag outside of -1 to 1, treat it as if it were 1 or -1
// POST: -PI/2 <= return value <= PI/2
double pitch(double y_mag);


// PRE: -PI/2 <= rad <= PI/2
// This function scales the roll value to fit on the screen
// POST: -39 <= return value <= 39
int scaleRadsForScreen(double rad);

// PRE: num >= 0
// This function prints the character use to the screen num times
// This function is the ONLY place printf is allowed to be used
// POST: nothing is returned, but use has been printed num times
void print_chars(int num, char use);
double scaleRadsForScreenJoy(double rad);
int main()
{
	
	double x, y, z, j1, j2, j3, j4;			// magnitude values of x, y, and z
	int b_Up, b_Down, b_Left, b_Right, t;	// variables to hold the button statuses
	double roll_rad, pitch_rad;		// value of the roll measured in radians
	int scaled_value; 	// value of the roll adjusted to fit screen display
	int toggle = 0;
	//insert any beginning needed code here

	do
	{
		fflush(stdout);
		// Get line of input
		scanf("%d, %lf, %lf, %lf, %d, %d, %d, %d, %d, %d, %d, %d", &t, &x, &y, &z, &b_Up, &b_Right, &b_Down, &b_Left, &j1, &j2, &j3, &j4);//Grab Input
		//printf("%lf\n", joy);//Grab Input
		// calculate roll and pitch.  Use the buttons to set the condition for roll and pitch
		roll_rad = roll(j1);
		pitch_rad = pitch(j2);
		
		// switch between roll and pitch(up vs. down button)
		if (b_Up == 1){
			toggle = 0;
		}else if(b_Down == 1){
			toggle = 1;
		}
		fflush(stdout);
		// Output your graph line
		if (toggle == 0){
			scaled_value = scaleRadsForScreenJoy(roll_rad);
		}else{
			scaled_value = scaleRadsForScreenJoy(pitch_rad);
		}
		printf("%d\n", scaled_value);
		if (scaled_value < 0){
			scaled_value = scaled_value * -1;
			int i;
			for(i=0; i<=39; i++){
				printf(" "); 
			}
			print_chars(scaled_value, 'r');
		}else if (scaled_value == 0){
			int i;
			for(i=0; i<=39; i++){
				printf(" "); 
			}
			//printf("0\n");
		}else{
			int i;
			for(i=0; i<=40 - scaled_value; i++){
				printf(" "); 
			}
			print_chars(scaled_value, 'l');
		}
		fflush(stdout);
		
	} while (read_line(&x, &y, &z, &t, &b_Up, &b_Down, &b_Left, &b_Right) == 0); // Modify to stop when left button is pressed
	return 0;
}
int read_line(double* g_x, double* g_y, double* g_z, int* time, int* Button_T, int* Button_X, int* Button_S, int* Button_C){

	if (*Button_S == 1){
		return 1;
	}else{
		return 0;
	}
}

double roll(double x_mag){
	if (x_mag > 1){
		x_mag = 1;
	}else if(x_mag < -1.0){
		x_mag = -1.0;
	}
	return asin(x_mag);
}
double pitch(double y_mag){
	if (y_mag > 1){
		y_mag = 1;
	}else if(y_mag < -1.0){
		y_mag = -1.0;
	}
	return asin(y_mag);
}
int scaleRadsForScreen(double rad){
	int num = 78/PI;
	if (rad >= -PI/2 && rad <= PI/2){
		num = num*rad;
	}
	return num;
}
double scaleRadsForScreenJoy(double rad){
	
	
	double numb = 39;
	numb = numb / 130;
	//if (rad >= -PI/2 && rad <= PI/2){
		numb = numb *rad;
	//}
	return numb;
}
void print_chars(int num, char use){
	int i;
	if (num > 39){
		for(i=0; i<=39; i++){
			printf("%c", use);
		}
	}else{
		for(i=0; i<=num; i++){
			printf("%c", use);
		}
	}
	printf("\n");
}