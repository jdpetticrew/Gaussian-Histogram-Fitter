The Gaussian Histogram Fitter is a C++ class for putting a 1d data set into a histogram,
fitting that histogram to a single peaked gaussian probability density fuction of the form
f(x)=a exp(-((x-b)/c)^2) and calculating the Full-Width at Half-Maximum.

It has been tested with data generated at random.org

The class is contained in histogram_class.cpp and histogram.h.
main.cpp has been included as a demonstration only.

The class has 4 constructors.
1) histogram(double* data, int size);
	Pass the 1d data array and the number of elements it contains.
	The class will ask for a user input for histogram bin width and output the histgram data and fit to Hist.txt
2) histogram(double* data, int size, double binsize);
	Pass the 1d data array, the number of elements the array contains, and the histogram bin width.
	The class will output  the histgram data and fit to Hist.txt
3) histogram(double* data, int size, char* fname);
	Pass the 1d data array, the number of elements the array contains, and a file name to output the data and fit.
	The class will ask for a user input for histogram bin width and output the fit and data to the passed file name.
4) histogram(double* data, int size, double binsize, char* fname);
	Pass the 1d data array, the number of elements the array contains, the histogram bin width, and a file name to output the data and fit.
	The class will utput the fit and data to the passed file name.

Public functions:
Get_FWHM() will return the Full-Width at Half-Maximum as a double.
Get_Mean() will return the mean of the histogram as a double.
Get_SDev() will return the standard deviation of the histogram as a double.
show_fit() will print the fitted probability density function in terminal.

LICENSE
The Gaussian Histogram Fitter has been released under the Apache 2.0 license.
Please see NOTICE.txt and LICENSE.txt