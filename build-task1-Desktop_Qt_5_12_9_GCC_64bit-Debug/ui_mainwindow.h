/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QTextBrowser *textBrowser;
    QPushButton *ReadPath;
    QPushButton *resetBt;
    QGraphicsView *graphicsView;
    QLabel *label_2;
    QPushButton *InverseBt;
    QPushButton *GrayBt;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_4;
    QSlider *BinSlider;
    QSpinBox *BinspinBox;
    QLabel *label_3;
    QPushButton *SizeBt;
    QPushButton *updownBt;
    QPushButton *leftrightBt;
    QLabel *label;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_3;
    QSlider *RotateSlider;
    QSpinBox *RotatespinBox;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1100, 680);
        MainWindow->setMinimumSize(QSize(1100, 680));
        MainWindow->setMaximumSize(QSize(1100, 680));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 10, 801, 32));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        textBrowser = new QTextBrowser(layoutWidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setMinimumSize(QSize(550, 30));

        horizontalLayout->addWidget(textBrowser);

        ReadPath = new QPushButton(layoutWidget);
        ReadPath->setObjectName(QString::fromUtf8("ReadPath"));
        ReadPath->setMinimumSize(QSize(80, 30));

        horizontalLayout->addWidget(ReadPath);

        resetBt = new QPushButton(centralwidget);
        resetBt->setObjectName(QString::fromUtf8("resetBt"));
        resetBt->setGeometry(QRect(990, 530, 89, 25));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(20, 50, 800, 600));
        graphicsView->setMinimumSize(QSize(600, 600));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(850, 290, 67, 17));
        InverseBt = new QPushButton(centralwidget);
        InverseBt->setObjectName(QString::fromUtf8("InverseBt"));
        InverseBt->setGeometry(QRect(990, 470, 89, 25));
        GrayBt = new QPushButton(centralwidget);
        GrayBt->setObjectName(QString::fromUtf8("GrayBt"));
        GrayBt->setGeometry(QRect(850, 470, 89, 25));
        layoutWidget_2 = new QWidget(centralwidget);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(850, 390, 231, 28));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        BinSlider = new QSlider(layoutWidget_2);
        BinSlider->setObjectName(QString::fromUtf8("BinSlider"));
        BinSlider->setMaximum(255);
        BinSlider->setValue(100);
        BinSlider->setSliderPosition(100);
        BinSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(BinSlider);

        BinspinBox = new QSpinBox(layoutWidget_2);
        BinspinBox->setObjectName(QString::fromUtf8("BinspinBox"));
        BinspinBox->setMaximum(255);
        BinspinBox->setValue(100);

        horizontalLayout_4->addWidget(BinspinBox);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(850, 370, 67, 17));
        SizeBt = new QPushButton(centralwidget);
        SizeBt->setObjectName(QString::fromUtf8("SizeBt"));
        SizeBt->setGeometry(QRect(850, 530, 89, 25));
        updownBt = new QPushButton(centralwidget);
        updownBt->setObjectName(QString::fromUtf8("updownBt"));
        updownBt->setGeometry(QRect(850, 590, 89, 30));
        leftrightBt = new QPushButton(centralwidget);
        leftrightBt->setObjectName(QString::fromUtf8("leftrightBt"));
        leftrightBt->setGeometry(QRect(990, 590, 89, 25));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(870, 40, 200, 200));
        label->setStyleSheet(QString::fromUtf8("border-image: url(:/\345\215\223\345\267\245logo.png);"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(850, 310, 231, 28));
        horizontalLayout_3 = new QHBoxLayout(widget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        RotateSlider = new QSlider(widget);
        RotateSlider->setObjectName(QString::fromUtf8("RotateSlider"));
        RotateSlider->setMaximum(360);
        RotateSlider->setSliderPosition(0);
        RotateSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(RotateSlider);

        RotatespinBox = new QSpinBox(widget);
        RotatespinBox->setObjectName(QString::fromUtf8("RotatespinBox"));
        RotatespinBox->setMaximum(360);

        horizontalLayout_3->addWidget(RotatespinBox);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        ReadPath->setText(QApplication::translate("MainWindow", "Read Path", nullptr));
        resetBt->setText(QApplication::translate("MainWindow", "\350\211\262\345\275\251\345\244\215\344\275\215", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\346\227\213\350\275\254\357\274\232", nullptr));
        InverseBt->setText(QApplication::translate("MainWindow", "\345\217\215\350\211\262", nullptr));
        GrayBt->setText(QApplication::translate("MainWindow", "\347\201\260\345\272\246\345\214\226", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "\344\272\214\345\200\274\345\214\226\357\274\232", nullptr));
        SizeBt->setText(QApplication::translate("MainWindow", "\345\244\247\345\260\217\345\244\215\344\275\215", nullptr));
        updownBt->setText(QApplication::translate("MainWindow", "\344\270\212\344\270\213\347\277\273\350\275\254", nullptr));
        leftrightBt->setText(QApplication::translate("MainWindow", "\345\267\246\345\217\263\347\277\273\350\275\254", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
