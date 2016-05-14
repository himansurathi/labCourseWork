#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

Mat change(Mat m);

int main()

{
    Mat image = imread("C:/Users/Public/Pictures/Sample Pictures/Penguins.jpg");

    Mat copy = Mat::zeros(image.size(),image.type());

    Mat changedImage = change(copy);

    namedWindow("Image");
    imshow("Image",changedImage);

    waitKey(0);
}

Mat change(Mat m)
{
    int cols = m.cols;
    int rows = m.rows;

    double alpha = 2.2;
    int beta = 50;


    for(int i=0;i<rows;i++)
    {
        for(int c=0;c<cols;c++)
        {
            m.at<Vec3b>(rows,c)[0] = saturate_cast<uchar>(alpha* (m.at<Vec3b>(rows,cols)[0]) + beta);
            m.at<Vec3b>(rows,c)[1] = saturate_cast<uchar>(alpha* (m.at<Vec3b>(rows,cols)[1]) + beta);
            m.at<Vec3b>(rows,c)[2] = saturate_cast<uchar>(alpha* (m.at<Vec3b>(rows,cols)[2]) + beta);
        }
    }

    return m;

}
T
