#include "histogram.h"
#include <stdio.h>

//constructor for histogram class
histogram::histogram(double* data, int size){
	dataset = new double[size];
	int i;
	for(i=0;i<size;i++){
		dataset[i]=data[i];
	}
	printf("I have an array of %d elements\n",i);
};

//destructor for histogram class
histogram::~histogram(){
	delete[] dataset;
};

