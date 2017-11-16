#include "histogram.h"
#include <stdio.h>
#include <conio.h>
int main(){
    //Read In Data Set
    FILE *data;
    data=fopen("data.txt","r");
    int row_counter=0;
    double test;
    while(fscanf(data,"%lf\n",&test)>0){
    	row_counter++;
	}
	double dataset[row_counter];
	rewind(data);
	int i=0;
	for(i=0;i<row_counter;i++){
		fscanf(data,"%lf\n",&dataset[i]);
	}
	histogram hist(dataset, row_counter);
	
	histogram hist1(dataset, row_counter, 0.1);
	
	printf("Press space to exit\n");
	int inputkey;
    while((inputkey=_getch())==0);
	return 0;
}
