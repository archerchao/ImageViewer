#include "mainwindow.h"

#include <QApplication>

#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <string.h>

using namespace cv;
using namespace std;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    std::string path = "/home/superchao/图片/鸣人.jpg";
//    cv::Mat img=cv::imread(path);
//    if(img.empty()){
//        std::cout << "无法读取图片" << std::endl;
//        return 0;
//    }
//    else{
//        std::cout << "图片读取成功" << std::endl;
//    }
//    //展示原图
//    cv::imshow("原图",img);

//    //平移
//    Mat translation_img;
//    Mat warp_matrix = (cv::Mat_<float>(2, 3) << cos(0), -sin(0), img.cols/2 ,
//                                             sin(0), cos(0),  img.rows/2  );
//    cv::warpAffine(img, translation_img, warp_matrix, cv::Size(img.cols, img.rows), cv::INTER_LINEAR);
//    cv::imshow("右下方平移", translation_img);

//    //旋转 & 缩放
//    Mat rotation_img;
//    Point center = Point2f((float)(img.cols/2.0),(float)(img.rows/2.0)); //旋转中心
//    double angle = -45;  //旋转角度  正逆，负顺
//    double scale = 1/sqrt(2); //缩放比例
//    warp_matrix = getRotationMatrix2D(center, angle, scale);  //获得旋转的仿射矩阵
//    warpAffine(img, rotation_img, warp_matrix, cv::Size(img.cols, img.rows), cv::INTER_LINEAR);
//    imshow("45度旋转,1/sqrt(2)倍缩放", rotation_img);

//    //翻转
//    Mat flip_img;
//    flip(img, flip_img,0); //0：上下翻转；1：左右翻转；-1：上下翻转且左右翻转
//    imshow("上下翻转", flip_img);
//    flip(img, flip_img,1); //0：上下翻转；1：左右翻转；-1：上下翻转且左右翻转
//    imshow("左右翻转", flip_img);
//    flip(img, flip_img,-1); //0：上下翻转；1：左右翻转；-1：上下翻转且左右翻转
//    imshow("上下且左右翻转", flip_img);

//    //投影变换
//    Mat transform_img;
//    Point2f srcPoints1[4], dstPoints1[4]; //投影（透视视角）变换
//    srcPoints1[0] = Point2f(0, 0);//左上/原点
//    srcPoints1[1] = Point2f(0, img.rows);//左下角
//    srcPoints1[2] = Point2f(img.cols, 0);//右上角
//    srcPoints1[3] = Point2f(img.cols, img.rows);//右下角
//    //前4点到后4点变换
//    dstPoints1[0] = Point2f(0 + 150, 0 + 150);
//    dstPoints1[1] = Point2f(0 + 50, img.rows);
//    dstPoints1[2] = Point2f(img.cols - 50, 0 + 50 );
//    dstPoints1[3] = Point2f(img.cols, img.rows);
//    //获取设计好的仿射矩阵
//    Mat M2 = getAffineTransform(srcPoints1, dstPoints1);
//    warpAffine(img, transform_img, M2, img.size(), 1, 0);
//    imshow("仿射变换", transform_img);

//    waitKey();

    MainWindow w;
    w.show();
    return a.exec();
}
