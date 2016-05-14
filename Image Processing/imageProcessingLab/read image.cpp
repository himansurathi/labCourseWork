#include <stdio.h>
#include <opencv2/opencv.hpp>
#include "headerfile.h"
using namespace cv;

bool readImage(char *img,Mat &image){
    image = imread(img, CV_LOAD_IMAGE_COLOR);
    if(! image.data )
    {
		  printf( "Could not open or find the image\n" );
		  return false;
    }
    return true;
}

