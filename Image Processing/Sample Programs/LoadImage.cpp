

#include <cv.h>
#include <highgui.h>
using namespace cv;
using namespace std;
int main( int argc, char ** argv )
{
	char * imageName = argv[1];
	Mat image;
	image = imread( imageName, 1 );
	if( argc != 2 || !image.data )
	{
		printf( " No image data \n " );
		return -1;
	}
	Mat gray_image;
	cvtColor( image, gray_image, CV_BGR2GRAY );
	Mat cropped_image (gray_image, Rect(0, 0, gray_image.rows, gray_image.cols) );
	imwrite( "Gray_Image.jpg", gray_image );
	namedWindow( imageName, CV_WINDOW_AUTOSIZE );
	namedWindow( "Gray image", CV_WINDOW_AUTOSIZE );
	namedWindow("Crop",CV_WINDOW_AUTOSIZE );
	imshow( imageName, image );
	imshow( "Gray image", gray_image );
	imshow( "Crop", cropped_image );
	cout << "M = " << endl << " " << gray_image << endl << endl;
	waitKey(0);
	return 0;
}
