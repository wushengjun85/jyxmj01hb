/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

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

class Ui_Dialog
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QLabel *label_2;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QLabel *label_3;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QLabel *label_4;
    QLCDNumber *lcdNumber_2;
    QLCDNumber *lcdNumber;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(847, 627);
        pushButton = new QPushButton(Dialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(720, 550, 61, 51));
        pushButton->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/img2/back.png);"));
        pushButton_2 = new QPushButton(Dialog);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(180, 270, 31, 31));
        label = new QLabel(Dialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(220, 270, 61, 31));
        pushButton_3 = new QPushButton(Dialog);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(290, 270, 31, 31));
        pushButton_4 = new QPushButton(Dialog);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(180, 340, 31, 31));
        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(220, 340, 61, 31));
        pushButton_5 = new QPushButton(Dialog);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(290, 340, 31, 31));
        pushButton_6 = new QPushButton(Dialog);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(180, 420, 31, 31));
        label_3 = new QLabel(Dialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(220, 420, 61, 31));
        pushButton_7 = new QPushButton(Dialog);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(290, 420, 31, 31));
        pushButton_8 = new QPushButton(Dialog);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setGeometry(QRect(140, 170, 51, 51));
        pushButton_8->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/img2/timeset.png);"));
        label_4 = new QLabel(Dialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(170, 570, 101, 41));
        lcdNumber_2 = new QLCDNumber(Dialog);
        lcdNumber_2->setObjectName(QString::fromUtf8("lcdNumber_2"));
        lcdNumber_2->setGeometry(QRect(10, 550, 101, 31));
        lcdNumber_2->setFrameShape(QFrame::NoFrame);
        lcdNumber_2->setDigitCount(10);
        lcdNumber_2->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber = new QLCDNumber(Dialog);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setGeometry(QRect(20, 580, 81, 21));
        lcdNumber->setStyleSheet(QString::fromUtf8("selection-color: rgb(255, 0, 0);"));
        lcdNumber->setFrameShape(QFrame::NoFrame);
        lcdNumber->setNumDigits(8);
        lcdNumber->setDigitCount(8);
        lcdNumber->setSegmentStyle(QLCDNumber::Flat);

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QString());
        pushButton_2->setText(QApplication::translate("Dialog", "-", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        pushButton_3->setText(QApplication::translate("Dialog", "+", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("Dialog", "-", 0, QApplication::UnicodeUTF8));
        label_2->setText(QString());
        pushButton_5->setText(QApplication::translate("Dialog", "+", 0, QApplication::UnicodeUTF8));
        pushButton_6->setText(QApplication::translate("Dialog", "-", 0, QApplication::UnicodeUTF8));
        label_3->setText(QString());
        pushButton_7->setText(QApplication::translate("Dialog", "+", 0, QApplication::UnicodeUTF8));
        pushButton_8->setText(QString());
        label_4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
