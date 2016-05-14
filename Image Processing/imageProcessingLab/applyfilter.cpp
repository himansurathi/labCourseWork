#include <opencv2/opencv.hpp>
#include "headerfile.h"
using namespace cv;


void applyFilter(Mat image){
	Mat filteredImage,element;
	int kernel_size=3,erosion_size=1;//aperture linear size; it must be odd and greater than 1

	element = getStructuringElement( MORPH_RECT,
        						     Size( 2*erosion_size + 1, 2*erosion_size+1 ),
	                                 Point( erosion_size, erosion_size ) );
	erode(image, filteredImage,element);
	displayImage("Min Filtered Image",filteredImage);
	waitKey(0);
	cvDestroyWindow("Min Filtered Image");

	dilate(image, filteredImage,element);
	displayImage("Max Filtered Image",filteredImage);
	waitKey(0);
	cvDestroyWindow("Max Filtered Image");

	boxFilter(image, filteredImage, -1, Size(kernel_size, kernel_size),
			  Point(-1, -1), true, BORDER_DEFAULT);
	displayImage("Average Filtered Image",filteredImage);
	waitKey(0);
	cvDestroyWindow("Average Filtered Image");

	medianBlur(image,filteredImage,kernel_size );
	displayImage("Median Filtered Image",filteredImage);
	waitKey(0);
	cvDestroyWindow("Median Filtered Image");

}



