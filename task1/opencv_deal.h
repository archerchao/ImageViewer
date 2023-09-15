#ifndef OPENCV_DEAL_H
#define OPENCV_DEAL_H

#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <string.h>
#include <vector>
#include <iostream>
#include <stack>

cv::Mat setMatSize(cv::Mat mat_img, float scale);
cv::Mat setMatAngle(cv::Mat mat_img, float angle);
cv::Mat invertColors(cv::Mat mat_img);
cv::Mat grayscale(cv::Mat mat_img);
cv::Mat binarization(cv::Mat mat_img, int value);
cv::Mat flips(cv::Mat mat_img, int flipcode);
cv::Mat biliner_size(cv::Mat mat_img, double sx, double sy);
cv::Mat bevel(cv::Mat, float angle1, float angle2);
cv::Mat perspective(cv::Mat mat_img, cv::Mat perspectiveMatrix, cv::Size outputSize);
std::vector<int> calculateHistogram(cv::Mat& inputImage);// 自定义函数，计算图像的灰度直方图
cv::Mat drawHistogram(const std::vector<int>& histogram);
cv::Mat equalizeGrayHistogram(const cv::Mat& inputImage);// 自定义函数，执行直方图均衡化
cv::Mat grayHistogram(cv::Mat mat_img);

void addSaltAndPepperNoise(cv::Mat& image, double noiseRatio);// 自定义函数，添加椒盐噪声
cv::Mat medianFilter(const cv::Mat& inputImage, int kernelSize);// 自定义中值滤波函数

cv::Mat applyRobertOperator(const cv::Mat& inputImage);// 自定义函数，应用Robert算子进行图像锐化
cv::Mat applySobelOperator(const cv::Mat& inputImage);// 自定义函数，应用Sobel算子进行图像锐化
cv::Mat applyLaplaceOperator(const cv::Mat& inputImage);// 自定义函数，应用Laplace算子进行图像锐化

cv::Mat DomainLowPassFilter(const cv::Mat& inputImage, double cutoffFrequency);// 自定义函数，应用频域低通滤波
cv::Mat DomainHighPassFilter(const cv::Mat& inputImage, double cutoffFrequency);// 自定义函数，应用频域高通滤波

cv::Mat dualThresholds(const cv::Mat& inputImage, double threshold1, double threshold2);// 自定义函数，使用双阈值法分割图像

cv::Mat regionGrowing(const cv::Mat& inputImage, cv::Point seedPoint, int similarityThreshold);// 自定义函数，使用区域生长法分割图像

cv::Mat watershed(const cv::Mat& inputImage, int value);

#endif // OPENCV_DEAL_H
