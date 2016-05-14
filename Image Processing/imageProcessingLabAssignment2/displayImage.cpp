#include <opencv2/opencv.hpp>
#include "headerfile.h"

using namespace std;
using namespace cv;

void displayImage(string windowName,Mat image){
	namedWindow( windowName, CV_WINDOW_AUTOSIZE );
	imshow(windowName, image );
	waitKey(0);

}
