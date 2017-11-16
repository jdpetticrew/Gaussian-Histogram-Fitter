#ifndef HISTOGRAM_H
#define HISTOGRAM_H

class histogram{
	private:
		double* dataset;
		int size;
		double max;
		double min;		
		double binsize;
		double* binEdges;
		double* binCenters;
		double* binValues;
		double mean;
		double meansquare;
		double sdev; //standard deviation
		//Gaussian in the form f(x) = a exp(-((x-b)/c)^2)
		double a;
		double b;
		double c;
		double FWHM;
		char* filename;
		int bins;
		int charstored=0;
		
		void binner(); //Bins the DataSet and calculates mean and standard deviation
		void fit(); //Fits Gaussian Probability Density Function in the form f(x) = a exp(-((x-b)/c)^2)
		void max_min(); //finds maximum and minimum in dataset
		void print(); //Prints Histogram Data to Hist.txt Used if no string is passed in constructor
		void print_custom(); //Prints Histogram Data to custom file
	public:
		histogram(double* data, int size); //constructor for histogram class Ask for Bin Size
		histogram(double* data, int size, double binsize); //constructor for histogram class passed Bin Size
		histogram(double* data, int size, char* fname); //constructor for histogram class Ask for Bin Size and passes string for printing Hist to file.
		histogram(double* data, int size, double binsize, char* fname); //constructor for histogram class passed Bin Size and passes string for printing Hist to file.
		~histogram();
		double Get_FWHM(){return FWHM;}; //Returns Full-Width @ Half-Maximum
		double Get_Mean(){return mean;}; //Returns Mean of Histogram
		double Get_SDev(){return sdev;}; //Returns Standard Deviation of Histogram
		void show_fit();// displays Probability Density function of gaussian
};
#endif
