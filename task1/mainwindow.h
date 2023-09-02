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

private:
    Ui::MainWindow *ui;
    ImageWidget *m_Image;

};
#endif // MAINWINDOW_H
