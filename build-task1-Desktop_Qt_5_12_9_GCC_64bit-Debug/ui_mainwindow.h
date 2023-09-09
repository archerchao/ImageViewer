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
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
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
    QAction *zoomin;
    QAction *bevel;
    QAction *perspective;
    QAction *histogram;
    QAction *equHistogram;
    QAction *robert;
    QAction *sebel;
    QAction *laplace;
    QAction *medianFilter;
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
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_3;
    QSlider *RotateSlider;
    QSpinBox *RotatespinBox;
    QPushButton *testBt;
    QLabel *histogramLabel;
    QStatusBar *statusbar;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QMenu *menu_4;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1100, 680);
        MainWindow->setMinimumSize(QSize(1100, 680));
        MainWindow->setMaximumSize(QSize(1100, 680));
        zoomin = new QAction(MainWindow);
        zoomin->setObjectName(QString::fromUtf8("zoomin"));
        bevel = new QAction(MainWindow);
        bevel->setObjectName(QString::fromUtf8("bevel"));
        perspective = new QAction(MainWindow);
        perspective->setObjectName(QString::fromUtf8("perspective"));
        histogram = new QAction(MainWindow);
        histogram->setObjectName(QString::fromUtf8("histogram"));
        equHistogram = new QAction(MainWindow);
        equHistogram->setObjectName(QString::fromUtf8("equHistogram"));
        robert = new QAction(MainWindow);
        robert->setObjectName(QString::fromUtf8("robert"));
        sebel = new QAction(MainWindow);
        sebel->setObjectName(QString::fromUtf8("sebel"));
        laplace = new QAction(MainWindow);
        laplace->setObjectName(QString::fromUtf8("laplace"));
        medianFilter = new QAction(MainWindow);
        medianFilter->setObjectName(QString::fromUtf8("medianFilter"));
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
        graphicsView->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
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
        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(850, 310, 231, 28));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        RotateSlider = new QSlider(layoutWidget1);
        RotateSlider->setObjectName(QString::fromUtf8("RotateSlider"));
        RotateSlider->setMaximum(360);
        RotateSlider->setSliderPosition(0);
        RotateSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(RotateSlider);

        RotatespinBox = new QSpinBox(layoutWidget1);
        RotatespinBox->setObjectName(QString::fromUtf8("RotatespinBox"));
        RotatespinBox->setMaximum(360);

        horizontalLayout_3->addWidget(RotatespinBox);

        testBt = new QPushButton(centralwidget);
        testBt->setObjectName(QString::fromUtf8("testBt"));
        testBt->setGeometry(QRect(850, 430, 89, 25));
        histogramLabel = new QLabel(centralwidget);
        histogramLabel->setObjectName(QString::fromUtf8("histogramLabel"));
        histogramLabel->setGeometry(QRect(840, 20, 250, 250));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1100, 28));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        menu_3 = new QMenu(menuBar);
        menu_3->setObjectName(QString::fromUtf8("menu_3"));
        menu_4 = new QMenu(menuBar);
        menu_4->setObjectName(QString::fromUtf8("menu_4"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu_3->menuAction());
        menuBar->addAction(menu_4->menuAction());
        menu->addAction(zoomin);
        menu->addSeparator();
        menu->addAction(bevel);
        menu->addSeparator();
        menu->addAction(perspective);
        menu_2->addAction(histogram);
        menu_2->addSeparator();
        menu_2->addAction(equHistogram);
        menu_3->addSeparator();
        menu_3->addAction(robert);
        menu_3->addSeparator();
        menu_3->addAction(sebel);
        menu_3->addSeparator();
        menu_3->addAction(laplace);
        menu_4->addAction(medianFilter);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        zoomin->setText(QApplication::translate("MainWindow", "\346\224\276\345\244\247", nullptr));
        bevel->setText(QApplication::translate("MainWindow", "\346\226\234\345\210\207", nullptr));
        perspective->setText(QApplication::translate("MainWindow", "\351\200\217\350\247\206", nullptr));
        histogram->setText(QApplication::translate("MainWindow", "\346\230\276\347\244\272\347\233\264\346\226\271\345\233\276", nullptr));
        equHistogram->setText(QApplication::translate("MainWindow", "\347\233\264\346\226\271\345\233\276\345\235\207\350\241\241", nullptr));
        robert->setText(QApplication::translate("MainWindow", "robert", nullptr));
        sebel->setText(QApplication::translate("MainWindow", "sebel", nullptr));
        laplace->setText(QApplication::translate("MainWindow", "laplace", nullptr));
        medianFilter->setText(QApplication::translate("MainWindow", "\344\270\255\345\200\274\346\273\244\346\263\242", nullptr));
        ReadPath->setText(QApplication::translate("MainWindow", "Read Path", nullptr));
        resetBt->setText(QApplication::translate("MainWindow", "\350\211\262\345\275\251\345\244\215\344\275\215", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\346\227\213\350\275\254\357\274\232", nullptr));
        InverseBt->setText(QApplication::translate("MainWindow", "\345\217\215\350\211\262", nullptr));
        GrayBt->setText(QApplication::translate("MainWindow", "\347\201\260\345\272\246\345\214\226", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "\344\272\214\345\200\274\345\214\226\357\274\232", nullptr));
        SizeBt->setText(QApplication::translate("MainWindow", "\345\244\247\345\260\217\345\244\215\344\275\215", nullptr));
        updownBt->setText(QApplication::translate("MainWindow", "\344\270\212\344\270\213\347\277\273\350\275\254", nullptr));
        leftrightBt->setText(QApplication::translate("MainWindow", "\345\267\246\345\217\263\347\277\273\350\275\254", nullptr));
        testBt->setText(QApplication::translate("MainWindow", "testBt", nullptr));
        histogramLabel->setText(QString());
        menu->setTitle(QApplication::translate("MainWindow", "\345\217\214\347\272\277\346\200\247\346\217\222\345\200\274", nullptr));
        menu_2->setTitle(QApplication::translate("MainWindow", "\347\233\264\346\226\271\345\233\276", nullptr));
        menu_3->setTitle(QApplication::translate("MainWindow", "\351\224\220\345\214\226", nullptr));
        menu_4->setTitle(QApplication::translate("MainWindow", "\346\273\244\346\263\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
