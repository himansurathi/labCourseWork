/*
 * opening an image.h
 *
 *  Created on: 24-Aug-2015
 *      Author: himansu
 */


#ifndef OPENING_AN_IMAGE_H_
#define OPENING_AN_IMAGE_H_

#include <string>
#include <opencv2/opencv.hpp>

int openImage( char*);
int convertToGray( char*);
void displayImage(std::string,cv::Mat);
void printMatrix(cv::Mat);
bool readImage(char*,cv::Mat&);
void applyFilter(cv::Mat);
void transformations(cv::Mat);
void calculateHistogram(cv::Mat);
void showHistogram(cv::Mat);
void thresholdImage(cv::Mat,int,int,std::string);
void smoothing(cv::Mat,int,int,int,int,int);
cv::Mat inverseDiscreteFourierTransform(cv::Mat );
cv::Mat  discreteFourierTransform(cv::Mat);
cv::Mat mydft(cv::Mat);
#endif /* OPENING_AN_IMAGE_H_ */
