#ifndef HISTOGRAM_H
#define HISTOGRAM_H

class histogram{
	private:
		double* dataset;
		int size;
		double max;
		double min;
		void max_min();
		double binsize;
		void binner();
		double* binEdges;
		double* binCenters;
		double* binValues;
		double mean;
		double meansquare;
		double sdev; //standard deviation
	public:
		histogram(double* data, int size);
		~histogram();
};
#endif
