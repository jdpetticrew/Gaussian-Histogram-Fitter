#include "histogram.h"
#include <stdio.h>
#include <math.h>

//constructor for histogram class
histogram::histogram(double* data, int size):size(size){
	dataset = new double[size];
	int i;
	for(i=0;i<size;i++){
		dataset[i]=data[i];
	}
	mean=0;
	meansquare=0;
	max_min();
	binner();
	fit();
};

//destructor for histogram class
histogram::~histogram(){
	delete[] dataset;
	delete[] binEdges;
	delete[] binCenters;
	delete[] binValues;
};

//finds maximum and minimum in dataset
void histogram::max_min(){
	max=dataset[0];
	min=dataset[0];
	int i;
	for(i=1;i<size;i++){
		if(dataset[i]>max) max=dataset[i];
		else if(dataset[i]<min) min=dataset[i];
	}
};

//Bins the DataSet and calculates mean and standard deviation
void histogram::binner(){
	printf("Enter Bin Width:");
	scanf("%lf",&binsize);
	int bins=(max-min)/binsize+3;
	binEdges = new double[bins+1];
	binCenters = new double[bins];
	binValues = new double[bins];
	int i, j;
	for(i=0;i<(bins+1);i++){
		binEdges[i]=(min-binsize)+i*binsize;
	}
	for(i=0;i<bins;i++){
		binCenters[i]=(binEdges[i+1]-binEdges[i])/2 +binEdges[i];
		binValues[i]=0;
	}
	
	for(j=0;j<size;j++){
		for(i=0;i<bins;i++){
			if(dataset[j]>=binEdges[i] && dataset[j]<binEdges[i+1]){
				binValues[i]++;
				mean+=binCenters[i]/size;
			}
		}
	}
	for(i=0;i<bins;i++){
		meansquare+=binValues[i]*(binCenters[i]-mean)*(binCenters[i]-mean);
	}
	sdev=sqrt((meansquare-mean)/(size-1));
	printf("Mean: %lf, Standard Deviation: %lf\n", mean, sdev);
	FILE *binout;
	binout=fopen("Hist.txt","w");
	for(i=0;i<bins;i++){
		fprintf(binout,"%lf, %lf\n",binCenters[i], binValues[i]);
	}
	fclose(binout);
};

//Fits Gaussian Probability Density Function in the form f(x) = a exp(-((x-b)/c)^2)
void histogram::fit(){
	a=1/(sdev*sqrt(2*3.141592653589793));
	b=mean;
	c=sqrt(2)*sdev;
	printf("a: %lf, b: %lf, c: %lf\n", a, b,c);
};
