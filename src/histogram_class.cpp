#include "histogram.h"
#include <stdio.h>

//constructor for histogram class
histogram::histogram(double* data, int size):size(size){
	dataset = new double[size];
	int i;
	for(i=0;i<size;i++){
		dataset[i]=data[i];
	}
	max_min();
	binner();
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

//Bins the DataSet
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
			}
		}
	}
	FILE *binout;
	binout=fopen("Hist.txt","w");
	for(i=0;i<bins;i++){
		fprintf(binout,"%lf, %lf\n",binCenters[i], binValues[i]);
	}
	fclose(binout);
};
