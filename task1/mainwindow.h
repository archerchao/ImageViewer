#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ImageWidget.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void recvShowPicSignal(QImage image);//接收并显示图片的函数
private slots:
    void on_ReadPath_clicked();

    void on_RotateSlider_valueChanged(int value);

    void on_RotatespinBox_editingFinished();

    void on_GrayBt_clicked();

    void on_BinSlider_valueChanged(int value);

    void on_BinspinBox_editingFinished();

    void on_resetBt_clicked();

    void on_InverseBt_clicked();

    void on_SizeBt_clicked();

    void on_updownBt_clicked();

    void on_leftrightBt_clicked();

    void on_testBt_clicked();

    void on_threshold1Slider_valueChanged(int value);

    void on_threshold1spinBox_editingFinished();

    void on_threshold2Slider_valueChanged(int value);

    void on_threshold2spinBox_editingFinished();


    void on_growSlider_valueChanged(int value);

    void on_growspinBox_valueChanged(int arg1);

    void on_watershedSlider_valueChanged(int value);

    void on_watershedspinBox_valueChanged(int arg1);

    void on_pushButton_clicked();

    void on_canny1Slider_valueChanged(int value);

    void on_canny1spinBox_valueChanged(int arg1);

    void on_canny2Slider_valueChanged(int value);

    void on_canny2spinBox_valueChanged(int arg1);

    void on_HoughthresholdSlider_valueChanged(int value);

    void on_HoughthresholdspinBox_valueChanged(int arg1);

    void on_HoughminSlider_valueChanged(int value);

    void on_HoughminspinBox_valueChanged(int arg1);

private:
    Ui::MainWindow *ui;
    ImageWidget *m_Image;
    QGraphicsScene  *qgraphicsScene;

};
#endif // MAINWINDOW_H
