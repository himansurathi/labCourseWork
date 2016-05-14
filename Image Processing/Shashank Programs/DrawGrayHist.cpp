
#include "opencv2/highgui/highgui.hpp"
#include <opencv/cv.h>
#include <opencv2/core/core.hpp>
#include <iostream>
#include <fstream>

using namespace cv;
using namespace std;

void showHistogram(Mat& img)
{
	int bins = 256;             // number of bins
	int nc = img.channels();    // number of channels

	vector<Mat> hist(nc);       // histogram arrays

	// Initalize histogram arrays
	for (int i = 0; i < hist.size(); i++)
		hist[i] = Mat::zeros(1, bins, CV_32SC1);

	// Calculate the histogram of the image
	for (int i = 0; i < img.rows; i++)
	{
		for (int j = 0; j < img.cols; j++)
		{
			for (int k = 0; k < nc; k++)
			{
				uchar val = nc == 1 ? img.at<uchar>(i,j) : img.at<Vec3b>(i,j)[k];
				hist[k].at<int>(val) += 1;
			}
		}
	}

	// For each histogram arrays, obtain the maximum (peak) value
	// Needed to normalize the display later
	int hmax[3] = {0,0,0};
	for (int i = 0; i < nc; i++)
	{
		for (int j = 0; j < bins-1; j++)
			hmax[i] = hist[i].at<int>(j) > hmax[i] ? hist[i].at<int>(j) : hmax[i];
	}

	const char* wname[3] = { "blue", "green", "red" };
	Scalar colors[3] = { Scalar(255,0,0), Scalar(0,255,0), Scalar(0,0,255) };

	vector<Mat> canvas(nc);

	// Display each histogram in a canvas
	for (int i = 0; i < nc; i++)
	{
		canvas[i] = Mat::ones(125, bins, CV_8UC3);

		for (int j = 0, rows = canvas[i].rows; j < bins-1; j++)
		{
			line(
				canvas[i],
				Point(j, rows),
				Point(j, rows - (hist[i].at<int>(j) * rows/hmax[i])),
				nc == 1 ? Scalar(200,200,200) : colors[i],
				1, 8, 0
			);
		}

		imshow(nc == 1 ? "value" : wname[i], canvas[i]);
	}

}
int main( int argc, const char** argv )
{
     Mat img = imread("MYImage2.JPG", -1); //read the image data in the file "MyPic.JPG" and store it in 'img'
    resize(img,img,Size(64,64));
    cvtColor(img,img,CV_BGR2GRAY);

     if (img.empty()) //check whether the image is loaded or not
     {
          cout << "Error : Image cannot be loaded..!!" << endl;
          //system("pause"); //wait for a key press
          return -1;
     }

        showHistogram(img);





     namedWindow("MyWindow", CV_WINDOW_AUTOSIZE); //create a window with the name "MyWindow"
     imshow("MyWindow", img); //display the image which is stored in the 'img' in the "MyWindow" window

     waitKey(0); //wait infinite time for a keypress

     destroyWindow("MyWindow"); //destroy the window with the name, "MyWindow"

     return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
