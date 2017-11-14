#ifndef HISTOGRAM_H
#define HISTOGRAM_H

class histogram{
	private:
		double* dataset;
	public:
		histogram(double* data, int size);
		~histogram();
};
#endif
