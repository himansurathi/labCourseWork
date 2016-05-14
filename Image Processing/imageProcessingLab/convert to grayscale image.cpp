
#include <stdio.h>
#include <iostream>
#include <opencv2/opencv.hpp>
#include "headerfile.h"

using namespace std;
using namespace cv;

int convertToGray(char *img)
{

		Mat image,dftimage;
		bool result;
		result=readImage(img,image);
		if(result){

		   Mat gray;// Create a new matrix to hold the gray image

		   resize(image,gray,Size(64,64),0,0,INTER_AREA);

		   cvtColor(gray, gray, CV_BGR2GRAY);// convert RGB image to gray

		   displayImage("Gray Scale Image",gray);
		   waitKey(0);
		   printMatrix(gray);
		   cout<<"Number of Rows in image is "<<gray.rows<<endl;
		   cout<<"Number of Columns in image is "<<gray.cols<<endl;

		   showHistogram(gray);
		   calculateHistogram(image);
		   applyFilter(gray);


		   thresholdImage(gray,0,50,"Low Threshold Image");
		   waitKey(0);
		   thresholdImage(gray,50,200,"Medium Threshold Image");
		   waitKey(0);
		   thresholdImage(gray,200,255,"High Threshold Image");
		   waitKey(0);

		   dftimage=discreteFourierTransform(gray);
		   displayImage("Discrete Fourier Transform",dftimage);
    	   waitKey(0);

		   smoothing(gray,40,40,1,3,5);
		   transformations(gray);

		}
        return 0;
}
