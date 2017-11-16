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
	
	//Test Constructor without passing BinSize
	histogram hist(dataset, row_counter);
	//Test Constructor without passing BinSize but passing filename
	histogram hist2(dataset, row_counter,"Hello.txt");
	//Test Constructor passing BinSize
	histogram hist1(dataset, row_counter, 0.1);
	//Test Constructor passing BinSize and filename
	histogram hist3(dataset, row_counter, 0.1,"GoodBye.txt");
	
	printf("Press space to exit\n");
	int inputkey;
    while((inputkey=_getch())==0);
	return 0;
}
