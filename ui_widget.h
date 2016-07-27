/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLineEdit *lineEdit_2;
    QPushButton *pushButton;
    QLabel *label;
    QPushButton *pushButton_2;
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
    QLCDNumber *lcdNumber;
    QLCDNumber *lcdNumber_2;
    QPushButton *pushButton_3;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 602);
        Widget->setStyleSheet(QString::fromUtf8(""));
        lineEdit_2 = new QLineEdit(Widget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(20, 490, 131, 51));
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(670, 550, 51, 51));
        pushButton->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/img2/mysetup_icon.png);"));
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 140, 61, 31));
        pushButton_2 = new QPushButton(Widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(600, 550, 51, 51));
        pushButton_2->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/img2/myicon_setup.png);"));
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(70, 240, 61, 41));
        label_3 = new QLabel(Widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(70, 190, 61, 41));
        label_4 = new QLabel(Widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(70, 290, 61, 31));
        label_6 = new QLabel(Widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(70, 340, 61, 31));
        label_7 = new QLabel(Widget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(70, 390, 101, 41));
        label_8 = new QLabel(Widget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(70, 440, 91, 31));
        label_9 = new QLabel(Widget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(640, 160, 71, 41));
        label_10 = new QLabel(Widget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(640, 240, 71, 41));
        label_11 = new QLabel(Widget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(640, 330, 71, 41));
        label_12 = new QLabel(Widget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(630, 400, 91, 41));
        label_13 = new QLabel(Widget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(630, 450, 71, 41));
        lcdNumber = new QLCDNumber(Widget);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setGeometry(QRect(20, 580, 81, 21));
        lcdNumber->setStyleSheet(QString::fromUtf8("selection-color: rgb(255, 0, 0);"));
        lcdNumber->setFrameShape(QFrame::NoFrame);
        lcdNumber->setNumDigits(8);
        lcdNumber->setDigitCount(8);
        lcdNumber->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber_2 = new QLCDNumber(Widget);
        lcdNumber_2->setObjectName(QString::fromUtf8("lcdNumber_2"));
        lcdNumber_2->setGeometry(QRect(10, 550, 101, 31));
        lcdNumber_2->setFrameShape(QFrame::NoFrame);
        lcdNumber_2->setDigitCount(10);
        lcdNumber_2->setSegmentStyle(QLCDNumber::Flat);
        pushButton_3 = new QPushButton(Widget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(730, 550, 51, 51));
        pushButton_3->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/img2/laba.bmp);"));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QString());
        label->setText(QApplication::translate("Widget", "456", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QString());
        label_2->setText(QApplication::translate("Widget", "456", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Widget", "123", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Widget", "123566", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("Widget", "123566", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("Widget", "123566", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("Widget", "123566", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("Widget", "88888", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("Widget", "88888", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("Widget", "88888", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("Widget", "88888", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("Widget", "88888", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
