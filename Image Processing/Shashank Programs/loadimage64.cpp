#include<iostream>
#include<stdio.h>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

int main()
{
      Mat src, dst;

      // Load an image
      src = imread("lena.jpg", CV_LOAD_IMAGE_GRAYSCALE);

      if( !src.data )
      { return -1; }
resize(src, dst, Size(64,64), 0, 0,INTER_LINEAR );
        
        for(int y = 0; y < dst.rows; y++){
            for(int x = 0; x < dst.cols; x++){
                printf("%d",dst.at<uchar>(y,x));
}
printf("\n");}   return 0;
}
