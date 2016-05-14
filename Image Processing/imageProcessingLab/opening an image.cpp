#include <stdio.h>
#include <opencv2/opencv.hpp>
#include "headerfile.h"
using namespace cv;
int openImage( char* img )
{
	Mat image;
	bool result;
	result=readImage(img,image);

	if(result){
		displayImage("Original Image",image);
		waitKey( 0);
	}
	return 0;
}
