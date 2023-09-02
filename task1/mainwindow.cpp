#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QDebug>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <string.h>
#include "imgprocess.h"
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
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::recvShowPicSignal(QImage image)
{
    QPixmap ConvertPixmap=QPixmap::fromImage(image);//The QPixmap class is an off-screen image representation that can be used as a paint device
    QGraphicsScene  *qgraphicsScene = new QGraphicsScene;//要用QGraphicsView就必须要有QGraphicsScene搭配着用
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
    ui->graphicsView->rotate(value - rotate_angle);//旋转
    rotate_angle = value;//记录当前旋转角度
}
void MainWindow::on_RotatespinBox_editingFinished()//旋转角度输入Box回调函数
{
    ui->RotateSlider->setValue(ui->RotatespinBox->value());//设置滑块值
}

//灰度化
void MainWindow::on_GrayBt_clicked()
{
    if(mat_img.channels()!=1){//判断是否为彩色图像
        cv::cvtColor(mat_img, mat_img, COLOR_BGR2GRAY);//彩色图像转灰度图像
        QImage qimg = cvMat2QImage(mat_img);//Mat转QImage
        m_Image->m_pix = QPixmap::fromImage(qimg);//QImage转QPixma
        m_Image->upd();//更新显示
    }
}

//二值化
void MainWindow::on_BinSlider_valueChanged(int value)//二值化滑块回调函数
{
    if(img_path != ""){//判断图片地址是否为空
        ui->BinspinBox->setValue(value);//设置二值化Box中的值
        cv::Mat bin_img;//二值化返回图像
        //二进制阈值化
        cv::threshold(mat_img, bin_img, value, 255, cv::THRESH_BINARY);//二值化函数
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
        int i=0, j=0;
        if(mat_img.channels() != 1)//彩色图像
        {
            std::vector<Mat> mv;
            split(mat_img, mv);//彩色图像RGB通道分离
            //彩色图像反转
            //算法：反转后的像素a = 255 - a
            for (i = 0; i < mat_img.rows; i++)//遍历高度
            {
                for (j = 0; j < mat_img.cols; j++)//遍历宽度
                {
                    mv[0].at<uchar>(i,j) = 255 - mv[0].at<uchar>(i,j);//像素点反转
                    mv[1].at<uchar>(i,j) = 255 - mv[1].at<uchar>(i,j);//像素点反转
                    mv[2].at<uchar>(i,j) = 255 - mv[2].at<uchar>(i,j);//像素点反转
                }
            }
            merge(mv, mat_img);//三通道合并成为彩色图像
        }
        else//灰度图像
        {
            //算法：反转后的像素a = 255 - a
            for (i = 0; i < mat_img.rows; i++)
            {
                for (j = 0; j < mat_img.cols; j++)
                {
                    mat_img.at<uchar>(i, j) = 255 - mat_img.at<uchar>(i, j);   //对每一个像素反转
                }
            }
        }
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
    flip(mat_img, mat_img,0); //0：上下翻转；1：左右翻转；-1：上下翻转且左右翻转
    QImage qimg = cvMat2QImage(mat_img);
    m_Image->m_pix = QPixmap::fromImage(qimg);
    m_Image->upd();
}
void MainWindow::on_leftrightBt_clicked()//左右翻转
{
    flip(mat_img, mat_img,1); //0：上下翻转；1：左右翻转；-1：上下翻转且左右翻转
    QImage qimg = cvMat2QImage(mat_img);
    m_Image->m_pix = QPixmap::fromImage(qimg);
    m_Image->upd();
}
