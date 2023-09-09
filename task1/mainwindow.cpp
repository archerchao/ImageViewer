#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QDebug>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <string.h>
#include "imgprocess.h"
#include "opencv_deal.h"
#include <QAction>

using namespace cv;
using namespace std;
QString img_path;
QImage img;
cv::Mat img_src,mat_img;
float rotate_angle = 0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)//在
{
    ui->setupUi(this);

    void (QAction::*zoomsignal)(bool) = &QAction::triggered;	// zoomsignal指向带参的信号
    connect(ui->zoomin,zoomsignal,this,[=](){
        qDebug()<<"zoomin";
        mat_img = biliner_size(mat_img,1.1,1.1);
        QImage qimg = cvMat2QImage(mat_img);//Mat转QImage
        m_Image->m_pix = QPixmap::fromImage(qimg);//QImage转QPixma
        m_Image->upd();//更新显示
    });

    void (QAction::*bevelsignal)(bool) = &QAction::triggered;
    connect(ui->bevel,bevelsignal,this,[=](){
        qDebug()<<"bevelsignal";
        mat_img = bevel(mat_img,20,-30);
        QImage qimg = cvMat2QImage(mat_img);//Mat转QImage
        m_Image->m_pix = QPixmap::fromImage(qimg);//QImage转QPixma
        m_Image->upd();//更新显示
    });

    void (QAction::*perspectivesignal)(bool) = &QAction::triggered;
    connect(ui->perspective,perspectivesignal,this,[=](){
        qDebug()<<"perspectivesignal";

        // 定义透视变换的四个源点坐标
        std::vector<cv::Point2f> srcPoints;
        srcPoints.push_back(cv::Point2f(0, 0));   // 左上角
        srcPoints.push_back(cv::Point2f(mat_img.cols, 0));  // 右上角
        srcPoints.push_back(cv::Point2f(0, mat_img.rows));  // 左下角
        srcPoints.push_back(cv::Point2f(mat_img.cols, mat_img.rows)); // 右下角
        // 定义透视变换后的四个目标点坐标
        std::vector<cv::Point2f> dstPoints;
        dstPoints.push_back(cv::Point2f(100, 100));
        dstPoints.push_back(cv::Point2f(mat_img.cols-100, 100));
        dstPoints.push_back(cv::Point2f(0, mat_img.rows));
        dstPoints.push_back(cv::Point2f(mat_img.cols, mat_img.rows));
        // 计算透视变换矩阵
        cv::Mat perspectiveMatrix = findHomography(srcPoints, dstPoints, CV_RANSAC);
        // 透视转换
        mat_img = perspective(mat_img, perspectiveMatrix, mat_img.size());

        QImage qimg = cvMat2QImage(mat_img);//Mat转QImage
        m_Image->m_pix = QPixmap::fromImage(qimg);//QImage转QPixma
        m_Image->upd();//更新显示
    });

    void (QAction::*histogramsignal)(bool) = &QAction::triggered;
    connect(ui->histogram,histogramsignal,this,[=](){
        qDebug()<<"histogramsignal";
        mat_img = grayscale(mat_img);
        // 计算原始图像的直方图
        std::vector<int> originalHistogram = calculateHistogram(mat_img);
        cv::Mat originalHistImage = drawHistogram(originalHistogram);
        cv::imshow("原直方图", originalHistImage);

        QImage qimg = cvMat2QImage(mat_img);//Mat转QImage
        m_Image->m_pix = QPixmap::fromImage(qimg);//QImage转QPixma
        m_Image->upd();//更新显示
    });


    void (QAction::*equHistogramsignal)(bool) = &QAction::triggered;
    connect(ui->equHistogram,equHistogramsignal,this,[=](){
        qDebug()<<"equHistogramsignal";
        mat_img = grayscale(mat_img);
        // 计算原始图像的直方图
        std::vector<int> originalHistogram = calculateHistogram(mat_img);
        cv::Mat originalHistImage = drawHistogram(originalHistogram);
        cv::imshow("原直方图", originalHistImage);
        mat_img = grayHistogram(mat_img);
        // 计算原始图像的直方图
        std::vector<int> equHistogram = calculateHistogram(mat_img);
        cv::Mat equHistImage = drawHistogram(equHistogram);
        cv::imshow("均衡直方图", equHistImage);

        QImage qimg = cvMat2QImage(mat_img);//Mat转QImage
        m_Image->m_pix = QPixmap::fromImage(qimg);//QImage转QPixma
        m_Image->upd();//更新显示
    });


    void (QAction::*medianFiltersignal)(bool) = &QAction::triggered;
    connect(ui->medianFilter,medianFiltersignal,this,[=](){
        qDebug()<<"medianFiltersignal";
        mat_img = grayscale(mat_img);
        // 复制原始图像以进行去噪处理
        cv::Mat noisyImage = mat_img.clone();
        // 添加椒盐噪声
        double noiseRatio = 0.1; // 噪声比例
        addSaltAndPepperNoise(noisyImage, noiseRatio);
        // 调用自定义中值滤波函数进行去噪处理
        int kernelSize = 3; // 中值滤波核大小（奇数）
        cv::Mat denoisedImage = medianFilter(noisyImage, kernelSize);
        // 显示原始图像、带噪声的图像和去噪后的图像
        cv::namedWindow("原始图像", cv::WINDOW_NORMAL);
        cv::namedWindow("带噪声的图像", cv::WINDOW_NORMAL);
        cv::imshow("原始图像", mat_img);
        cv::imshow("带噪声的图像", noisyImage);

        QImage qimg = cvMat2QImage(denoisedImage);//Mat转QImage
        m_Image->m_pix = QPixmap::fromImage(qimg);//QImage转QPixma
        m_Image->upd();//更新显示
    });


    void (QAction::*robertsignal)(bool) = &QAction::triggered;
    connect(ui->robert,robertsignal,this,[=](){
        qDebug()<<"robertsignal";
        mat_img = grayscale(img_src);
        cv::namedWindow("原始图像", cv::WINDOW_NORMAL);
        cv::imshow("原始图像", mat_img);
        mat_img = applyRobertOperator(mat_img);

        QImage qimg = cvMat2QImage(mat_img);//Mat转QImage
        m_Image->m_pix = QPixmap::fromImage(qimg);//QImage转QPixma
        m_Image->upd();//更新显示
    });


    void (QAction::*sebelsignal)(bool) = &QAction::triggered;
    connect(ui->sebel,sebelsignal,this,[=](){
        qDebug()<<"sebelsignal";
        mat_img = grayscale(img_src);
        cv::namedWindow("原始图像", cv::WINDOW_NORMAL);
        cv::imshow("原始图像", mat_img);
        mat_img = applySobelOperator(mat_img);

        QImage qimg = cvMat2QImage(mat_img);//Mat转QImage
        m_Image->m_pix = QPixmap::fromImage(qimg);//QImage转QPixma
        m_Image->upd();//更新显示
    });


    void (QAction::*laplacesignal)(bool) = &QAction::triggered;
    connect(ui->laplace,laplacesignal,this,[=](){
        qDebug()<<"laplacesignal";
        mat_img = grayscale(img_src);
        cv::namedWindow("原始图像", cv::WINDOW_NORMAL);
        cv::imshow("原始图像", mat_img);
        mat_img = applyLaplaceOperator(mat_img);

        QImage qimg = cvMat2QImage(mat_img);//Mat转QImage
        m_Image->m_pix = QPixmap::fromImage(qimg);//QImage转QPixma
        m_Image->upd();//更新显示
    });


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::recvShowPicSignal(QImage image)
{
    QPixmap ConvertPixmap=QPixmap::fromImage(image);//The QPixmap class is an off-screen image representation that can be used as a paint device
    qgraphicsScene = new QGraphicsScene;//要用QGraphicsView就必须要有QGraphicsScene搭配着用
    m_Image = new ImageWidget(&ConvertPixmap);//实例化类ImageWidget的对象m_Image，该类继承自QGraphicsItem，是自己写的类
    int nwith = ui->graphicsView->width();//获取界面控件Graphics View的宽度
    int nheight = ui->graphicsView->height();//获取界面控件Graphics View的高度
    m_Image->setQGraphicsViewWH(nwith,nheight);//将界面控件Graphics View的width和height传进类m_Image中
    qgraphicsScene->addItem(m_Image);//将QGraphicsItem类对象放进QGraphicsScene中
    ui->graphicsView->setSceneRect(QRectF(-(nwith/2),-(nheight/2),nwith,nheight));//使视窗的大小固定在原始大小，不会随图片的放大而放大
    ui->graphicsView->setScene(qgraphicsScene);//Sets the current scene to scene. If scene is already being viewed, this function does nothing.
    ui->graphicsView->setFocus();//将界面的焦点设置到当前GraphicsView控件
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//取消水平滚动条
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//取消垂直滚动条
}

//读取图片并显示
void MainWindow::on_ReadPath_clicked()
{
    QString runPath = QCoreApplication::applicationDirPath();//获取项目的根路径
    img_path = QFileDialog::getOpenFileName(this,QStringLiteral("选择文件"),runPath,"Files(*.jpg *.png)",nullptr,QFileDialog::DontResolveSymlinks);
    qDebug()<<img_path;
    ui->textBrowser->setText(img_path);
    if(img_path == ""){
        std::cout << "无法读取图片" << std::endl;
    }
    else{
        std::cout << "图片读取成功" << std::endl;
    }
    img_src = cv::imread(img_path.toStdString());
    mat_img = img_src;
    img.load(img_path);

    recvShowPicSignal(img);
}

//旋转
void MainWindow::on_RotateSlider_valueChanged(int value)//旋转滑块回调函数
{
    ui->RotatespinBox->setValue(value);//设置旋转角度数字显示
//    ui->graphicsView->rotate(value - rotate_angle);
    mat_img = setMatAngle(img_src, (float)value);//旋转
    QImage qimg = cvMat2QImage(mat_img);//Mat转QImage
    m_Image->m_pix = QPixmap::fromImage(qimg);//QImage转QPixma
    m_Image->upd();//更新显示
//    rotate_angle = value;//记录当前旋转角度

}
void MainWindow::on_RotatespinBox_editingFinished()//旋转角度输入Box回调函数
{
    ui->RotateSlider->setValue(ui->RotatespinBox->value());//设置滑块值
}

//灰度化
void MainWindow::on_GrayBt_clicked()
{
    mat_img = grayscale(mat_img);
    QImage qimg = cvMat2QImage(mat_img);//Mat转QImage
    m_Image->m_pix = QPixmap::fromImage(qimg);//QImage转QPixma
    m_Image->upd();//更新显示
}

//二值化
void MainWindow::on_BinSlider_valueChanged(int value)//二值化滑块回调函数
{
    if(img_path != ""){//判断图片地址是否为空
        ui->BinspinBox->setValue(value);//设置二值化Box中的值
        cv::Mat bin_img;//二值化返回图像
        //二进制阈值化
        bin_img = binarization(mat_img, value);
        QImage qimg = cvMat2QImage(bin_img);//Mat转QImag
        m_Image->m_pix = QPixmap::fromImage(qimg);//QImage转QPixmap
        m_Image->upd();//显示更新
    }
}
void MainWindow::on_BinspinBox_editingFinished()//二值化Box输入回调函数
{
    ui->BinSlider->setValue(ui->BinspinBox->value());//设置滑块值
}

void MainWindow::on_resetBt_clicked()
{
    if(img_path != ""){
        mat_img = img_src;
        QImage qimg = cvMat2QImage(mat_img);
        m_Image->m_pix = QPixmap::fromImage(qimg);
        m_Image->upd();
    }
}

void MainWindow::on_InverseBt_clicked()
{
    if(img_path != ""){
        mat_img = invertColors(mat_img);
        QImage qimg = cvMat2QImage(mat_img);//Opencv图像格式Mat转为QImage
        m_Image->m_pix = QPixmap::fromImage(qimg);//QImage转为QPixmap传入视图框并显示
        m_Image->upd();//更新显示
    }
}

void MainWindow::on_SizeBt_clicked()
{
    if(img_path != ""){
        m_Image->m_scaleValue = 1;//缩放比例回到原比例
        m_Image->setScale(m_Image->m_scaleValue);//回到原比例
        m_Image->setPos(0,0);
    }
}

void MainWindow::on_updownBt_clicked()//上下翻转
{
    mat_img = flips(mat_img, 0);//0：上下翻转；1：左右翻转；-1：上下翻转且左右翻转
    QImage qimg = cvMat2QImage(mat_img);
    m_Image->m_pix = QPixmap::fromImage(qimg);
    m_Image->upd();
}
void MainWindow::on_leftrightBt_clicked()//左右翻转
{
    mat_img = flips(mat_img, 1);//0：上下翻转；1：左右翻转；-1：上下翻转且左右翻转
    QImage qimg = cvMat2QImage(mat_img);
    m_Image->m_pix = QPixmap::fromImage(qimg);
    m_Image->upd();
}

void MainWindow::on_testBt_clicked()
{
//    mat_img = bevel(mat_img,-10,-10);
//    QImage qimg = cvMat2QImage(mat_img);//Mat转QImage
//    m_Image->m_pix = QPixmap::fromImage(qimg);//QImage转QPixma
//    m_Image->upd();//更新显示


    // 设置低通滤波器参数（截止频率）
    double lowPassCutoffFrequency = 30.0;
    // 设置高通滤波器参数（截止频率）
    double highPassCutoffFrequency = 30.0;
    // 应用频域低通滤波
    cv::Mat lowPassResult = DomainLowPassFilter(mat_img, lowPassCutoffFrequency);
    // 应用频域高通滤波
    cv::Mat highPassResult = DomainHighPassFilter(mat_img, highPassCutoffFrequency);
    // 显示原始图像和频域滤波结果
    cv::namedWindow("原始图像", cv::WINDOW_NORMAL);
    cv::namedWindow("低通滤波结果", cv::WINDOW_NORMAL);
    cv::namedWindow("高通滤波结果", cv::WINDOW_NORMAL);
    cv::imshow("原始图像", mat_img);
    cv::imshow("低通滤波结果", lowPassResult);
    cv::imshow("高通滤波结果", highPassResult);


    QImage qimg = cvMat2QImage(mat_img);//Mat转QImage
    m_Image->m_pix = QPixmap::fromImage(qimg);//QImage转QPixma
    m_Image->upd();//更新显示

    qDebug()<<"test";
}
