/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Mon Jan 20 15:15:02 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton_track;
    QFrame *frame;
    QLabel *imageAxes;
    QFrame *frame_5;
    QFrame *frame_3;
    QLabel *label_2;
    QRadioButton *radioButton_mshift;
    QRadioButton *radioButton_sgram;
    QRadioButton *radioButton_both;
    QRadioButton *radioButton_pf;
    QLabel *label_4;
    QLabel *label_8;
    QFrame *frame_4;
    QLabel *label_9;
    QRadioButton *radioButton_histo1;
    QRadioButton *radioButton_histo2;
    QRadioButton *radioButton_histo3;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(645, 492);
        MainWindow->setMinimumSize(QSize(645, 492));
        MainWindow->setMaximumSize(QSize(645, 492));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/flag_1.jpg"), QSize(), QIcon::Normal, QIcon::On);
        MainWindow->setWindowIcon(icon);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        pushButton_track = new QPushButton(centralWidget);
        pushButton_track->setObjectName(QString::fromUtf8("pushButton_track"));
        pushButton_track->setGeometry(QRect(20, 390, 491, 41));
        QFont font;
        font.setPointSize(15);
        pushButton_track->setFont(font);
        frame = new QFrame(centralWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(200, 30, 431, 341));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        imageAxes = new QLabel(frame);
        imageAxes->setObjectName(QString::fromUtf8("imageAxes"));
        imageAxes->setGeometry(QRect(10, 10, 411, 321));
        imageAxes->setFrameShape(QFrame::StyledPanel);
        imageAxes->setScaledContents(true);
        frame_5 = new QFrame(centralWidget);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        frame_5->setGeometry(QRect(20, 30, 171, 341));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        frame_3 = new QFrame(frame_5);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(10, 40, 151, 121));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        label_2 = new QLabel(frame_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 9, 131, 20));
        QFont font1;
        font1.setBold(true);
        font1.setItalic(false);
        font1.setUnderline(false);
        font1.setWeight(75);
        font1.setStrikeOut(false);
        label_2->setFont(font1);
        radioButton_mshift = new QRadioButton(frame_3);
        radioButton_mshift->setObjectName(QString::fromUtf8("radioButton_mshift"));
        radioButton_mshift->setGeometry(QRect(10, 30, 141, 22));
        radioButton_mshift->setChecked(false);
        radioButton_sgram = new QRadioButton(frame_3);
        radioButton_sgram->setObjectName(QString::fromUtf8("radioButton_sgram"));
        radioButton_sgram->setGeometry(QRect(10, 50, 141, 22));
        radioButton_sgram->setChecked(false);
        radioButton_both = new QRadioButton(frame_3);
        radioButton_both->setObjectName(QString::fromUtf8("radioButton_both"));
        radioButton_both->setGeometry(QRect(10, 70, 116, 22));
        radioButton_both->setChecked(false);
        radioButton_pf = new QRadioButton(frame_3);
        radioButton_pf->setObjectName(QString::fromUtf8("radioButton_pf"));
        radioButton_pf->setGeometry(QRect(10, 90, 141, 22));
        radioButton_pf->setChecked(true);
        label_4 = new QLabel(frame_5);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 5, 151, 21));
        label_4->setFont(font1);
        label_8 = new QLabel(frame_5);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(30, 260, 111, 71));
        label_8->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/UB.png")));
        label_8->setScaledContents(true);
        frame_4 = new QFrame(frame_5);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setGeometry(QRect(10, 164, 151, 91));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        label_9 = new QLabel(frame_4);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(10, 9, 131, 20));
        label_9->setFont(font1);
        radioButton_histo1 = new QRadioButton(frame_4);
        radioButton_histo1->setObjectName(QString::fromUtf8("radioButton_histo1"));
        radioButton_histo1->setGeometry(QRect(10, 30, 141, 22));
        radioButton_histo1->setChecked(true);
        radioButton_histo2 = new QRadioButton(frame_4);
        radioButton_histo2->setObjectName(QString::fromUtf8("radioButton_histo2"));
        radioButton_histo2->setGeometry(QRect(10, 50, 141, 22));
        radioButton_histo2->setChecked(false);
        radioButton_histo3 = new QRadioButton(frame_4);
        radioButton_histo3->setObjectName(QString::fromUtf8("radioButton_histo3"));
        radioButton_histo3->setGeometry(QRect(10, 70, 116, 22));
        radioButton_histo3->setChecked(false);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 0, 611, 21));
        label_5->setFont(font1);
        label_5->setAlignment(Qt::AlignCenter);
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(500, 430, 111, 20));
        QFont font2;
        font2.setPointSize(8);
        font2.setBold(true);
        font2.setItalic(false);
        font2.setUnderline(false);
        font2.setWeight(75);
        font2.setStrikeOut(false);
        label_6->setFont(font2);
        label_6->setAlignment(Qt::AlignCenter);
        label_6->setWordWrap(true);
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(526, 390, 61, 41));
        label_7->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/flag_2.jpg")));
        label_7->setScaledContents(true);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 645, 25));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Tracker Test", 0, QApplication::UnicodeUTF8));
        pushButton_track->setText(QApplication::translate("MainWindow", "START Tracking!", 0, QApplication::UnicodeUTF8));
        imageAxes->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "Trackers", 0, QApplication::UnicodeUTF8));
        radioButton_mshift->setText(QApplication::translate("MainWindow", "MS: Histograms", 0, QApplication::UnicodeUTF8));
        radioButton_sgram->setText(QApplication::translate("MainWindow", "MS: Spatiograms", 0, QApplication::UnicodeUTF8));
        radioButton_both->setText(QApplication::translate("MainWindow", "MS: Both", 0, QApplication::UnicodeUTF8));
        radioButton_pf->setText(QApplication::translate("MainWindow", "PF: Spatiograms", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "TRACKING OPTIONS", 0, QApplication::UnicodeUTF8));
        label_8->setText(QString());
        label_9->setText(QApplication::translate("MainWindow", "Color info", 0, QApplication::UnicodeUTF8));
        radioButton_histo1->setText(QApplication::translate("MainWindow", "Graylevel", 0, QApplication::UnicodeUTF8));
        radioButton_histo2->setText(QApplication::translate("MainWindow", "Hue", 0, QApplication::UnicodeUTF8));
        radioButton_histo3->setText(QApplication::translate("MainWindow", "Mod RGB", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "SPATIOGRAMS Vs. HISTOGRAMS FOR REGION-BASED TRACKING", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "TEAM COLOMBIA", 0, QApplication::UnicodeUTF8));
        label_7->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
