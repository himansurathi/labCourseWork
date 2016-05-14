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

void displayImage(std::string,cv::Mat);
cv::Mat inverseDiscreteFourierTransform(cv::Mat );
cv::Mat  discreteFourierTransform(cv::Mat);
cv::Mat mydft(cv::Mat);
#endif /* OPENING_AN_IMAGE_H_ */
