#include <opencv2/opencv.hpp>
#include "headerfile.h"
using namespace cv;

void idealLowPassFilter(Mat image,int dmin){
	double dist;
	Mat compleximage1,compleximage2,result;
	compleximage1=mydft(image);
	compleximage2=mydft(image);
	Point centre = Point(image.rows / 2, image.cols / 2);
	for(int i = 0; i < compleximage1.rows; i++)
		{
			for(int j = 0; j < compleximage1.cols; j++)
			{
				dist = (double) pow((i - centre.x), 2.0) + pow((double) (j - centre.y), 2.0);
				if(dist>(dmin*dmin))
					compleximage1.at<float>(i,j) = 0;
				if(dist<=(dmin*dmin))
				    compleximage2.at<float>(i,j) = 0;

			}
		}

	compleximage1=inverseDiscreteFourierTransform(compleximage1);
	compleximage2=inverseDiscreteFourierTransform(compleximage2);
	displayImage("Ideal Low Pass Filter",compleximage1);
	waitKey(0);
	displayImage("Ideal High Pass Filter",compleximage2);
	waitKey(0);

}

void ButterWorthLowPassFilter(Mat image,int dmin,int n,int W){
	double radius;
	Mat compleximage1,compleximage2;
	compleximage1=mydft(image);
	compleximage2=mydft(image);
	Point centre = Point(image.rows / 2, image.cols / 2);
	for (int i = 0; i < compleximage1.rows; i++)
	    {
	        for (int j = 0; j < compleximage1.cols; j++)
	        {
	            radius = (double) pow((i - centre.x), 2.0) + pow((double) (j - centre.y), 2.0);

	            // Butterworth low pass:
	            // tmp.at<float>(i,j) = (float)
	            //                        ( 1 / (1 + pow((double) (radius /  D), (double) (2 * n))));

	            // D(u,v) -> radius
	            // D_0 -> dmin
	            compleximage1.at<float>(i, j) = compleximage1.at<float>(i, j)*
	            		(float)( 1.0 / (1 + pow((double) (radius ) / dmin, (double) (2 * n))));
	            compleximage2.at<float>(i, j) = compleximage2.at<float>(i, j) *
	            		(float) ( 1.0 / (1 +  pow( dmin/(double) (radius ) , (double) (2 * n))));
	        }
	    }
	compleximage1=inverseDiscreteFourierTransform(compleximage1);
	compleximage2=inverseDiscreteFourierTransform(compleximage2);
	displayImage("Butter Worth Low Pass Filter",compleximage1);
	waitKey(0);
	displayImage("Butter Worth High Pass Filter",compleximage2);
	waitKey(0);
}
void GaussianLowPassFilter(Mat image,int MAX_KERNEL_LENGTH){
    Mat result;
	for ( int i = 1; i < MAX_KERNEL_LENGTH; i = i + 2 )
	   GaussianBlur( image, result, Size( i, i ), 0, 0 );
	displayImage("Gaussian Low Pass Filter",result);
	waitKey(0);
    addWeighted(image, 1.5, result, -0.5, 0, result); // from stackoverflow
	displayImage("Gaussian High Pass Filter",result);
	waitKey(0);
}

void smoothing(Mat dftimage,int dlow,int dbutter,int order,int W,int MAX_KERNEL_LENGTH){
   idealLowPassFilter(dftimage,dlow);
   ButterWorthLowPassFilter(dftimage,dbutter,order,W);
   GaussianLowPassFilter(dftimage,MAX_KERNEL_LENGTH);
}
