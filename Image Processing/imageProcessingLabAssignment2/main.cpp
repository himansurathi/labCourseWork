#include <stdio.h>
#include <opencv2/opencv.hpp>
using namespace cv;

int main( int argc, char** argv )
{
	Mat image,padded;
	if (argc != 2)
	{
	printf( "Sorry!!! Enter Image Name as a command line argument\n" );
	return -1;
	}
	image = imread(argv[1], CV_LOAD_IMAGE_COLOR);

	//	Mat localMean(image.rows,image.cols,0);
	//	int padding=2,ksize=3,i,j;
	//	copyMakeBorder(image,padded,padding,padding,padding,padding,BORDER_CONSTANT,Scalar::all(0));
	//	for(i=0;i<=padded.rows-ksize;i++){
	//		for(j=0;j<=padded.cols-ksize;j++){
	//			Mat temp=padded(Rect(i,j,3,3));
	//			localMean[i][j]=mean(temp);
	//
	//		}
	//	}
	return 0;
}
