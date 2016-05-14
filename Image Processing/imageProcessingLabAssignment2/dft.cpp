#include <opencv2/opencv.hpp>
#include <cstdio>
#include "headerfile.h"
using namespace cv;

Mat magimage;
Mat mydft(Mat image){
	Mat padded;                            //expand input image to optimal size
	Mat compleximage;
	int m = getOptimalDFTSize( image.rows );
    int n = getOptimalDFTSize( image.cols ); // on the border add zero values
    copyMakeBorder(image, padded, 0, m - image.rows, 0, n - image.cols, BORDER_CONSTANT, Scalar::all(0));

    Mat planes[]= {Mat_<float>(padded), Mat::zeros(padded.size(), CV_32F)};
    merge(planes, 2, compleximage);         // Add to the expanded another plane with zeros

    dft(compleximage, compleximage);            // this way the result may fit in the source matrix

    split(compleximage, planes);                   // planes[0] = Re(DFT(I), planes[1] = Im(DFT(I))
    magnitude(planes[0], planes[1], planes[0]);    // planes[0] = magnitude
    magimage = planes[0];
    return compleximage;
}
Mat  discreteFourierTransform(Mat image){

	Mat compleximage,result;
	compleximage=mydft(image);

    // compute the magnitude and switch to logarithmic scale
    // => log(1 + sqrt(Re(DFT(I))^2 + Im(DFT(I))^2))

    magimage += Scalar::all(1);                    // switch to logarithmic scale
    log(magimage, magimage);

    // crop the spectrum, if it has an odd number of rows or columns
    magimage = magimage(Rect(0, 0, magimage.cols & -2, magimage.rows & -2));

    // rearrange the quadrants of Fourier image  so that the origin is at the image center
    int cx = magimage.cols/2;
    int cy = magimage.rows/2;

    Mat q0(magimage, Rect(0, 0, cx, cy));   // Top-Left - Create a ROI per quadrant
    Mat q1(magimage, Rect(cx, 0, cx, cy));  // Top-Right
    Mat q2(magimage, Rect(0, cy, cx, cy));  // Bottom-Left
    Mat q3(magimage, Rect(cx, cy, cx, cy)); // Bottom-Right

    Mat tmp;                           // swap quadrants (Top-Left with Bottom-Right)
    q0.copyTo(tmp);
    q3.copyTo(q0);
    tmp.copyTo(q3);

    q1.copyTo(tmp);                    // swap quadrant (Top-Right with Bottom-Left)
    q2.copyTo(q1);
    tmp.copyTo(q2);

    normalize(magimage, result, 0, 1, CV_MINMAX); // Transform the matrix with float values into a
                                            // viewable image form (float between values 0 and 1).

    return result;
}
Mat inverseDiscreteFourierTransform(Mat image){
		Mat inverseTransform;

		idft(image, inverseTransform, DFT_INVERSE | DFT_REAL_OUTPUT);
        normalize(inverseTransform, inverseTransform, 0, 1, CV_MINMAX);
        return inverseTransform;
}
