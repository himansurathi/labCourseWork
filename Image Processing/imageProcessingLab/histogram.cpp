#include <stdio.h>
#include <iostream>
#include <opencv2/opencv.hpp>
#include "headerfile.h"

using namespace std;
using namespace cv;

void showHistogram(Mat image)
{
	int bins = 256;             // number of bins
	int nc = image.channels();  // number of channels

	vector<Mat> hist(nc);       // histogram arrays

	// Initialize histogram arrays
	for (int i = 0; i < hist.size(); i++)
		hist[i] = Mat::zeros(1, bins, CV_32SC1);

	// Calculate the histogram of the image
	for (int i = 0; i < image.rows; i++)
	{
		for (int j = 0; j < image.cols; j++)
		{
			for (int k = 0; k < nc; k++)
			{
				uchar val = nc == 1 ? image.at<uchar>(i,j) : image.at<Vec3b>(i,j)[k];
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

		imshow(nc == 1 ? "Gray Scale Histogram" : wname[i], canvas[i]);
	}
}
void calculateHistogram(Mat src){
	Mat dst;
	vector<Mat> bgr_planes;
	split( src, bgr_planes );
	/// Establish the number of bins
	int histSize = 256;
	/// Set the ranges ( for B,G,R) )
	float range[] = { 0, 256 } ;
	const float * histRange = { range };
	bool uniform = true; bool accumulate = false;
	Mat b_hist, g_hist, r_hist;
	/// Compute the histograms:
	calcHist( &bgr_planes[0], 1, 0, Mat(), b_hist, 1, &histSize, &histRange, uniform, accumulate );
	calcHist( &bgr_planes[1], 1, 0, Mat(), g_hist, 1, &histSize, &histRange, uniform, accumulate );
	calcHist( &bgr_planes[2], 1, 0, Mat(), r_hist, 1, &histSize, &histRange, uniform, accumulate );
	// Draw the histograms for B, G and R
	int hist_w = 512; int hist_h = 400;
	int bin_w = cvRound( (double) hist_w/histSize );

	Mat histImage( hist_h, hist_w, CV_8UC3, Scalar( 0,0,0) );
	/// Normalize the
	normalize(b_hist,b_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat() );
	normalize(g_hist,g_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat() );
	normalize(r_hist,r_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat() );

	/// Draw for each channel
	for( int i = 1; i < histSize; i++ )
	{
		line( histImage, Point( bin_w*(i-1), hist_h - cvRound(b_hist.at<float>(i-1)) ) ,
		Point( bin_w*(i), hist_h - cvRound(b_hist.at<float>(i)) ),
		Scalar( 255, 0, 0), 2, 8, 0 );
		line( histImage, Point( bin_w*(i-1), hist_h - cvRound(g_hist.at<float>(i-1)) ) ,
		Point( bin_w*(i), hist_h - cvRound(g_hist.at<float>(i)) ),
		Scalar( 0, 255, 0), 2, 8, 0 );
		line( histImage, Point( bin_w*(i-1), hist_h - cvRound(r_hist.at<float>(i-1)) ) ,
		Point( bin_w*(i), hist_h - cvRound(r_hist.at<float>(i)) ),
		Scalar( 0, 0, 255), 2, 8, 0 );
	}
	displayImage("RGB Histogram",histImage);
    waitKey(0);

}
