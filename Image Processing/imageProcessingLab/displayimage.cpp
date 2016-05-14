#include <opencv2/opencv.hpp>
#include "headerfile.h"

using namespace std;
using namespace cv;

void displayImage(string windowName,Mat image){
	namedWindow( windowName, CV_WINDOW_AUTOSIZE );
	imshow(windowName, image );
}

void printMatrix(Mat image){
   for(int i=0;i<image.rows;i++){
	   for(int j=0;j<image.cols;j++){
		   cout<<(int)image.at<uchar>(i, j)<<" ";
	   }
	   cout<<endl;
   }
}

