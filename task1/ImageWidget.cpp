#include "ImageWidget.h"
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <QPointF>
#include <QGraphicsSceneDragDropEvent>
#include <QDrag>
#include <math.h>

extern cv::Mat img_src,mat_img;

ImageWidget::ImageWidget(QPixmap *pixmap)
{
    m_pix = *pixmap;
    setAcceptDrops(true);//If enabled is true, this item will accept hover events; otherwise, it will ignore them. By default, items do not accept hover events.
    m_scaleValue = 0;
    m_scaleDafault = 1;
    m_isMove = false;
}

QRectF ImageWidget::boundingRect() const
{
    return QRectF(-m_pix.width() / 2, -m_pix.height() / 2,
                  m_pix.width(), m_pix.height());
}

void ImageWidget::paint(QPainter *painter, const QStyleOptionGraphicsItem *,
                    QWidget *)
{
    painter->drawPixmap(-m_pix.width() / 2, -m_pix.height() / 2, m_pix);
}


void ImageWidget::mousePressEvent(QGraphicsSceneMouseEvent *event)//点击鼠标事件
{
    if(event->button()== Qt::LeftButton)
    {
        m_startPos = event->pos();//鼠标左击时，获取当前鼠标在图片中的坐标，
        m_isMove = true;//标记鼠标左键被按下
    }
    else if(event->button() == Qt::RightButton)
    {
        ResetItemPos();//右击鼠标重置大小
    }

}

void ImageWidget::mouseMoveEvent(QGraphicsSceneMouseEvent *event)//鼠标移动事件
{
    if(m_isMove)
    {
        QPointF point = (event->pos() - m_startPos)*m_scaleValue;
        moveBy(point.x(), point.y());
    }
}

void ImageWidget::mouseReleaseEvent(QGraphicsSceneMouseEvent *)//左键释放
{
    m_isMove = false;//标记鼠标左键已经抬起
}


void ImageWidget::wheelEvent(QGraphicsSceneWheelEvent *event)//鼠标滚轮事件
{
    if((event->delta() > 0)&&(m_scaleValue >= 10))//最大放大到原始图像的10倍
    {
        return;
    }
    else if((event->delta() < 0)&&(m_scaleValue <= m_scaleDafault*0.1))//图像缩小到0.1倍大小之后就不继续缩小
    {
        return;
    }
    else
    {
        qreal qrealOriginScale = m_scaleValue;
        if(event->delta() > 0)//鼠标滚轮向前滚动
        {
            m_scaleValue*=1.1;//每次放大10%
        }
        else
        {
            m_scaleValue*=0.9;//每次缩小10%
        }
        setScale(m_scaleValue);//缩放
        if(event->delta() > 0)
        {
            moveBy(-event->pos().x()*qrealOriginScale*0.1, -event->pos().y()*qrealOriginScale*0.1);//使图片缩放的效果看起来像是以鼠标所在点为中心进行缩放的
        }
        else
        {
            moveBy(event->pos().x()*qrealOriginScale*0.1, event->pos().y()*qrealOriginScale*0.1);//使图片缩放的效果看起来像是以鼠标所在点为中心进行缩放的
        }
    }
}

void ImageWidget::setQGraphicsViewWH(int nwidth, int nheight)//将主界面的控件QGraphicsView的width和height传进本类中，并根据图像的长宽和控件的长宽的比例来使图片缩放到适合控件的大小
{
    int nImgWidth = m_pix.width();
    int nImgHeight = m_pix.height();
    qreal temp1 = nwidth*1.0/nImgWidth;
    qreal temp2 = nheight*1.0/nImgHeight;
    if(temp1>temp2)
    {
        m_scaleDafault = temp2;
    }
    else
    {
        m_scaleDafault = temp1;
    }
    setScale(m_scaleDafault);
    m_scaleValue = m_scaleDafault;
}

void ImageWidget::ResetItemPos()//重置图片位置
{
    m_scaleValue = m_scaleDafault;//缩放比例回到原比例
    setScale(m_scaleDafault);//回到原比例
    setPos(0,0);
}

void ImageWidget::upd()
{
    setScale(m_scaleValue);
}

qreal ImageWidget::getScaleValue() const
{
    return m_scaleValue;
}


QImage cvMat2QImage(cv::Mat& m)
{
    switch (m.type()) {    //判断Mat的类型，从而返回不同类型的img
        case CV_8UC1:{
            // 通过QImage::QImage(uchar *data, int width, int height, int bytesPerLine,
             // QImage::Format format, QImageCleanupFunction cleanupFunction = nullptr,
             //void *cleanupInfo = nullptr)，主要修改后两个非默认的参数
            QImage img((uchar*)m.data,m.cols,m.rows,m.cols*1,QImage::Format_Grayscale8);
            return img;
        }
        case CV_8UC3:{
            QImage img((uchar*)m.data,m.cols,m.rows,m.cols*3,QImage::Format_RGB888);
            return img.rgbSwapped();
        }
        case CV_8UC4:{
            QImage img((uchar*)m.data,m.cols,m.rows,m.cols*4,QImage::Format_ARGB32);
            return img;
        }
        default:{
            QImage img;
            return img;
        }
    }
}
