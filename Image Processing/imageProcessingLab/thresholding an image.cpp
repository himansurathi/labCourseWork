#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <stdlib.h>
#include <stdio.h>
#include "headerfile.h"
using namespace cv;


void thresholdImage(Mat image,	int thresholdLowerValue,int thresholdHigherValue,String window)
{
	int threshold_type = 3;
	Mat dst;
	threshold( image, dst, thresholdLowerValue,thresholdHigherValue,threshold_type );
	showHistogram(dst);
	displayImage(window,dst);
}

