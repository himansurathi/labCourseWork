#include <opencv2/opencv.hpp>
#include "headerfile.h"
using namespace std;
using namespace cv;

void logtransformation(Mat image){
	Mat logTransformedImage;

	image.convertTo(logTransformedImage,CV_32F);//Converts an array to another data type
	logTransformedImage=logTransformedImage+1;
	log(logTransformedImage,logTransformedImage);//Computes a natural logarithm of absolute value of each matrix element.
	normalize(logTransformedImage,logTransformedImage,0,255,NORM_MINMAX);// normalize values in such a way that min value is 0 and max value = 255 for every pixel
	convertScaleAbs(logTransformedImage,logTransformedImage);//calculates absolute values, and converts the result to 8-bit.

	displayImage("Log Transformed Image",logTransformedImage);
	waitKey(0);
	cvDestroyWindow("Log Transformed Image");
}

void powertransformation(Mat image,double gamma){
	Mat powerTransformedImage;
	double inverse_gamma=1.0/gamma; //Gamma encoding

	convertScaleAbs(image,powerTransformedImage);//calculates absolute values, and converts the result to 8-bit.
	powerTransformedImage.convertTo(powerTransformedImage,CV_32F);//Converts an array to another data type
	powerTransformedImage=powerTransformedImage+1; // To remove cells with intensity 0
	powerTransformedImage=(powerTransformedImage)/256.0;
	pow(powerTransformedImage,inverse_gamma,powerTransformedImage);
	powerTransformedImage=powerTransformedImage*256; // Re-adjusting the required factor
	powerTransformedImage=powerTransformedImage-1;
	normalize(powerTransformedImage,powerTransformedImage,0,255,NORM_MINMAX);// normalize values in such a way that min value is 0 and max value = 255 for every pixel
	convertScaleAbs(powerTransformedImage,powerTransformedImage);//calculates absolute values, and converts the result to 8-bit.

	displayImage("Power Transformed Image",powerTransformedImage);
	waitKey(0);
	cvDestroyWindow("Power Transformed Image");

}
void histogramEqualization(Mat image){
	Mat histogramImage;
	equalizeHist( image,histogramImage);
	displayImage("Histogram Equalized Image",histogramImage);
	waitKey(0);
	cvDestroyWindow("Histogram Equalized Image");
}
void transformations(Mat image){
	//logtransformation(image);
	//powertransformation(image,2);
	histogramEqualization(image);
}



