
// SE 185 Lab 8
#include <stdio.h>


#define MAXPOINTS 10000

// compute the average of the first num_items of buffer
double avg(double buffer[], int num_items);

//update the max and min of the first num_items of array
void maxmin(double array[], int num_items, double* max, double* min);

//shift length-1 elements of the buffer to the left and put the 
//new_item on the right.
void updatebuffer(double buffer[], int length, double new_item);



int main(int argc, char* argv[]) {
	
	/* DO NOT CHANGE THIS PART OF THE CODE */
	double x[MAXPOINTS], y[MAXPOINTS], z[MAXPOINTS];
	int lengthofavg = 0;
	if (argc>1) {
		sscanf(argv[1], "%d", &lengthofavg );
		printf("You entered a buffer length of %d\n", lengthofavg);
	}
	else {
		printf("Enter a length on the command line\n");
		return -1;
	}
	if (lengthofavg <1 || lengthofavg >MAXPOINTS) {
		printf("Invalid length\n");
		return -1;
	}
	/* PUT YOUR CODE HERE */
	int on = 1;
	double gx, gy, gz;
	double _maxX, _maxY, _maxZ;
	double _minX, _minY, _minZ;

	do{
		scanf("%lf, %lf, %lf", &gx, &gy, &gz);
		updatebuffer(x, lengthofavg, gx);
		updatebuffer(y, lengthofavg, gy);
		updatebuffer(z, lengthofavg, gz);
		maxmin(x, lengthofavg, &_maxX, &_minX);
		maxmin(y, lengthofavg, &_maxY, &_minY);
		maxmin(z, lengthofavg, &_maxZ, &_minZ);
		printf("X:%lf, Y:%lf, Z:%lf, Avg X:%lf, Avg Y:%lf, Avg Z:%lf, Max X:%lf, Min X:%lf, Max Y:%lf, Min Y:%lf, Max Z:%lf, Min Z:%lf\n", gx, gy, gz, avg(x, lengthofavg), avg(y, lengthofavg), avg(z, lengthofavg), _maxX, _minX, _maxY, _minY, _maxZ, _minZ); 
	}while(on == 1);
	
}
double avg(double buffer[], int num_items){
	int i;
	int i2;
	double total = 0;
	for(i=0;i<num_items;i++){
		total += buffer[i];
	}
	return (total / num_items);
}
void maxmin(double array[], int num_items, double* _max, double* _min){
	int i; 
	*_max=-99000;
	*_min=99000;
	for (i=0; i<num_items; i++){
		
		if (array[i] > *_max){
			*_max=array[i];
		}
		if (i != 0){
		if (array[i]< *_min){
			*_min=array[i];
		}
		}
	}
	
}
void updatebuffer(double buffer[], int length, double new_item){
	int i;
	for(i=1; i<length;i++){
		buffer[i-1] = buffer[i];
		
	}
	buffer[length - 1] = new_item;
}