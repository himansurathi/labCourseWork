#include<cv.h>
#include<stdio.h>
#include<highgui.h>
 using namespace cv ;
int main(int argc , char ** argv)
{
	char *imagename = argv[1];
	Mat image ;
	image = imread(imagename , 1);
	Mat grayImage ;
	cvtColor(image , grayImage , CV_BGR2GRAY);
	imwrite("abcd.jpg" , grayImage);
	namedWindow(" Display Grayscale" , CV_WINDOW_AUTOSIZE);
	imshow(" Display Grayscale" , grayImage);

	int m = grayImage.rows;
		int n = grayImage.cols;
		float con=0,con1=0,con2=0,contrast=0;

		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				float pixel = (float)grayImage.at<uchar>(i, j);
				//con1+=(pixel*pixel);
				//con2 += pixel;
				printf("%f " , pixel);
			}
			printf("\n");
		}
	waitKey(0);
	return 0 ;
}
