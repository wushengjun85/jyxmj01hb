/********************************************************************************
** Form generated from reading UI file 'camera.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAMERA_H
#define UI_CAMERA_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_camera
{
public:
    QPushButton *show_ptn;
    QPushButton *stop_ptn;
    QPushButton *quit_ptn;
    QLabel *show_label;
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QPushButton *pushButton_2;
    QLCDNumber *lcdNumber_2;
    QLCDNumber *lcdNumber;
    QPushButton *pushButton_3;

    void setupUi(QDialog *camera)
    {
        if (camera->objectName().isEmpty())
            camera->setObjectName(QString::fromUtf8("camera"));
        camera->resize(800, 601);
        show_ptn = new QPushButton(camera);
        show_ptn->setObjectName(QString::fromUtf8("show_ptn"));
        show_ptn->setGeometry(QRect(120, 570, 131, 31));
        stop_ptn = new QPushButton(camera);
        stop_ptn->setObjectName(QString::fromUtf8("stop_ptn"));
        stop_ptn->setGeometry(QRect(270, 570, 151, 31));
        quit_ptn = new QPushButton(camera);
        quit_ptn->setObjectName(QString::fromUtf8("quit_ptn"));
        quit_ptn->setGeometry(QRect(450, 570, 141, 31));
        show_label = new QLabel(camera);
        show_label->setObjectName(QString::fromUtf8("show_label"));
        show_label->setGeometry(QRect(230, 140, 341, 261));
        pushButton = new QPushButton(camera);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(600, 550, 51, 51));
        pushButton->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/img2/myicon_setup.png);"));
        label = new QLabel(camera);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 140, 71, 31));
        label_2 = new QLabel(camera);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(70, 190, 71, 41));
        label_3 = new QLabel(camera);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(70, 240, 66, 41));
        label_4 = new QLabel(camera);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(70, 290, 66, 31));
        label_6 = new QLabel(camera);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(70, 340, 66, 31));
        label_7 = new QLabel(camera);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(70, 390, 66, 31));
        label_8 = new QLabel(camera);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(70, 440, 66, 31));
        label_9 = new QLabel(camera);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(640, 170, 66, 31));
        label_10 = new QLabel(camera);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(640, 250, 66, 31));
        label_11 = new QLabel(camera);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(640, 330, 66, 31));
        label_12 = new QLabel(camera);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(630, 410, 66, 31));
        label_13 = new QLabel(camera);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(630, 460, 66, 31));
        label_14 = new QLabel(camera);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(310, 410, 111, 41));
        label_15 = new QLabel(camera);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(310, 460, 111, 41));
        pushButton_2 = new QPushButton(camera);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(660, 550, 51, 51));
        pushButton_2->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/img2/mysetup_icon.png);"));
        lcdNumber_2 = new QLCDNumber(camera);
        lcdNumber_2->setObjectName(QString::fromUtf8("lcdNumber_2"));
        lcdNumber_2->setGeometry(QRect(10, 550, 101, 31));
        lcdNumber_2->setFrameShape(QFrame::NoFrame);
        lcdNumber_2->setDigitCount(10);
        lcdNumber_2->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber = new QLCDNumber(camera);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setGeometry(QRect(20, 580, 81, 21));
        lcdNumber->setStyleSheet(QString::fromUtf8("selection-color: rgb(255, 0, 0);"));
        lcdNumber->setFrameShape(QFrame::NoFrame);
        lcdNumber->setNumDigits(8);
        lcdNumber->setDigitCount(8);
        lcdNumber->setSegmentStyle(QLCDNumber::Flat);
        pushButton_3 = new QPushButton(camera);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(720, 550, 51, 51));
        pushButton_3->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/img2/laba.bmp);"));

        retranslateUi(camera);

        QMetaObject::connectSlotsByName(camera);
    } // setupUi

    void retranslateUi(QDialog *camera)
    {
        camera->setWindowTitle(QApplication::translate("camera", "Dialog", 0, QApplication::UnicodeUTF8));
        show_ptn->setText(QApplication::translate("camera", "start", 0, QApplication::UnicodeUTF8));
        stop_ptn->setText(QApplication::translate("camera", "stop", 0, QApplication::UnicodeUTF8));
        quit_ptn->setText(QApplication::translate("camera", "quit", 0, QApplication::UnicodeUTF8));
        show_label->setText(QString());
        pushButton->setText(QString());
        label->setText(QApplication::translate("camera", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("camera", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("camera", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("camera", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("camera", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("camera", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("camera", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("camera", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("camera", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("camera", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("camera", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("camera", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("camera", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("camera", "TextLabel", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QString());
        pushButton_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class camera: public Ui_camera {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMERA_H
