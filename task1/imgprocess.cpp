#include "imgprocess.h"

cv::Mat RotateImage(cv::Mat &img, float angle)//旋转角度  正逆，负顺
{
    //旋转 & 缩放
    cv::Mat rotation_img;
    cv::Point center = cv::Point2f((float)(img.cols/2.0),(float)(img.rows/2.0)); //旋转中心
    cv::Mat warp_matrix = getRotationMatrix2D(center, angle, 1);  //获得旋转的仿射矩阵
    warpAffine(img, rotation_img, warp_matrix, cv::Size(img.cols, img.rows), cv::INTER_LINEAR);
    return rotation_img;
}
