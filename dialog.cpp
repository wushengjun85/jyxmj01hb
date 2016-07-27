#include "dialog.h"
#include "ui_dialog.h"
#include<QPainter>
#include<QString>
#include<QTime>
#include<QTimer>


/*******************************************************************************/
//Date:2016.6.1
//Author:wushengjun
//speed defined
int zl = 5; //轴流滚筒转速
int ftq = 6;//复脱器转速
int syq = 8;//升运器转速

extern QString Datesetup;
/*******************************************************************************/




/********************************************************************************************************************/
//2016 6.1  wushengjun
//定义变量 控制图标闪烁。
//
/********************************************************************************************************************/

extern unsigned char flagLeft;  //左转
extern unsigned char countLeft; //左转

extern unsigned char flagBattery;//电瓶指示灯
extern unsigned char countBattery;//电瓶指示灯

extern unsigned char flagWidthlamp; //示宽灯
extern unsigned char countWidthlamp;//示宽灯

extern unsigned char  flagYG; //远光灯
extern unsigned char  countYG;//远光灯

extern unsigned char  flagSW; //水温
extern unsigned char  countSW; //水温

extern unsigned char  flagJG; //近光灯
extern unsigned char  countJG; //近光灯


extern unsigned char  flagJY; //机油
extern unsigned char  countJY; //机油

extern unsigned char  flagLCM; //粮仓满
extern unsigned char  countLCM; //粮仓满

extern unsigned char   flagFDJYR; //发动机预热
extern unsigned char   countFDJYR; //发动机预热

extern unsigned char   flagGL; //过滤
extern unsigned char   countGL; //过滤

extern unsigned char   flagYL; //油量
extern unsigned char    countYL;//油量

extern unsigned char  flagYeyayouwen;//液压油温
extern unsigned char  countYeyayouwen; //液压油温

extern unsigned char    flagECU;//ecu
extern unsigned char    countECU;//ecu

extern unsigned char    flagPark;//停车
extern unsigned char    countPark; //停车

extern unsigned char   flagFDJGZ; //发动机故障
extern unsigned char   countFDJGZ; //发动机故障

extern unsigned char   flagRight; //右转
extern unsigned char    countRight;//右转


extern unsigned char  flagyouxiangman;//油量满报警
extern unsigned char  flagyouliangdi; //油量低报警






//第三个字节
extern uchar kg6;//开关6 6，
extern uchar kg5;//开关5 5，
extern uchar kg4;//开关4 4,
extern uchar kg3;//开关3 3,
extern uchar kg2;//开关2 2,
extern uchar kg1;//开关1 1,


//第二个字节
extern ushort out6;//输出6 6，
extern ushort out5;//输出5 5,
extern ushort out4;//输出4 4,


//第一个字节
extern ushort out3;//输出3 3,
extern ushort out2;//输出2 2,
extern ushort out1;//输出1 1,






/********************************************************************************************************************/

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    resize(800,600);
    Dialog::move(0,0);//回到原来主窗口的位置
    setWindowFlags(windowFlags()|Qt::FramelessWindowHint|Qt::WindowTitleHint);//删除 最小化、最大化、关闭按钮


    QTimer *dialogtime = new QTimer(this);
    connect(dialogtime, SIGNAL(timeout()), this, SLOT(update()));  //连接信号槽，定时器超时触发窗体更新

    dialogtime->start(500);

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    this->close();
}

void Dialog::paintEvent(QPaintEvent *event)
{
    QPainter dp(this);
    QPixmap dppix;
    dppix.load("./img2/setup2.bmp");
    dp.drawPixmap(0,0,800,600,dppix);

/**********************************************************************************************************************/

    //加载上方图标 闪烁用到
    //zuo zhuandeng
    QPainter paintLeft(this);
    QPixmap pixLeft;

    /**********************************************************************************************************************/
    //测试用
    //2016.7.11
    ui->label_4->setText(Datesetup);
    /**********************************************************************************************************************/


    /**************************************************************************************************************/
    QString timeStr2= QTime::currentTime().toString();     //绘制当前的时间
    QString dateStr2 = QDate::currentDate().toString("yyyy-MM-dd");

    //QDateTime settr = QDate::currentDate();



    //ui->lineEdit->setText(dateStr);
    ui->lcdNumber_2->display(dateStr2);
    ui->lcdNumber->display(timeStr2);


    /**************************************************************************************************************/


    /************************************************************************************************/
    //闪烁不同步问题解决办法。
    //利用消息队列 和 for 循环解决。
    //2016.7.25
    #if 1

        QPainter paintShanshuo(this);
        QPixmap pixShanshuo;
        if(1) //左转灯闪烁
        {
            countLeft++;
            if (countLeft>1)
                countLeft = 0;
            switch(countLeft)
            {
                case 1:
                if(flagLeft)//左转灯闪烁
                {
                    pixShanshuo.load("./img2/27.png");//14.jpg
                    paintShanshuo.drawPixmap(0,0,43,34,pixShanshuo);
                }
                if(flagBattery)//电瓶指示灯
                {
                    pixShanshuo.load("./img2/21.png");//14.jpg
                    paintShanshuo.drawPixmap(51,0,43,34,pixShanshuo);//正上方图片显示
                    paintShanshuo.drawPixmap(20,335,43,34,pixShanshuo);//左边图片显示
                }

                if(flagSW)//水温 0~120度  95度以上报警。
                {
                     pixShanshuo.load("./img2/12.png");//14.jpg
                     paintShanshuo.drawPixmap(204,0,35,35,pixShanshuo);//正上方位置显示的图标
                }

                if(flagJY) //机油  油压报警 0～1 MPa,在0.1 MPa 以下为报警区。
                {
                     pixShanshuo.load("./img2/22.png");//14.jpg
                     paintShanshuo.drawPixmap(306,0,43,43,pixShanshuo);//正上方位置显示的图标
                     paintShanshuo.drawPixmap(20,180,43,43,pixShanshuo);//左边显示的图标
                }

                if(flagLCM)//flagLCM = 1; //粮仓满
                {
                    pixShanshuo.load("./img2/7.png");//14.jpg
                    paintShanshuo.drawPixmap(357,0,43,43,pixShanshuo);
                }

                if(flagFDJYR)//flagFDJYR = 1; //发动机预热
                {
                    pixShanshuo.load("./img2/17.png");//14.jpg
                    paintShanshuo.drawPixmap(357,0,43,43,pixShanshuo);
                }

                if(flagGL)//过滤
                {
                    pixShanshuo.load("./img2/20.png");//14.jpg
                    paintShanshuo.drawPixmap(408,0,43,43,pixShanshuo);
                }
                if (flagyouxiangman|flagyouliangdi)//油量
                {
                    pixShanshuo.load("./img2/23.png");//14.jpg
                    paintShanshuo.drawPixmap(459,0,43,43,pixShanshuo);
                    paintShanshuo.drawPixmap(20,120,43,43,pixShanshuo);
                }
                if(flagYeyayouwen)//液压油温
                {
                     pixShanshuo.load("./img2/16.png");//14.jpg
                     paintShanshuo.drawPixmap(523,0,43,43,pixShanshuo);//上边图标
                     paintShanshuo.drawPixmap(20,230,43,43,pixShanshuo);//左边图标
                }
                if(flagECU)//ecu
                {
                    pixShanshuo.load("./img2/91.png");//14.jpg
                    paintShanshuo.drawPixmap(585,0,43,32,pixShanshuo);
                }

                if(flagFDJGZ)//发动机故障
                {
                    pixShanshuo.load("./img2/8.png");//14.jpg
                    paintShanshuo.drawPixmap(697,0,43,37,pixShanshuo);
                }

                if(flagRight)//右转
                {
                    pixShanshuo.load("./img2/right.png");//14.jpg
                    paintShanshuo.drawPixmap(752,0,48,48,pixShanshuo);
                }
                break;
            }

            //不用闪烁
            if(flagWidthlamp)//示宽灯
            {
                pixShanshuo.load("./img2/25.png");//14.jpg
                paintShanshuo.drawPixmap(102,0,43,34,pixShanshuo);
            }

            if(flagJG)//近光灯flagJG
            {
                pixShanshuo.load("./img2/15.png");//14.jpg
                paintShanshuo.drawPixmap(255,0,38,41,pixShanshuo);
            }

            if(flagYG)//远光灯
            {
                pixShanshuo.load("./img2/24.png");//14.jpg
                paintShanshuo.drawPixmap(153,0,43,34,pixShanshuo);
            }

            if(flagPark)//停车 刹车
            {
                pixShanshuo.load("./img2/18.png");//14.jpg
                paintShanshuo.drawPixmap(640,0,43,34,pixShanshuo);
            }

        }

    #endif




    /************************************************************************************************/


#if 0
    if(flagLeft) //左转灯闪烁
    {
        countLeft++;
        if (countLeft>1)
            countLeft = 0;
        switch(countLeft)
        {
            case 1:pixLeft.load("./img2/27.png");//14.jpg
            break;
        }
        paintLeft.drawPixmap(0,0,43,34,pixLeft);

    }


    //电瓶指示灯
    QPainter paintBattery(this);
    QPixmap pixBattery;


    if(flagBattery) //闪烁
    {
        countBattery++;
        if (countBattery>1)
            countBattery = 0;
        switch(countBattery)
        {
            case 1:pixBattery.load("./img2/21.png");//14.jpg
            break;
        }
        paintBattery.drawPixmap(51,0,43,34,pixBattery);
    }

    //示宽灯
    QPainter paintWidthlamp(this);
    QPixmap pixWidthlamp;
    if(flagWidthlamp) //闪烁
    {
        countWidthlamp++;
        if (countWidthlamp>1)
            countWidthlamp = 0;
        switch(countWidthlamp)
        {
            case 1:pixWidthlamp.load("./img2/25.png");//14.jpg
            break;
        }
        paintWidthlamp.drawPixmap(102,0,43,34,pixWidthlamp);
    }

    //远光灯
    QPainter paintYG(this);
    QPixmap pixYG;
    if(flagYG) //闪烁
    {
        countYG++;
        if (countYG>1)
            countYG = 0;
        switch(countYG)
        {
            case 1:pixYG.load("./img2/24.png");//14.jpg
            break;
        }
        paintYG.drawPixmap(153,0,43,34,pixYG);
    }

    //水温
    QPainter paintSW(this);
    QPixmap pixSW;
    if(flagSW) //闪烁
    {
        countSW++;
        if (countSW>1)
            countSW = 0;
        switch(countSW)
        {
            case 1:pixSW.load("./img2/12.png");//14.jpg
            break;
        }
        paintSW.drawPixmap(204,0,35,35,pixSW);
    }

    //近光灯flagJG

    QPainter paintJG(this);
    QPixmap pixJG;
    if(flagJG) //闪烁
    {
        countJG++;
        if (countJG>1)
            countJG = 0;
        switch(countJG)
        {
            case 1:pixJG.load("./img2/15.png");//14.jpg
            break;
        }
        paintJG.drawPixmap(255,0,38,41,pixJG);
    }

    //机油
    QPainter paintJY(this);
    QPixmap pixJY;
    if(flagJY) //闪烁
    {
        countJY++;
        if (countJY>1)
            countJY = 0;
        switch(countJY)
        {
            case 1:pixJY.load("./img2/22.png");//14.jpg
            break;
        }
        paintJY.drawPixmap(306,0,43,43,pixJY);
    }

    //flagLCM = 1; //粮仓满
    QPainter paintLCM(this);
    QPixmap pixLCM;
    if(flagLCM) //闪烁
    {
        countLCM++;
        if (countLCM>1)
            countLCM = 0;
        switch(countLCM)
        {
            case 1:pixLCM.load("./img2/7.png");//14.jpg
            break;
        }
        paintLCM.drawPixmap(357,0,43,43,pixLCM);
    }

    //flagFDJYR = 1; //发动机预热
    QPainter paintFDJYR(this);
    QPixmap pixFDJYR;
    if(flagFDJYR) //闪烁
    {
        countFDJYR++;
        if (countFDJYR>1)
            countFDJYR = 0;
        switch(countFDJYR)
        {
            case 1:pixFDJYR.load("./img2/17.png");//14.jpg
            break;
        }
        paintFDJYR.drawPixmap(357,0,43,43,pixFDJYR);
    }

    // flagGL = 1; //过滤
    QPainter paintGL(this);
    QPixmap pixGL;
    if(flagGL)
    {
        countGL++;
        if (countGL>1)
            countGL = 0;
        switch(countGL)
        {
            case 1:pixGL.load("./img2/20.png");//14.jpg
            break;
        }
        paintGL.drawPixmap(408,0,43,43,pixGL);
    }

    //flagYL = 1; //油量
    QPainter paintYL(this);
    QPixmap pixYL;
    if(flagyouxiangman|flagyouliangdi)
    {
        countYL++;
        if (countYL>1)
            countYL = 0;
        switch(countYL)
        {
            case 1:pixYL.load("./img2/23.png");//14.jpg
            break;
        }
        paintYL.drawPixmap(459,0,43,43,pixYL);

    }


    //以上比例都是 + 51

    //flagYeyayouwen = 1;//液压油温
    QPainter paintYeyayouwen(this);
    QPixmap pixYeyayouwen;
    if(flagYeyayouwen)
    {
        countYeyayouwen++;
        if (countYeyayouwen>1)
            countYeyayouwen = 0;
        switch(countYeyayouwen)
        {
            case 1:pixYeyayouwen.load("./img2/16.png");//14.jpg
            break;
        }
        paintYeyayouwen.drawPixmap(523,0,43,43,pixYeyayouwen);//上边图标

        //paintYeyayouwen.drawPixmap(20,230,43,43,pixYeyayouwen);//左边图标
    }


    //ecu
        QPainter paintECU(this);
        QPixmap pixECU;
        if(flagECU)
        {
            countECU++;
            if (countECU>1)
                countECU = 0;
            switch(countECU)
            {
                case 1:pixECU.load("./img2/91.png");//14.jpg
                break;
            }
            paintECU.drawPixmap(585,0,43,32,pixECU);
        }


        //flagPark = 1;//停车
        QPainter paintPark(this);
        QPixmap pixPark;
        if(flagPark)
        {
            countPark++;
            if (countPark>1)
                countPark = 0;
            switch(countPark)
            {
                case 1:pixPark.load("./img2/18.png");//14.jpg
                break;
            }
            paintPark.drawPixmap(640,0,43,34,pixPark);
        }

        //
        //flagFDJGZ = 1; //发动机故障
        QPainter paintFDJGZ(this);
        QPixmap pixFDJGZ;
        if(flagFDJGZ)
        {
            countFDJGZ++;
            if (countFDJGZ>1)
                countFDJGZ = 0;
            switch(countFDJGZ)
            {
                case 1:pixFDJGZ.load("./img2/8.png");//14.jpg
                break;
            }
            paintFDJGZ.drawPixmap(697,0,43,37,pixFDJGZ);
        }



        //flagRight = 1; //右转
        QPainter paintRight(this);
        QPixmap pixRight;
        if(flagRight)
        {
            countRight++;
            if (countRight>1)
                countRight = 0;
            switch(countRight)
            {
                case 1:pixRight.load("./img2/right.png");//14.jpg
                break;
            }
            paintRight.drawPixmap(752,0,48,48,pixRight);
        }



#endif

    /**********************************************************************************************************************/







    /********************************************************************************************************/
    //2016.7.6 radiobutton input and output;

    if (kg1)
    {
        QPainter point1_in(this);
        QPixmap pointpix1_in;
        pointpix1_in.load("./img2/2.png");
        point1_in.drawPixmap(523,276,14,14,pointpix1_in);
    }


    if (out1)
    {
        QPainter point1_out(this);
        QPixmap pointpix1_out;
        pointpix1_out.load("./img2/2.png");
        point1_out.drawPixmap(607,276,14,14,pointpix1_out);
    }



    if (kg2)
    {
        QPainter point2_in(this);
        QPixmap pointpix2_in;
        pointpix2_in.load("./img2/2.png");
        point2_in.drawPixmap(523,309,14,14,pointpix2_in);
    }


    if (out2)
    {
        QPainter point2_out(this);
        QPixmap pointpix2_out;
        pointpix2_out.load("./img2/2.png");
        point2_out.drawPixmap(607,309,14,14,pointpix2_out);
    }



    if (kg3)
    {
        QPainter point3_in(this);
        QPixmap pointpix3_in;
        pointpix3_in.load("./img2/2.png");
        point3_in.drawPixmap(523,342,14,14,pointpix3_in);
    }


    if (out3)
    {
        QPainter point3_out(this);
        QPixmap pointpix3_out;
        pointpix3_out.load("./img2/2.png");
        point3_out.drawPixmap(607,342,14,14,pointpix3_out);
    }



    if (kg4)
    {
        QPainter point4_in(this);
        QPixmap pointpix4_in;
        pointpix4_in.load("./img2/2.png");
        point4_in.drawPixmap(523,374,14,14,pointpix4_in);
    }


    if (out4)
    {
        QPainter point4_out(this);
        QPixmap pointpix4_out;
        pointpix4_out.load("./img2/2.png");
        point4_out.drawPixmap(607,374,14,14,pointpix4_out);
    }


    if (kg5)
    {
        QPainter point5_in(this);
        QPixmap pointpix5_in;
        pointpix5_in.load("./img2/2.png");
        point5_in.drawPixmap(523,407,14,14,pointpix5_in);
    }

    if (out5)
    {
        QPainter point5_out(this);
        QPixmap pointpix5_out;
        pointpix5_out.load("./img2/2.png");
        point5_out.drawPixmap(607,407,14,14,pointpix5_out);
    }



    if (kg6)
    {
        QPainter point6_in(this);
        QPixmap pointpix6_in;
        pointpix6_in.load("./img2/2.png");
        point6_in.drawPixmap(523,440,14,14,pointpix6_in);
    }


    if (out6)
    {
        QPainter point6_out(this);
        QPixmap pointpix6_out;
        pointpix6_out.load("./img2/2.png");
        point6_out.drawPixmap(607,440,14,14,pointpix6_out);
    }


    /********************************************************************************************************/
}

//轴流滚筒堵塞转速 --
void Dialog::on_pushButton_2_clicked()
{
    zl--;
    ui->label->setText(QString::number(zl,10));
}

//轴流滚筒堵塞转速 ++
void Dialog::on_pushButton_3_clicked()
{
    zl++;
    ui->label->setText(QString::number(zl,10));
}

//复脱器堵塞转速 ++
void Dialog::on_pushButton_5_clicked()
{
    ftq++;
    ui->label_2->setText(QString::number(ftq,10));
}

//复脱器堵塞转速 --
void Dialog::on_pushButton_4_clicked()
{
    ftq--;
    ui->label_2->setText(QString::number(ftq,10));
}

//升运器堵塞转速 ++
void Dialog::on_pushButton_7_clicked()
{
    syq++;
    ui->label_3->setText(QString::number(syq,10));
}

//升运器堵塞转速 --
void Dialog::on_pushButton_6_clicked()
{
    syq--;
    ui->label_3->setText(QString::number(syq,10));
}


//时间设置显示
void Dialog::on_pushButton_8_clicked()
{

    tmset.show();
    tmset.exec();
}
