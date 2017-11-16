#include "histogram.h"
#include <stdio.h>
#include <math.h>
#include <string.h>

//constructor for histogram class Ask for Bin Size
histogram::histogram(double* data, int size):size(size){
	dataset = new double[size];
	int i;
	for(i=0;i<size;i++){
		dataset[i]=data[i];
	}
	mean=0;
	meansquare=0;
	max_min();
	printf("Enter Bin Width:");
	scanf("%lf",&binsize);
	binner();
	fit();
	print();
};

//constructor for histogram class passed Bin Size
histogram::histogram(double* data, int size, double binsize):size(size), binsize(binsize){
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
	print();
};

//constructor for histogram class Ask for Bin Size and passes string for printing Hist to file.
histogram::histogram(double* data, int size, char* fname):size(size){
	filename=new char[strlen(fname)+1];
	strcpy(filename,fname);
	dataset = new double[size];
	int i;
	for(i=0;i<size;i++){
		dataset[i]=data[i];
	}
	mean=0;
	meansquare=0;
	max_min();
	printf("Enter Bin Width:");
	scanf("%lf",&binsize);
	binner();
	fit();
	print_custom();
};

//constructor for histogram class passed Bin Size and passes string for printing Hist to file.
histogram::histogram(double* data, int size, double binsize, char* fname):size(size), binsize(binsize){
	filename=new char[strlen(fname)+1];
	strcpy(filename,fname);
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
	print_custom();	
};

//destructor for histogram class
histogram::~histogram(){
	delete[] dataset;
	delete[] binEdges;
	delete[] binCenters;
	delete[] binValues;
	if(charstored!=0) delete[] filename;
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
	bins=(max-min)/binsize+3;
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
};

//Fits Gaussian Probability Density Function in the form f(x) = a exp(-((x-b)/c)^2)
void histogram::fit(){
	a=1/(sdev*sqrt(2*3.141592653589793));
	b=mean;
	c=sqrt(2)*sdev;
	FWHM = 2.3548*sdev;
};

//Prints Histogram Data to Hist.txt
void histogram::print(){
	FILE *binout;
	binout=fopen("Hist.txt","w");
	fprintf(binout,"f(x)= %lf * exp(-((x-%lf)/%lf)^2)\n",a,b,c);
	int i;
	for(i=0;i<bins;i++){
		fprintf(binout,"%lf, %lf\n",binCenters[i], binValues[i]);
	}
	fclose(binout);
};

//Prints Histogram Data to custom file
void histogram::print_custom(){
	charstored=1; //tells destructor to delete filename
	FILE *binout;
	binout=fopen(filename,"w");
	fprintf(binout,"f(x)= %lf * exp(-((x-%lf)/%lf)^2)\n",a,b,c);
	int i;
	for(i=0;i<bins;i++){
		fprintf(binout,"%lf, %lf\n",binCenters[i], binValues[i]);
	}
	fclose(binout);
};

//Displays Histogram fit in terminal
void histogram::show_fit(){
	printf("f(x)= %lf * exp(-((x-%lf)/%lf)^2)\n",a,b,c);
};
