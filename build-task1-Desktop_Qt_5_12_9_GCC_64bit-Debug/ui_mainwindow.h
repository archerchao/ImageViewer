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
#include <QtWidgets/QTabWidget>
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
    QAction *ErodeMenu;
    QAction *DilateMenu;
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QTextBrowser *textBrowser;
    QPushButton *ReadPath;
    QPushButton *resetBt;
    QGraphicsView *graphicsView;
    QPushButton *InverseBt;
    QPushButton *GrayBt;
    QPushButton *SizeBt;
    QPushButton *updownBt;
    QPushButton *leftrightBt;
    QPushButton *testBt;
    QTabWidget *tabWidget;
    QWidget *tab;
    QPushButton *pushButton;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_3;
    QSlider *RotateSlider;
    QSpinBox *RotatespinBox;
    QLabel *label_2;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_4;
    QSlider *BinSlider;
    QSpinBox *BinspinBox;
    QLabel *label_3;
    QWidget *layoutWidget_9;
    QHBoxLayout *horizontalLayout_11;
    QSlider *HoughthresholdSlider;
    QSpinBox *HoughthresholdspinBox;
    QLabel *label_10;
    QLabel *label_11;
    QWidget *layoutWidget_10;
    QHBoxLayout *horizontalLayout_13;
    QSlider *HoughminSlider;
    QSpinBox *HoughminspinBox;
    QWidget *tab2;
    QWidget *layoutWidget_6;
    QHBoxLayout *horizontalLayout_9;
    QSlider *watershedSlider;
    QSpinBox *watershedspinBox;
    QLabel *label_4;
    QLabel *label_5;
    QWidget *layoutWidget_4;
    QHBoxLayout *horizontalLayout_6;
    QSlider *threshold1Slider;
    QSpinBox *threshold1spinBox;
    QLabel *label_7;
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout_5;
    QSlider *threshold2Slider;
    QSpinBox *threshold2spinBox;
    QLabel *label_6;
    QWidget *layoutWidget_5;
    QHBoxLayout *horizontalLayout_8;
    QSlider *growSlider;
    QSpinBox *growspinBox;
    QLabel *label_8;
    QWidget *layoutWidget_7;
    QHBoxLayout *horizontalLayout_7;
    QSlider *canny1Slider;
    QSpinBox *canny1spinBox;
    QLabel *label_9;
    QWidget *layoutWidget_8;
    QHBoxLayout *horizontalLayout_10;
    QSlider *canny2Slider;
    QSpinBox *canny2spinBox;
    QStatusBar *statusbar;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QMenu *menu_4;
    QMenu *menu_5;

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
        ErodeMenu = new QAction(MainWindow);
        ErodeMenu->setObjectName(QString::fromUtf8("ErodeMenu"));
        DilateMenu = new QAction(MainWindow);
        DilateMenu->setObjectName(QString::fromUtf8("DilateMenu"));
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
        InverseBt = new QPushButton(centralwidget);
        InverseBt->setObjectName(QString::fromUtf8("InverseBt"));
        InverseBt->setGeometry(QRect(990, 470, 89, 25));
        GrayBt = new QPushButton(centralwidget);
        GrayBt->setObjectName(QString::fromUtf8("GrayBt"));
        GrayBt->setGeometry(QRect(850, 470, 89, 25));
        SizeBt = new QPushButton(centralwidget);
        SizeBt->setObjectName(QString::fromUtf8("SizeBt"));
        SizeBt->setGeometry(QRect(850, 530, 89, 25));
        updownBt = new QPushButton(centralwidget);
        updownBt->setObjectName(QString::fromUtf8("updownBt"));
        updownBt->setGeometry(QRect(850, 590, 89, 30));
        leftrightBt = new QPushButton(centralwidget);
        leftrightBt->setObjectName(QString::fromUtf8("leftrightBt"));
        leftrightBt->setGeometry(QRect(990, 590, 89, 25));
        testBt = new QPushButton(centralwidget);
        testBt->setObjectName(QString::fromUtf8("testBt"));
        testBt->setGeometry(QRect(920, 500, 89, 25));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(830, 0, 261, 451));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        pushButton = new QPushButton(tab);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(200, 110, 50, 17));
        layoutWidget1 = new QWidget(tab);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 50, 231, 28));
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

        label_2 = new QLabel(tab);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 30, 67, 17));
        layoutWidget_2 = new QWidget(tab);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(20, 130, 231, 28));
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

        label_3 = new QLabel(tab);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 110, 67, 17));
        layoutWidget_9 = new QWidget(tab);
        layoutWidget_9->setObjectName(QString::fromUtf8("layoutWidget_9"));
        layoutWidget_9->setGeometry(QRect(20, 320, 231, 28));
        horizontalLayout_11 = new QHBoxLayout(layoutWidget_9);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(0, 0, 0, 0);
        HoughthresholdSlider = new QSlider(layoutWidget_9);
        HoughthresholdSlider->setObjectName(QString::fromUtf8("HoughthresholdSlider"));
        HoughthresholdSlider->setMaximum(255);
        HoughthresholdSlider->setSliderPosition(0);
        HoughthresholdSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_11->addWidget(HoughthresholdSlider);

        HoughthresholdspinBox = new QSpinBox(layoutWidget_9);
        HoughthresholdspinBox->setObjectName(QString::fromUtf8("HoughthresholdspinBox"));
        HoughthresholdspinBox->setMaximum(255);

        horizontalLayout_11->addWidget(HoughthresholdspinBox);

        label_10 = new QLabel(tab);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(20, 300, 141, 17));
        label_11 = new QLabel(tab);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(20, 360, 171, 17));
        layoutWidget_10 = new QWidget(tab);
        layoutWidget_10->setObjectName(QString::fromUtf8("layoutWidget_10"));
        layoutWidget_10->setGeometry(QRect(20, 380, 231, 28));
        horizontalLayout_13 = new QHBoxLayout(layoutWidget_10);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        horizontalLayout_13->setContentsMargins(0, 0, 0, 0);
        HoughminSlider = new QSlider(layoutWidget_10);
        HoughminSlider->setObjectName(QString::fromUtf8("HoughminSlider"));
        HoughminSlider->setMaximum(255);
        HoughminSlider->setSliderPosition(0);
        HoughminSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_13->addWidget(HoughminSlider);

        HoughminspinBox = new QSpinBox(layoutWidget_10);
        HoughminspinBox->setObjectName(QString::fromUtf8("HoughminspinBox"));
        HoughminspinBox->setMaximum(255);

        horizontalLayout_13->addWidget(HoughminspinBox);

        tabWidget->addTab(tab, QString());
        tab2 = new QWidget();
        tab2->setObjectName(QString::fromUtf8("tab2"));
        layoutWidget_6 = new QWidget(tab2);
        layoutWidget_6->setObjectName(QString::fromUtf8("layoutWidget_6"));
        layoutWidget_6->setGeometry(QRect(20, 30, 231, 28));
        horizontalLayout_9 = new QHBoxLayout(layoutWidget_6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        watershedSlider = new QSlider(layoutWidget_6);
        watershedSlider->setObjectName(QString::fromUtf8("watershedSlider"));
        watershedSlider->setMaximum(255);
        watershedSlider->setSliderPosition(0);
        watershedSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_9->addWidget(watershedSlider);

        watershedspinBox = new QSpinBox(layoutWidget_6);
        watershedspinBox->setObjectName(QString::fromUtf8("watershedspinBox"));
        watershedspinBox->setMaximum(255);

        horizontalLayout_9->addWidget(watershedspinBox);

        label_4 = new QLabel(tab2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 190, 67, 17));
        label_5 = new QLabel(tab2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 130, 67, 17));
        layoutWidget_4 = new QWidget(tab2);
        layoutWidget_4->setObjectName(QString::fromUtf8("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(20, 150, 231, 28));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget_4);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        threshold1Slider = new QSlider(layoutWidget_4);
        threshold1Slider->setObjectName(QString::fromUtf8("threshold1Slider"));
        threshold1Slider->setMaximum(255);
        threshold1Slider->setSliderPosition(0);
        threshold1Slider->setOrientation(Qt::Horizontal);

        horizontalLayout_6->addWidget(threshold1Slider);

        threshold1spinBox = new QSpinBox(layoutWidget_4);
        threshold1spinBox->setObjectName(QString::fromUtf8("threshold1spinBox"));
        threshold1spinBox->setMaximum(255);

        horizontalLayout_6->addWidget(threshold1spinBox);

        label_7 = new QLabel(tab2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(20, 10, 91, 17));
        layoutWidget_3 = new QWidget(tab2);
        layoutWidget_3->setObjectName(QString::fromUtf8("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(20, 210, 231, 28));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget_3);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        threshold2Slider = new QSlider(layoutWidget_3);
        threshold2Slider->setObjectName(QString::fromUtf8("threshold2Slider"));
        threshold2Slider->setMaximum(255);
        threshold2Slider->setSliderPosition(0);
        threshold2Slider->setOrientation(Qt::Horizontal);

        horizontalLayout_5->addWidget(threshold2Slider);

        threshold2spinBox = new QSpinBox(layoutWidget_3);
        threshold2spinBox->setObjectName(QString::fromUtf8("threshold2spinBox"));
        threshold2spinBox->setMaximum(255);

        horizontalLayout_5->addWidget(threshold2spinBox);

        label_6 = new QLabel(tab2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 70, 91, 17));
        layoutWidget_5 = new QWidget(tab2);
        layoutWidget_5->setObjectName(QString::fromUtf8("layoutWidget_5"));
        layoutWidget_5->setGeometry(QRect(20, 90, 231, 28));
        horizontalLayout_8 = new QHBoxLayout(layoutWidget_5);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        growSlider = new QSlider(layoutWidget_5);
        growSlider->setObjectName(QString::fromUtf8("growSlider"));
        growSlider->setMaximum(255);
        growSlider->setSliderPosition(0);
        growSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_8->addWidget(growSlider);

        growspinBox = new QSpinBox(layoutWidget_5);
        growspinBox->setObjectName(QString::fromUtf8("growspinBox"));
        growspinBox->setMaximum(255);

        horizontalLayout_8->addWidget(growspinBox);

        label_8 = new QLabel(tab2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(20, 250, 67, 17));
        layoutWidget_7 = new QWidget(tab2);
        layoutWidget_7->setObjectName(QString::fromUtf8("layoutWidget_7"));
        layoutWidget_7->setGeometry(QRect(20, 270, 231, 28));
        horizontalLayout_7 = new QHBoxLayout(layoutWidget_7);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        canny1Slider = new QSlider(layoutWidget_7);
        canny1Slider->setObjectName(QString::fromUtf8("canny1Slider"));
        canny1Slider->setMaximum(255);
        canny1Slider->setSliderPosition(0);
        canny1Slider->setOrientation(Qt::Horizontal);

        horizontalLayout_7->addWidget(canny1Slider);

        canny1spinBox = new QSpinBox(layoutWidget_7);
        canny1spinBox->setObjectName(QString::fromUtf8("canny1spinBox"));
        canny1spinBox->setMaximum(255);

        horizontalLayout_7->addWidget(canny1spinBox);

        label_9 = new QLabel(tab2);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(20, 310, 67, 17));
        layoutWidget_8 = new QWidget(tab2);
        layoutWidget_8->setObjectName(QString::fromUtf8("layoutWidget_8"));
        layoutWidget_8->setGeometry(QRect(20, 330, 231, 28));
        horizontalLayout_10 = new QHBoxLayout(layoutWidget_8);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        canny2Slider = new QSlider(layoutWidget_8);
        canny2Slider->setObjectName(QString::fromUtf8("canny2Slider"));
        canny2Slider->setMaximum(255);
        canny2Slider->setSliderPosition(0);
        canny2Slider->setOrientation(Qt::Horizontal);

        horizontalLayout_10->addWidget(canny2Slider);

        canny2spinBox = new QSpinBox(layoutWidget_8);
        canny2spinBox->setObjectName(QString::fromUtf8("canny2spinBox"));
        canny2spinBox->setMaximum(255);

        horizontalLayout_10->addWidget(canny2spinBox);

        tabWidget->addTab(tab2, QString());
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
        menu_5 = new QMenu(menuBar);
        menu_5->setObjectName(QString::fromUtf8("menu_5"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu_3->menuAction());
        menuBar->addAction(menu_4->menuAction());
        menuBar->addAction(menu_5->menuAction());
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
        menu_5->addSeparator();
        menu_5->addAction(ErodeMenu);
        menu_5->addSeparator();
        menu_5->addAction(DilateMenu);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


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
        ErodeMenu->setText(QApplication::translate("MainWindow", "\350\205\220\350\232\200", nullptr));
        DilateMenu->setText(QApplication::translate("MainWindow", "\350\206\250\350\203\200", nullptr));
        ReadPath->setText(QApplication::translate("MainWindow", "Read Path", nullptr));
        resetBt->setText(QApplication::translate("MainWindow", "\350\211\262\345\275\251\345\244\215\344\275\215", nullptr));
        InverseBt->setText(QApplication::translate("MainWindow", "\345\217\215\350\211\262", nullptr));
        GrayBt->setText(QApplication::translate("MainWindow", "\347\201\260\345\272\246\345\214\226", nullptr));
        SizeBt->setText(QApplication::translate("MainWindow", "\345\244\247\345\260\217\345\244\215\344\275\215", nullptr));
        updownBt->setText(QApplication::translate("MainWindow", "\344\270\212\344\270\213\347\277\273\350\275\254", nullptr));
        leftrightBt->setText(QApplication::translate("MainWindow", "\345\267\246\345\217\263\347\277\273\350\275\254", nullptr));
        testBt->setText(QApplication::translate("MainWindow", "testBt", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "Otsu", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\346\227\213\350\275\254\357\274\232", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "\344\272\214\345\200\274\345\214\226\357\274\232", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "\351\234\215\345\244\253\345\217\230\345\214\226\347\264\257\345\212\240\351\230\210\345\200\274\357\274\232", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "\351\234\215\345\244\253\345\217\230\345\214\226\346\234\200\345\260\217\347\233\264\347\272\277\351\225\277\345\272\246\357\274\232", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Tab 1", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "\345\217\214\351\230\210\345\200\2742\357\274\232", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "\345\217\214\351\230\210\345\200\2741\357\274\232", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "Watershed\357\274\232", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "\347\224\237\351\225\277\351\230\210\345\200\274\357\274\232", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "Canny1:", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "Canny2:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab2), QApplication::translate("MainWindow", "\351\230\210\345\200\274", nullptr));
        menu->setTitle(QApplication::translate("MainWindow", "\345\217\214\347\272\277\346\200\247\346\217\222\345\200\274", nullptr));
        menu_2->setTitle(QApplication::translate("MainWindow", "\347\233\264\346\226\271\345\233\276", nullptr));
        menu_3->setTitle(QApplication::translate("MainWindow", "\351\224\220\345\214\226", nullptr));
        menu_4->setTitle(QApplication::translate("MainWindow", "\346\273\244\346\263\242", nullptr));
        menu_5->setTitle(QApplication::translate("MainWindow", "\350\205\220\350\232\200/\350\206\250\350\203\200", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
