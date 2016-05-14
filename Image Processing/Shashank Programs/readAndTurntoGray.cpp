
#include "opencv2/highgui/highgui.hpp"
#include <opencv/cv.h>
#include <opencv2/core/core.hpp>
#include <iostream>
#include <fstream>

using namespace cv;
using namespace std;

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


     ofstream myfile;
     myfile.open("image1.txt");
    myfile<<img;
    myfile.close();



     namedWindow("MyWindow", CV_WINDOW_AUTOSIZE); //create a window with the name "MyWindow"
     imshow("MyWindow", img); //display the image which is stored in the 'img' in the "MyWindow" window

     waitKey(0); //wait infinite time for a keypress

     destroyWindow("MyWindow"); //destroy the window with the name, "MyWindow"

     return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
