#include "histogram.h"
#include <stdio.h>
#include <conio.h>
#include <string.h>

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
	
	
	//Test Constructor without passing BinSize
	histogram hist1(dataset, row_counter);
	
	char example1[strlen("example1.txt")+1]="example1.txt";
	//Test Constructor without passing BinSize but passing filename
	histogram hist2(dataset, row_counter,example1);
	
	//Test Constructor passing BinSize
	histogram hist3(dataset, row_counter, 0.1);
	
	char example2[strlen("example2.txt")+1]="example2.txt";
	//Test Constructor passing BinSize and filename
	histogram hist4(dataset, row_counter, 0.1,example2);
	hist4.show_fit();
	
	printf("Press space to exit\n");
	int inputkey;
    while((inputkey=_getch())==0);
	return 0;
}
