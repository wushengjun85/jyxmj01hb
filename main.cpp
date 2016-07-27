#include <QtGui/QApplication>
#include "widget.h"
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    //QApplication::setOverrideCursor(Qt::BlankCursor);//隐藏鼠标 光标
    //QApplication::setOverrideCursor(Qt::ArrowCursor);//显示鼠标 光标

    //在开发板上 显示汉字
    #if 0
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    QFont font  = a.font();
    font.setFamily("unifont");
    a.setFont(font);
    #endif

    return a.exec();
}
