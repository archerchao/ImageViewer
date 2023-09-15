#include "opencv_deal.h"
#include <QDebug>

cv::Mat setMatSize(cv::Mat mat_img, float scale)
{
    cv::Mat new_img;
//    //旋转 & 缩放
//    cv::Point center = cv::Point2f((float)(mat_img.cols/2.0),(float)(mat_img.rows/2.0)); //旋转中心
//    cv::Mat warp_matrix = getRotationMatrix2D(center, angle, scale);  //获得旋转的仿射矩阵
//    warpAffine(mat_img, new_img, warp_matrix, cv::Size(mat_img.cols, mat_img.rows), cv::INTER_LINEAR);
//    return new_img;
}

cv::Mat setMatAngle(cv::Mat mat_img, float angle)
{
    cv::Mat new_img;
    /*
    对旋转的进行改进，由于图形是一个矩形，旋转后的新图像的形状是一个原图像的外接矩形
    因此需要重新计算出旋转后的图形的宽和高
    */
    int width = mat_img.cols;
    int height = mat_img.rows;

    double radian= angle * CV_PI / 180.;//角度转换为弧度
    double width_rotate = fabs(width*cos(radian))+fabs(height*sin(radian));
    double height_rotate= fabs(width*sin(radian)) + fabs(height*cos(radian));

    //旋转中心 原图像中心点
    cv::Point center = cv::Point2f((float)(mat_img.cols/2.0),(float)(mat_img.rows/2.0)); //旋转中心
    //旋转矩阵
    cv::Mat m1 = cv::getRotationMatrix2D(center, angle, 1.0);
    //m1为2行3列通道数为1的矩阵
    //变换矩阵的中心点相当于平移一样 原图像的中心点与新图像的中心点的相对位置
    m1.at<double>(0, 2) += (width_rotate - width) / 2.;
    m1.at<double>(1, 2) += (height_rotate - height) / 2.;

    if (mat_img.channels() == 1)
    {
        cv::warpAffine(mat_img, new_img, m1,cv::Size(width_rotate,height_rotate), cv::INTER_LINEAR, 0, cv::Scalar(255));
    }
    else if (mat_img.channels() == 3)
    {
        cv::warpAffine(mat_img, new_img, m1,cv::Size(width_rotate, height_rotate), cv::INTER_LINEAR, 0, cv::Scalar(255, 255, 255));
    }
    return new_img;
}

cv::Mat invertColors(cv::Mat mat_img)
{
    cv::Mat invert_img = mat_img;
    if(mat_img.channels() != 1)//彩色图像
    {
        std::vector<cv::Mat> mv;
        split(mat_img, mv);//彩色图像RGB通道分离
        //彩色图像反转
        //算法：反转后的像素a = 255 - a
        for (int i = 0; i < mat_img.rows; i++)//遍历高度
        {
            for (int j = 0; j < mat_img.cols; j++)//遍历宽度
            {
                mv[0].at<uchar>(i,j) = 255 - mv[0].at<uchar>(i,j);//像素点反转
                mv[1].at<uchar>(i,j) = 255 - mv[1].at<uchar>(i,j);//像素点反转
                mv[2].at<uchar>(i,j) = 255 - mv[2].at<uchar>(i,j);//像素点反转
            }
        }
        merge(mv, invert_img);//三通道合并成为彩色图像
    }
    else//灰度图像
    {
        //算法：反转后的像素a = 255 - a
        for (int i = 0; i < mat_img.rows; i++)
        {
            for (int j = 0; j < mat_img.cols; j++)
            {
                invert_img.at<uchar>(i, j) = 255 - mat_img.at<uchar>(i, j);   //对每一个像素反转
            }
        }
    }
    return invert_img;
}

cv::Mat grayscale(cv::Mat mat_img)
{
    cv::Mat gray_img=mat_img;
    if(mat_img.channels()!=1){//判断是否为彩色图像
        cv::cvtColor(mat_img, gray_img, cv::COLOR_BGR2GRAY);//彩色图像转灰度图像
    }
    return gray_img;
}

cv::Mat binarization(cv::Mat mat_img, int value)
{
    //二进制阈值化
    cv::Mat bin_img;
    cv::threshold(mat_img, bin_img, value, 255, cv::THRESH_BINARY);//二值化函数
    return bin_img;
}

cv::Mat flips(cv::Mat mat_img, int flipcode)//0：上下翻转；1：左右翻转；-1：上下翻转且左右翻转
{
    cv::Mat flip_img;
    cv::flip(mat_img, flip_img, flipcode);
    return flip_img;
}

cv::Mat biliner_size(cv::Mat mat_img, double sx, double sy)
{
    cv::Mat res_img;

    int dst_rows = round(mat_img.rows * sy);//把一个小数四舍五入 height
    int dst_cols = round(mat_img.cols * sx); //width

    res_img = cv::Mat(dst_rows, dst_cols, mat_img.type());
    for (int i = 0; i < res_img.rows; i++)
    {
        //几何中心对齐
        double index_i = i / sy ;
        //防止越界
        if (index_i < 0) index_i = 0;
        if (index_i >= mat_img.rows - 1) index_i = mat_img.rows - 2;
        //相邻2*2像素的行（坐标）
        int i1 = floor(index_i);//把一个小数向下取整 2.2==2
        int i2 = ceil(index_i);//把一个小数向上取整  2.2==3
        //u为得到浮点型坐标行的小数部分
        double u = index_i - i1;
        for (int j = 0; j < res_img.cols; j++)
        {
            //几何中心对齐
            double index_j = j / sx;
            //防止越界
            if (index_j < 0) index_j = 0;
            if (index_j >= mat_img.cols - 1) index_j = mat_img.cols - 2;
            //相邻2*2像素的列（坐标）
            int j1 = floor(index_j);
            int j2 = ceil(index_j);
            //v为得到浮点型坐标列的小数部分
            double v = index_j - j1;
            if (mat_img.channels() == 1)
            {
                //灰度图像
                res_img.at<uchar>(i, j) = (1 - u)*(1 - v)*mat_img.at<uchar>(i1, j1) + (1 - u)*v*mat_img.at<uchar>(i1, j2) + u*(1 - v)*mat_img.at<uchar>(i2, j1) + u*v*mat_img.at<uchar>(i2, j2);
            }
            else
            {
                //彩色图像
                res_img.at<cv::Vec3b>(i, j)[0] = (1 - u)*(1 - v)*mat_img.at<cv::Vec3b>(i1, j1)[0] + (1 - u)*v*mat_img.at<cv::Vec3b>(i1, j2)[0] + u*(1 - v)*mat_img.at<cv::Vec3b>(i2, j1)[0] + u*v*mat_img.at<cv::Vec3b>(i2, j2)[0];
                res_img.at<cv::Vec3b>(i, j)[1] = (1 - u)*(1 - v)*mat_img.at<cv::Vec3b>(i1, j1)[1] + (1 - u)*v*mat_img.at<cv::Vec3b>(i1, j2)[1] + u*(1 - v)*mat_img.at<cv::Vec3b>(i2, j1)[1] + u*v*mat_img.at<cv::Vec3b>(i2, j2)[1];
                res_img.at<cv::Vec3b>(i, j)[2] = (1 - u)*(1 - v)*mat_img.at<cv::Vec3b>(i1, j1)[2] + (1 - u)*v*mat_img.at<cv::Vec3b>(i1, j2)[2] + u*(1 - v)*mat_img.at<cv::Vec3b>(i2, j1)[2] + u*v*mat_img.at<cv::Vec3b>(i2, j2)[2];
            }
        }
    }
    return res_img;
}

cv::Mat bevel(cv::Mat mat_img, float angle1, float angle2)
{
    cv::Mat res_img;
    int move1 = 0, move2 = 0;
    int dst_rows = round(mat_img.rows + abs(mat_img.cols * tan(angle2 * CV_PI / 180)));//把一个小数四舍五入 height
    int dst_cols = round(mat_img.cols + abs(mat_img.rows * tan(angle1 * CV_PI / 180))); //width
    if(angle1 < 0){
        move1 = abs(mat_img.rows * tan(angle1 * CV_PI / 180));
    }
    if(angle2 < 0){
        move2 = abs(mat_img.cols * tan(angle2 * CV_PI / 180));
    }
    res_img = cv::Mat(dst_rows, dst_cols, mat_img.type());
    for (int i = 0; i < res_img.rows; i++)
    {
        for (int j = 0; j < res_img.cols; j++)
        {

            double index_i = i - move2 - j * tan(angle2 * CV_PI / 180);
            //防止越界
            if ( (index_i < 0) || (index_i >= mat_img.rows - 1) )
            {
                if (mat_img.channels() == 1)
                {
                    //灰度图像
                    res_img.at<uchar>(i, j) = 255;
                }
                else
                {
                    //彩色图像
                    res_img.at<cv::Vec3b>(i, j)[0] = 0;
                    res_img.at<cv::Vec3b>(i, j)[1] = 0;
                    res_img.at<cv::Vec3b>(i, j)[2] = 0;
                }
                continue;
            }
            //相邻2*2像素的行（坐标）
            int i1 = floor(index_i);//把一个小数向下取整 2.2==2
            int i2 = ceil(index_i);//把一个小数向上取整  2.2==3
            //u为得到浮点型坐标行的小数部分
            double u = index_i - i1;

            double index_j = j - move1 - i * tan(angle1 * CV_PI / 180);
            //防止越界
            if ( (index_j < 0) || (index_j >= mat_img.cols - 1))
            {
                if (mat_img.channels() == 1)
                {
                    //灰度图像
                    res_img.at<uchar>(i, j) = 255;
                }
                else
                {
                    //彩色图像
                    res_img.at<cv::Vec3b>(i, j)[0] = 0;
                    res_img.at<cv::Vec3b>(i, j)[1] = 0;
                    res_img.at<cv::Vec3b>(i, j)[2] = 0;
                }
                continue;
            }

            //相邻2*2像素的列（坐标）
            int j1 = floor(index_j);
            int j2 = ceil(index_j);
            //v为得到浮点型坐标列的小数部分
            double v = index_j - j1;
            if (mat_img.channels() == 1)
            {
                //灰度图像
                res_img.at<uchar>(i, j) = (1 - u)*(1 - v)*mat_img.at<uchar>(i1, j1) + (1 - u)*v*mat_img.at<uchar>(i1, j2) + u*(1 - v)*mat_img.at<uchar>(i2, j1) + u*v*mat_img.at<uchar>(i2, j2);
            }
            else
            {
                //彩色图像
                res_img.at<cv::Vec3b>(i, j)[0] = (1 - u)*(1 - v)*mat_img.at<cv::Vec3b>(i1, j1)[0] + (1 - u)*v*mat_img.at<cv::Vec3b>(i1, j2)[0] + u*(1 - v)*mat_img.at<cv::Vec3b>(i2, j1)[0] + u*v*mat_img.at<cv::Vec3b>(i2, j2)[0];
                res_img.at<cv::Vec3b>(i, j)[1] = (1 - u)*(1 - v)*mat_img.at<cv::Vec3b>(i1, j1)[1] + (1 - u)*v*mat_img.at<cv::Vec3b>(i1, j2)[1] + u*(1 - v)*mat_img.at<cv::Vec3b>(i2, j1)[1] + u*v*mat_img.at<cv::Vec3b>(i2, j2)[1];
                res_img.at<cv::Vec3b>(i, j)[2] = (1 - u)*(1 - v)*mat_img.at<cv::Vec3b>(i1, j1)[2] + (1 - u)*v*mat_img.at<cv::Vec3b>(i1, j2)[2] + u*(1 - v)*mat_img.at<cv::Vec3b>(i2, j1)[2] + u*v*mat_img.at<cv::Vec3b>(i2, j2)[2];
            }
        }
    }

    return res_img;
}

cv::Mat perspective(cv::Mat mat_img, cv::Mat perspectiveMatrix,cv::Size outputSize)
{
   // 创建目标图像
   cv::Mat outputImage(outputSize, mat_img.type(), cv::Scalar(0, 0, 0));

   // 获取透视变换矩阵的逆矩阵
   cv::Mat inversePerspectiveMatrix;
   invert(perspectiveMatrix, inversePerspectiveMatrix);

   // 循环遍历目标图像的每个像素
   for (int y = 0; y < outputSize.height; y++) {
       for (int x = 0; x < outputSize.width; x++) {
           // 计算在输入图像中的坐标
           cv::Mat inputCoordinates = (cv::Mat_<double>(3, 1) << x, y, 1);
           cv::Mat transformedCoordinates = inversePerspectiveMatrix * inputCoordinates;

           double inputX = transformedCoordinates.at<double>(0, 0) / transformedCoordinates.at<double>(2, 0);
           double inputY = transformedCoordinates.at<double>(1, 0) / transformedCoordinates.at<double>(2, 0);

           // 使用双线性插值计算插值像素值
           if (inputX >= 0 && inputX < mat_img.cols - 1 && inputY >= 0 && inputY < mat_img.rows - 1) {
               int x1 = floor(inputX);
               int x2 = x1 + 1;
               int y1 = floor(inputY);
               int y2 = y1 + 1;

               double deltaX = inputX - x1;
               double deltaY = inputY - y1;

               cv::Vec3b Q11 = mat_img.at<cv::Vec3b>(y1, x1);
               cv::Vec3b Q12 = mat_img.at<cv::Vec3b>(y2, x1);
               cv::Vec3b Q21 = mat_img.at<cv::Vec3b>(y1, x2);
               cv::Vec3b Q22 = mat_img.at<cv::Vec3b>(y2, x2);

               cv::Vec3b interpolatedValue;
               for (int c = 0; c < 3; c++) {
                   interpolatedValue[c] = (1 - deltaX) * (1 - deltaY) * Q11[c] +
                                          deltaX * (1 - deltaY) * Q21[c] +
                                          (1 - deltaX) * deltaY * Q12[c] +
                                          deltaX * deltaY * Q22[c];
               }

               outputImage.at<cv::Vec3b>(y, x) = interpolatedValue;
           }
       }
   }
   return outputImage;
}

// 自定义函数，计算图像的灰度直方图
std::vector<int> calculateHistogram(cv::Mat& inputImage) {
    if(inputImage.channels()!=1){//判断是否为彩色图像
        cv::cvtColor(inputImage, inputImage, cv::COLOR_BGR2GRAY);//彩色图像转灰度图像
    }

    std::vector<int> histogram(256, 0); // 初始化直方图，包括256个灰度级别，每个初始计数为0

    // 遍历图像的每个像素并增加相应灰度级别的计数
    for (int y = 0; y < inputImage.rows; y++) {
        for (int x = 0; x < inputImage.cols; x++) {
            uchar pixelValue = inputImage.at<uchar>(y, x);
            histogram[pixelValue]++;
        }
    }
    return histogram;
}

// 自定义函数，绘制直方图
cv::Mat drawHistogram(const std::vector<int>& histogram) {
    int histWidth = 512;
    int histHeight = 400;
    cv::Mat histImage(histHeight, histWidth, CV_8UC3, cv::Scalar(255, 255, 255));

    int binWidth = cvRound((double)histWidth / histogram.size());
    for (int i = 0; i < histogram.size(); i++) {
        cv::line(histImage,
                 cv::Point(binWidth * i, histHeight),
                 cv::Point(binWidth * i, histHeight - cvRound((double)histogram[i] / histImage.total() * histHeight)),
                 cv::Scalar(0, 0, 0), 1, 8, 0);
    }

    return histImage;
}

// 自定义函数，执行直方图均衡化
cv::Mat grayHistogram(cv::Mat mat_img) {
    // 计算灰度直方图
    std::vector<int> grayHistogram = calculateHistogram(mat_img);
    // 计算累积直方图
    std::vector<int> cumulativeHistogram(256, 0);
    cumulativeHistogram[0] = grayHistogram[0];
    for (int i = 1; i < 256; i++) {
        cumulativeHistogram[i] = cumulativeHistogram[i - 1] + grayHistogram[i];
    }

    // 归一化累积直方图
    int totalPixels = mat_img.rows * mat_img.cols;
    std::vector<int> normalizedCumulativeHistogram(256, 0);
    for (int i = 0; i < 256; i++) {
        normalizedCumulativeHistogram[i] = cvRound((cumulativeHistogram[i] * 255.0) / totalPixels);
    }

    // 创建均衡化后的图像
    cv::Mat equalizedImage = mat_img.clone();
    for (int y = 0; y < mat_img.rows; y++) {
        for (int x = 0; x < mat_img.cols; x++) {
            uchar pixelValue = mat_img.at<uchar>(y, x);
            uchar equalizedValue = static_cast<uchar>(normalizedCumulativeHistogram[pixelValue]);
            equalizedImage.at<uchar>(y, x) = equalizedValue;
        }
    }
    return equalizedImage;
}


cv::Mat medianFilter(const cv::Mat &inputImage, int kernelSize)
{
    cv::Mat outputImage = inputImage.clone();
    int radius = kernelSize / 2;

    for (int y = radius; y < inputImage.rows - radius; y++) {
        for (int x = radius; x < inputImage.cols - radius; x++) {
            std::vector<uchar> values;

            // 收集像素值
            for (int i = -radius; i <= radius; i++) {
                for (int j = -radius; j <= radius; j++) {
                    values.push_back(inputImage.at<uchar>(y + i, x + j));
                }
            }

            // 对值进行排序并取中值
            std::sort(values.begin(), values.end());
            uchar medianValue = values[kernelSize * kernelSize / 2];

            // 更新输出图像
            outputImage.at<uchar>(y, x) = medianValue;
        }
    }

    return outputImage;
}

void addSaltAndPepperNoise(cv::Mat &image, double noiseRatio)
{
    int rows = image.rows;
    int cols = image.cols;
    int numPixels = rows * cols;
    int numNoisePixels = static_cast<int>(numPixels * noiseRatio);

    // 设置随机种子
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    for (int i = 0; i < numNoisePixels; i++) {
        int x = std::rand() % cols;
        int y = std::rand() % rows;
        if (std::rand() % 2 == 0) {
            // 设置为白色噪声
            image.at<uchar>(y, x) = 255;
        } else {
            // 设置为黑色噪声
            image.at<uchar>(y, x) = 0;
        }
    }
}

cv::Mat applyRobertOperator(const cv::Mat &inputImage)
{
    cv::Mat outputImage = inputImage.clone();

    int kernelX[3][3] = { {1, 0, 0}, {0, -1, 0}, {0, 0, 0} };
    int kernelY[3][3] = { {0, 0, 0}, {0, -1, 0}, {0, 0, 1} };

    cv::Mat gradientX, gradientY;
    cv::filter2D(inputImage, gradientX, -1, cv::Mat(3, 3, CV_32S, kernelX));
    cv::filter2D(inputImage, gradientY, -1, cv::Mat(3, 3, CV_32S, kernelY));

    cv::add(gradientX, gradientY, outputImage);

    return outputImage;
}

cv::Mat applySobelOperator(const cv::Mat &inputImage)
{
    cv::Mat outputImage = inputImage.clone();

    cv::Mat gradientX, gradientY;
    cv::Sobel(inputImage, gradientX, -1, 1, 0);
    cv::Sobel(inputImage, gradientY, -1, 0, 1);

    cv::add(gradientX, gradientY, outputImage);

    return outputImage;
}

cv::Mat applyLaplaceOperator(const cv::Mat &inputImage)
{
    // 自定义拉普拉斯锐化算子
    cv::Mat laplacianKernel = (cv::Mat_<char>(3,3)<<0,-1,0,-1,4,-1,0,-1,0);
//    cv::Mat outputImage = inputImage.clone();

    // 应用自定义卷积核（算子）
    cv::Mat laplacianResponse;
    cv::filter2D(inputImage, laplacianResponse, -1, laplacianKernel);

    // 增强图像的边缘
//    cv::add(inputImage, laplacianResponse, outputImage);

    return laplacianResponse;
}


cv::Mat DomainLowPassFilter(const cv::Mat &inputImage, double cutoffFrequency)
{
    cv::Mat padded; // 填充后的图像
    int m = cv::getOptimalDFTSize(inputImage.rows);
    int n = cv::getOptimalDFTSize(inputImage.cols);

    // 填充输入图像
    cv::copyMakeBorder(inputImage, padded, 0, m - inputImage.rows, 0, n - inputImage.cols, cv::BORDER_CONSTANT, cv::Scalar::all(0));

    // 创建复数输入图像
    cv::Mat planes[] = {cv::Mat_<float>(padded), cv::Mat::zeros(padded.size(), CV_32F)};
    cv::Mat complexImage;
    cv::merge(planes, 2, complexImage);

    // 执行傅里叶变换
    cv::dft(complexImage, complexImage);

    // 创建频域低通滤波器
    cv::Mat lowPassFilter = cv::Mat::zeros(padded.size(), CV_32F);
    cv::Point center = cv::Point(padded.cols / 2, padded.rows / 2);

    for (int i = 0; i < padded.rows; i++) {
        for (int j = 0; j < padded.cols; j++) {
            double distance = std::sqrt((i - center.y) * (i - center.y) + (j - center.x) * (j - center.x));
            if (distance <= cutoffFrequency) {
                lowPassFilter.at<float>(i, j) = 1.0;
            }
        }
    }

    // 应用低通滤波器
    cv::Mat filteredImage;
    cv::mulSpectrums(complexImage, lowPassFilter, filteredImage, 0);

    // 执行逆傅里叶变换
    cv::dft(filteredImage, filteredImage, cv::DFT_INVERSE | cv::DFT_SCALE);

    // 分离实部
    cv::split(filteredImage, planes);

    // 返回低通滤波结果
    return planes[0];
}

cv::Mat DomainHighPassFilter(const cv::Mat &inputImage, double cutoffFrequency)
{
    // 使用低通滤波器和频域图像反转来实现高通滤波
    cv::Mat lowPass = DomainLowPassFilter(inputImage, cutoffFrequency);
    cv::Mat highPass = inputImage - lowPass;

    return highPass;
}

cv::Mat dualThresholds(const cv::Mat &inputImage, double threshold1, double threshold2)
{
    cv::Mat segmentedImage = inputImage.clone();

    for (int i = 0; i < inputImage.rows; i++) {
        for (int j = 0; j < inputImage.cols; j++) {
            uchar pixelValue = inputImage.at<uchar>(i, j);
            segmentedImage.at<uchar>(i, j) = 255;
            if (pixelValue < threshold1) {
                segmentedImage.at<uchar>(i, j) = 0;
            }
            if (pixelValue > threshold2) {
                segmentedImage.at<uchar>(i, j) = 0;
            }
        }
    }

    return segmentedImage;
}

cv::Mat regionGrowing(const cv::Mat &inputImage, cv::Point seedPoint, int similarityThreshold)
{
    cv::Mat outputImage = cv::Mat::zeros(inputImage.size(), CV_8UC1);    //生长区域
    cv::Size imageSize = inputImage.size();
    std::stack<cv::Point> pointsStack;
    pointsStack.push(seedPoint);

    // 获取种子点的像素值
    int seedPixelValue = inputImage.at<uchar>(seedPoint);

    while (!pointsStack.empty()) {
        cv::Point currentPoint = pointsStack.top();
        pointsStack.pop();

        // 如果当前点未被访问过且像素值与种子点相似，则将其标记为已访问
        if (outputImage.at<uchar>(currentPoint) == 0 && std::abs(inputImage.at<uchar>(currentPoint) - seedPixelValue) <= similarityThreshold) {
            outputImage.at<uchar>(currentPoint) = 255; // 设置为白色
            // 将当前点的邻居点入栈
            if (currentPoint.x > 0) {
                pointsStack.push(cv::Point(currentPoint.x - 1, currentPoint.y));
            }
            if (currentPoint.x < imageSize.width - 1) {
                pointsStack.push(cv::Point(currentPoint.x + 1, currentPoint.y));
            }
            if (currentPoint.y > 0) {
                pointsStack.push(cv::Point(currentPoint.x, currentPoint.y - 1));
            }
            if (currentPoint.y < imageSize.height - 1) {
                pointsStack.push(cv::Point(currentPoint.x, currentPoint.y + 1));
            }
        }
    }
    return outputImage;
}

cv::Mat watershed(const cv::Mat &inputImage, int value)
{
    // 1. 灰度化和二值化得到二值图像
    cv::Mat grayImage;
    cv::cvtColor(inputImage, grayImage, cv::COLOR_BGR2GRAY);

    cv::Mat binaryImage;
    cv::threshold(grayImage, binaryImage, value, 255, cv::THRESH_BINARY_INV | cv::THRESH_OTSU);
    // 2. 通过膨胀得到确定的背景区域，通过距离变换得到确定的前景区域
    cv::Mat sureBackground;
    cv::dilate(binaryImage, sureBackground, cv::Mat(), cv::Point(-1, -1), 3);

    cv::Mat distanceTransform;
    cv::distanceTransform(binaryImage, distanceTransform, cv::DIST_L2, 5);

    double minVal, maxVal;
    cv::Point minLoc, maxLoc;
    cv::minMaxLoc(distanceTransform, &minVal, &maxVal, &minLoc, &maxLoc);

    double thresholdValue = (value/255.0) * maxVal;
    cv::Mat sureForeground;
    cv::threshold(distanceTransform, sureForeground, thresholdValue, 255, cv::THRESH_BINARY);
    sureForeground.convertTo(sureForeground, CV_8U);

    // 3. 对确定的前景图像进行连接组件处理，得到标记图像
    cv::Mat markers;
    cv::connectedComponents(sureForeground, markers, 4, CV_32S);

    // 4. 根据标记图像对原图像应用分水岭算法，更新标记图像
    cv::watershed(inputImage, markers);

    // 绘制分割结果
    cv::Mat outputImage = cv::Mat::zeros(inputImage.size(), CV_8UC3);
    for (int i = 0; i < markers.rows; ++i) {
        for (int j = 0; j < markers.cols; ++j) {
            int marker = markers.at<int>(i, j);
            if (marker == -1){
//                outputImage.at<cv::Vec3b>(i, j) = cv::Vec3b(255, 0, 0); // 分割线
                // 加粗分割线
                cv::circle(outputImage, cv::Point(j, i), 2, cv::Scalar(255, 0, 0), -1);
            }
            else if (marker > 0)
                outputImage.at<cv::Vec3b>(i, j) = inputImage.at<cv::Vec3b>(i, j); // 标记区域保持原始颜色
        }
    }
    return outputImage;
}
