// averagefiltering1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <stdlib.h>
#include <stdio.h>
#pragma warning(disable:4996)
#include<string>
#include<cv.h>
using namespace cv;
using namespace std;
//function for finding entropy of an image
float calentropy(Mat frame)
{
	/// Establish the number of bins
	int histSize = 256;
	/// Set the ranges ( for B,G,R) )
	float range[] = { 0, 256 };
	const float* histRange = { range };
	bool uniform = true; bool accumulate = false;
	/// Compute the histograms:
	MatND hist;
	calcHist(&frame, 1, 0, Mat(), hist, 1, &histSize, &histRange, uniform, accumulate);
	hist /= frame.total();
	Mat logP;
	log(hist, logP);
	float entropy = -1 * sum(hist.mul(logP)).val[0];
	return entropy;
}
//function for finding mean of an image

float findmean(Mat img)
{
	int i, j, sum = 0;
	float mean = 0.0;
	int m = img.rows;
	int n = img.cols;
	int total = m*n;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			sum += (int)img.at<uchar>(i, j);
		}
	}
	mean = (float)sum / total;
	return mean;
}
//function for finding AMBE of an image

double findambe(Mat img, Mat dst)
{
	float ambe;
	float src = findmean(img);
	float dest = findmean(dst);
	ambe = src - dest;
	if (ambe < 0.0)
		ambe *= -1;
	return ambe;

}
//function for finding MSE and PSNR of an image

double getPSNR(const Mat& I1, const Mat& I2,FILE *out)
{
	Mat s1;
	absdiff(I1, I2, s1);       // |I1 - I2|
	s1.convertTo(s1, CV_32F);  // cannot make a square on 8 bits
	s1 = s1.mul(s1);           // |I1 - I2|^2
	Scalar s = sum(s1);         // sum elements per channel
	double sse = s.val[0]; // sum channels
	if (sse <= 1e-10) // for small values return zero
		return 0;
	else
	{
		double  mse = sse / (double)(I1.channels() * I1.total());
		fprintf(out,"\nMSE:%f", mse);
		double psnr = 10.0*log10((255 * 255) / mse);
		return psnr;
	}
}
//function for finding correlation of an image

double correlation(Mat src, Mat dst)
{
	int m = src.rows;
	int n = src.cols;
	float sum1 = 0.0;
	float sum2 = 0.0;
	float sum3 = 0.0;
	float sum = 0.0;
	float goriginalmean = findmean(dst);
	float gnoisedmean = findmean(src);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			float goriginal = (float)dst.at<uchar>(i, j);
			float gnoised = (float)src.at<uchar>(i, j);
			sum1 += ((goriginal - goriginalmean)*(gnoised - goriginalmean));
			sum2 += ((goriginal - goriginalmean)*(goriginal - goriginalmean));
			sum3 += ((gnoised - gnoisedmean)*(gnoised - gnoisedmean));
		}
	}
	float root = sqrt(sum2*sum3);
	sum += (sum1 / root);
	return sum;
}
//function for finding contrast of an image
float findcontrast(Mat src)
{
	int m = src.rows;
	int n = src.cols;
	float con=0,con1=0,con2=0,contrast=0;
	
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			float pixel = (float)src.at<uchar>(i, j);
			con1+=(pixel*pixel);
			con2 += pixel;
		}
	}
	con1 /= (m*n);
	con2 /= (m*n);
	con2 *= con2;
	con = con1 - con2;
	contrast = 10 * log10(con);
	return contrast;
}
//function for average filtering
Mat conv2(Mat src, int kernel_size)
{
	Mat dst;
	//apply filter
	boxFilter(src, dst, -1, Size(kernel_size, kernel_size), Point(-1, -1), true, BORDER_DEFAULT);
	return dst;
}
//main function
int main(int argc, const char** argv)
{
	String s1 = "1", s5 = "_back.JPG";
	for (int i = 88; i <= 93; i++)
	{
		for (int j = 1; j <= 10; j++)
		{
			for (int k = 1; k <= 2; k++)
			{
				String s2 = to_string(i);
				String s3 = "_" + to_string(j);
				String s4 = "_" + to_string(k);
				String s = s1 + s2 + s3 + s4 + s5;

				char str[30];
				strncpy(str, s.c_str(), sizeof(str));
				Mat img = imread(s, CV_LOAD_IMAGE_GRAYSCALE); //read the image data in the file "MyPic.JPG" and store it in 'img'

				if (img.empty()) //check whether the image is loaded or not
				{
					continue;

				}
				else
				{

					//namedWindow("MyWindow", CV_WINDOW_AUTOSIZE);
					//imshow("MyWindow", img);
					Mat dst = conv2(img, 3);

					FILE *out = fopen("backview.txt", "a");
					if (!out)

					{
						printf("Error opening file");
						return(1);
					}

					fprintf(out, "\nImage: %s", str);
					float oldentropy = calentropy(img);
					fprintf(out, "\nEntropy of noisy image:%f", oldentropy);
					float newentropy = calentropy(dst);
					fprintf(out, "\nEntropy of filtered image:%f", newentropy);
					float ambe = findambe(img, dst);
					fprintf(out, "\nambe:%f", ambe);
					double psnr = getPSNR(img, dst, out);
					fprintf(out, "\nPSNR=%f", psnr);
					float sum = correlation(img, dst);
					fprintf(out, "\nCorrelation:%f", sum);
					float oldcontrast = findcontrast(img);
					fprintf(out, "\nContrast of noisy image:%f", oldcontrast);
					float newcontrast = findcontrast(dst);
					fprintf(out, "\nContrast of filtered image:%f\n", newcontrast);
					fclose(out);
				}
			}
		}
	}
	//asnr(img, dst);
	waitKey(0); //wait infinite time for a keypress
	return 0;
	
}


