#include "widget.h"
#include "ui_widget.h"

#include"signalcan.h"

#include<QTime>
#include<QTimer>
#include<QPainter>
#include<QDebug>
#include<QEvent>
#include <QDateTime>
#include<QProcess>
#include<iostream>

#include<QMouseEvent>


int num = 0;
int numtmp = 0;


unsigned char wsjtmpflag = 0;

bool OK = false;

extern bool ok;



uchar wsj1 = 0;
uchar wsj2 = 0;
uchar wsj3 = 0;
uchar wsj4 = 0;
/********************************************************************************************************************/
//定义时间变量用于各界面传递
//2016.7.11

QString  Datesetup;
/********************************************************************************************************************/



/********************************************************************************************************************/
//2016 6.1  wushengjun
//定义变量 控制图标闪烁。
//
/********************************************************************************************************************/
uchar j=0;
uchar jflag = 0;
uchar mm=0;
uchar jjjflag = 0;
unsigned char  mybufflag[15] = {0};
unsigned char  myindex[15] = {0};


unsigned char  countBuff = 0;


unsigned char flagLeft = 0;  //左转
unsigned char countLeft = 0; //左转

unsigned char flagBattery = 0;//电瓶指示灯

unsigned char flagWidthlamp = 0; //示宽灯

unsigned char  flagYG = 0; //远光灯

unsigned char  flagSW  = 0; //水温

unsigned char  flagJG = 0; //近光灯

unsigned char  flagJY = 0; //机油

unsigned char  flagLCM = 0; //粮仓满

unsigned char   flagFDJYR = 0; //发动机预热

unsigned char   flagGL = 0; //过滤

unsigned char   flagYL = 0; //油量

unsigned char  flagYeyayouwen = 0;//液压油温

unsigned char    flagECU = 0;//ecu

unsigned char    flagPark = 0;//停车

unsigned char   flagFDJGZ = 0; //发动机故障

unsigned char   flagRight = 0; //右转

unsigned char  flagyouxiangman = 0; //油量满
unsigned char  flagyouliangdi  = 0; // 油量低


unsigned char  flagCanfault = 0;//Can 通信故障
unsigned char  flagJinqifault = 0;//进气温度传感器故障
unsigned char  flagYalisenserfault = 0;//增压压力传感器故障

unsigned char  flagSwSenserfault = 0; //水温传感器故障
unsigned char  flagTulunzhoufault = 0;//凸轮轴故障
unsigned char flagQulunzhoufault = 0;//曲轴故障

/********************************************************************************************************************/


//2016.6.20 wsj
//下面是显示can数据 值的变量
//临时定义，后边产品要更根据情况去改和规范 变量的定义。 有一半的变量可以复用。
/********************************************************************************************************************/
// 最终协议
//2016.7.8
/********************************************************************************************************************/
//开关量
//18FF01F6


//第一个字节
unsigned char DC;  //倒车信号（倒车+） 7,
unsigned char SK;  //位置灯（位置灯+） 6,
unsigned char SouSa;//手刹指示灯（手刹指示灯+） 5,
unsigned char Zuozhuan; //左转向灯（左转向灯）4,
unsigned char Youzhuan;  //右转向灯（右转向灯）3,
unsigned char YuanGuang; //远光指示灯（远光指示灯） 2,
unsigned char Jinguang; //近光指示灯（近光指示灯） 1,


//第二个字节
uchar youshuifenli;  //油水分离 6,
uchar fadongjiguzhang;//发动机故障 5,
uchar yure; //预热 4,
uchar liangman; //粮满 3,
uchar KL;  //空滤报警开关（空滤-） 2,
uchar CongDian; //充电指示灯-  1,


//第三个字节
uchar kg6;//开关6 6，
uchar kg5;//开关5 5，
uchar kg4;//开关4 4,
uchar kg3;//开关3 3,
uchar kg2;//开关2 2,
uchar kg1;//开关1 1,


//第二个字节
uchar out6;//输出6 6，
uchar out5;//输出5 5,
uchar out4;//输出4 4,


//第一个字节
uchar out3;//输出3 3,
uchar out2;//输出2 2,
uchar out1;//输出1 1,

//频率量
ushort  shengyunqi;    //升运器
ushort  futuoqi;       //复脱器
ushort  zhouliuguntong;//轴流滚筒
ushort  shisu; //时速

//模拟量
//18FF04F6
unsigned char YouLiang;     //油量（油量）
unsigned char Yeyayouwen; //液压油油温（液压油油温）
unsigned int   MiJi = 0;      //米计（预留）
unsigned int   LiCheng;   //里程（预留）


//发动机 数据


//18FEEE00
unsigned char SuiWen;//水温；
unsigned int  jiyouyali; //机油压力

//0CF00400

ushort fadongzhuansu; //发动机转速


//18FECA00
//故障报文
ulong guzhangbaowen; //故障报文
uint  spn = 0;//spn 码
uchar fmi = 0;//fmi 码


//预热指示灯
//18FEE400

uchar yurezhishideng;//18FEE400

//小时计
//18FEE500
unsigned int XiaoshiJi; //小时计

/********************************************************************************************************************/

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    setWindowTitle(tr("Haovel"));  //设置窗体名称
    resize(800,600);

    QTimer *timer = new QTimer(this);   //声明一个定时器
   //QTimer *timertst = new QTimer(this);

    //update()会自动产生重绘消息，调用paintEvent()
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));  //连接信号槽，定时器超时触发窗体更新
    connect(timer, SIGNAL(timeout()), this, SLOT(func()));  //连接信号槽，定时器超时触发窗体更新
    timer->start(500);   //启动定时器
    //timertst->start(1000);

    //解析现象，当去掉 setWindowFlags(windowFlags()|Qt::FramelessWindowHint|Qt::WindowTitleHint); 这一句，在开发板子上能显示上方图标，但是不闪烁，
    //不注释则可以在板子上闪烁。
    setWindowFlags(windowFlags()|Qt::FramelessWindowHint|Qt::WindowTitleHint); //删除 最小化、最大化、关闭按钮

    //倒车摄像头信号与槽
    connect(this,SIGNAL(sendcamersignal()),this,SLOT(cameraslot()));


    //线程初始化与启动
    mycan = new SignalCan();
    mycan->start();

    //ui->label->setText(QString::number(flagGL,10));//QString::number()

}



Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{

    QTime time = QTime::currentTime();   //获取当前的时间
    QPainter painter(this);
    QPixmap pix;
    pix.load("./img2/xingzou2.bmp");
    painter.drawPixmap(0,0,800,600,pix);



    int side = qMin(width(), height());  //绘制的范围(宽、高中最小值)

    painter.setRenderHint(QPainter::Antialiasing);//绘制的图像反锯齿
    //painter.translate(width() / 2, height() / 2);//重新定位坐标起始点，把坐标原点放到窗体的中央

    painter.translate(405, 284);//重新定位坐标起始点，把坐标原点放到窗体的中央
    //painter.scale(side / 400.0, side / 300.0);//设定画布的边界,用窗体宽高的最小值来计算时钟的大小，防止窗体拉伸导致的时钟变形以及显示不全




    //下面两个数组用来定义表针的两个顶点，以便后面的填充
    static const QPoint hourHand[4] = {
        QPoint(8, 0),
        QPoint(-8,0),
        QPoint(-1.5, -170),
        QPoint(1.5, -170)
    };
    static const QPoint minuteHand[4] = {
        QPoint(4, 0),
        QPoint(-4, 0),
        QPoint(-1, -100),
        QPoint(1, -100)
    };

    //km r/mini

    painter.setPen(Qt::NoPen);//填充时针，不需要边线所以NoPen
    painter.setBrush(Qt::red);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.save();
    //painter.rotate(6.0 *time.second());  //设旋转(角度 = 6° * (分钟 + 秒 / 60))
    painter.rotate(-120);
    //painter.rotate(6.0 *numtmp);  //设置旋转(6° * 秒)
    //painter.rotate(numtmp++);  //设置旋转(6° * 秒)
    painter.rotate(4.0 *shisu);

    painter.drawConvexPolygon(hourHand, 4);  //填充分针部分

    painter.restore();



    /***********************************************/
    //2016.6.25   画白圈
    painter.setBrush(Qt::darkGray); //画上中心原点/home/vmuser/qtworkplace/chanpin/img2
    painter.save();
    painter.drawEllipse(QPoint(0,0),25,25);
    painter.restore();

    //画白圈
    /***********************************************/

    painter.setBrush(Qt::black);//画上中心原点/home/vmuser/qtworkplace/chanpin/img2
    painter.save();
    painter.drawEllipse(QPoint(0,0),20,20);
    painter.restore();


    //km/h
    painter.translate(0,148);//重新定位坐标起始点，把坐标原点放到窗体的中央
    //painter.scale(side / 400.0, side / 300.0);

    painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::red);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.save();

    //painter.rotate(6.0 *time.second());  //设旋转(角度 = 6° * (分钟 + 秒 / 60))
    painter.rotate(-120);
    painter.rotate(4.0 *shisu);  //设旋转(角度 = 6° * (分钟 + 秒 / 60))
    //内测用
    /****************************************************************************/
    //qDebug()<<"time: "<<time.second()<<endl;

    /****************************************************************************/

    painter.drawConvexPolygon(minuteHand, 4);  //填充分针部分
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.restore();

    /***********************************************/
    //2016.6.25   画白圈
    painter.setBrush(Qt::darkGray); //画上中心原点/home/vmuser/qtworkplace/chanpin/img2
    painter.save();
    painter.drawEllipse(QPoint(0,0),13,13);
    painter.restore();

    //画白圈
    /***********************************************/


    painter.setBrush(Qt::black);
    painter.save();//画上中心原点
    painter.drawEllipse(QPoint(0,0),10,10);
    painter.restore();


    //chuli pupian shansuo
    painter.translate(-405,-432);//平移到左上角

/************************************************************************************************/
//2016.7.8
//加载里程图片
    QPainter paintLicheng(this);
    QPixmap pixLicheng;

    pixLicheng.load("./img2/35.png");//14.jpg
    paintLicheng.drawPixmap(625,380,96,27,pixLicheng);


/************************************************************************************************/
//2016.6.25  定义数值

    ui->label->setText(QString::number(YouLiang)); //油量（油量）
    ui->label_3->setText(QString::number(jiyouyali)); //机油压力
    ui->label_2->setText(QString::number(Yeyayouwen));//液压油油温（液压油油温）
    ui->label_4->setText(QString::number(SuiWen));//水温；
    //ui->label_5->setText(QString::number(KL)); //机油温度
    ui->label_6->setText(QString::number(CongDian));//充放电
    ui->label_7->setText(QString::number(fmi));//FMI
    ui->label_8->setText(QString::number(spn));//SPN

    ui->label_9->setText(QString::number(zhouliuguntong));//轴流滚筒
    ui->label_10->setText(QString::number(futuoqi)); //复脱器
    ui->label_11->setText(QString::number(shengyunqi));//升运器
    ui->label_12->setText(QString::number(MiJi));  //里程
    ui->label_13->setText(QString::number(XiaoshiJi));//小时计

    //加载上方图标 闪烁用到
    //zuo zhuandeng
    QPainter paintLeft(this);
    QPixmap pixLeft;

    if((DC==1)&&(wsjtmpflag == 0))
    {

        //DC = 0;
        //emit sendcamersignal();
         ok = true;

         QMouseEvent* press=new QMouseEvent(QEvent::MouseButtonPress,QPoint(2,2), Qt::LeftButton,Qt::LeftButton,Qt::NoModifier);
         QApplication::postEvent(ui->pushButton_2,press);
         QMouseEvent* release=new QMouseEvent(QEvent::MouseButtonRelease,QPoint(2,2),Qt::LeftButton,Qt::LeftButton,Qt::NoModifier);
         QApplication::postEvent(ui->pushButton_2,release);

         wsjtmpflag = 1;

    }
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


/****************************************************************************************************/
        //故障码解析  后期要单独解析 暂时先放到这。

        if((spn==522000)&&(fmi==12)) //Can 通信故障
        {
            flagCanfault = 1;

        }
        if(((spn==105)&&(fmi ==3))|((spn==105)&&(fmi ==4))) //进气温度传感器故障
        {
            flagJinqifault = 1;
        }
        if(spn == 102)//增压压力传感器故障
        {
            flagYalisenserfault = 1;
        }

        if(spn == 110)//水温传感器故障
        {
            flagSwSenserfault = 1;
        }

        if(spn == 4201)//凸轮轴故障
        {
             flagTulunzhoufault = 1;
        }

        if(spn == 4203)//曲轴故障
        {
             flagQulunzhoufault = 1;
        }



        /*****************************************************************************************************/
        //正下方长方形图标显示
        //2016.7.16

        QPainter paintBuff(this);
        QPixmap pixBuff;

        /**********************************************************************************************************/

                //临时添加 做测试用
                //2016.7.16
                mybufflag[0] = flagSW;//水温报警
                mybufflag[1] = flagJY;//机油  油压报警 0～1 MPa,在0.1 MPa 以下为报警区。

                mybufflag[2] = flagYeyayouwen;//flagYeyayouwen = 1;//液压油温
                mybufflag[3] = flagGL;//空气 过滤阻塞报警

                mybufflag[4] =  flagyouxiangman; //油箱满 报警
                //mybufflag[5] =  ;  //液压油温偏高请检查

                mybufflag[6] =  flagyouliangdi;//及时加油 油量低报警
                mybufflag[7] =  flagCanfault;  //通信故障

                mybufflag[8] = flagPark;//手刹 报警
                mybufflag[9] = flagJinqifault;//进气温度传感器故障

                mybufflag[10] = flagYalisenserfault;//增压压力传感器故障
                mybufflag[11] = flagTulunzhoufault; //凸轮轴故障

                mybufflag[12] =  flagQulunzhoufault;//曲轴故障
                mybufflag[13] =  flagBattery;//蓄电池故障

                mybufflag[14] =  flagSwSenserfault;//水温传感器故障


                //建立索引 对mybufflag进行提取。
                for (mm = 0; mm < 15; mm++)
                {
                    if(mybufflag[mm])
                    {
                        myindex[jflag] = mm;
                        jflag++;

                    }

                }
        /**********************************************************************************************************/

        if(jflag == 0)
        {
            memset(myindex,0,15);
        }


        jjjflag = jflag;
        jflag = 0;

    if (j >= jjjflag)
    {
        j = 0;
        memset(myindex,0,15);
    }
    countBuff++;
    if (countBuff>1)
        countBuff = 0;
    switch(countBuff)
    {
      case 1:
       // printf("===== flagyeyayouwen:: %d,midex[j] = %d\r\n",flagYeyayouwen,myindex[j]);
        switch(myindex[j])
        {
            //qDebug()<<"flagyeyayouwen::"<<flagYeyayouwen<<"  myindex[j]:"<<myindex[j]<<endl;
            case 0:
                 if (flagSW)
                 {
                     pixBuff.load("./img2/41.png");//41.jpg
                     paintBuff.drawPixmap(280,535,255,50,pixBuff); //正下方图标闪烁
                  }
                 break;

            case 1:
                 pixBuff.load("./img2/42.png");//42.jpg
                 paintBuff.drawPixmap(280,535,255,50,pixBuff); //正下方图标闪烁
            break;

            case 2:
                pixBuff.load("./img2/43.png");//43.jpg
                paintBuff.drawPixmap(280,535,255,50,pixBuff); //正下方图标闪烁
            break;

            case 3:
                pixBuff.load("./img2/44.png");//44.jpg
                paintBuff.drawPixmap(280,535,255,50,pixBuff); //正下方图标闪烁
            break;

            case 4:
                 pixBuff.load("./img2/45.png");//45.jpg
                 paintBuff.drawPixmap(280,535,255,50,pixBuff); //正下方图标闪烁
            break;

            case 5:
                 pixBuff.load("./img2/46.png");//46.jpg
                 paintBuff.drawPixmap(280,535,255,50,pixBuff); //正下方图标闪烁
            break;

            case 6:
                pixBuff.load("./img2/47.png");//47.jpg
                paintBuff.drawPixmap(280,535,255,50,pixBuff); //正下方图标闪烁
            break;

            case 7:
                pixBuff.load("./img2/48.png");//48.jpg
                paintBuff.drawPixmap(280,535,255,50,pixBuff); //正下方图标闪烁
            break;


            case 8:
                 pixBuff.load("./img2/49.png");//49.jpg
                 paintBuff.drawPixmap(280,535,255,50,pixBuff); //正下方图标闪烁
            break;

            case 9:
                 pixBuff.load("./img2/50.png");//50.jpg
                 paintBuff.drawPixmap(280,535,255,50,pixBuff); //正下方图标闪烁
            break;

            case 10:
                pixBuff.load("./img2/51.png");//51.jpg
                paintBuff.drawPixmap(280,535,255,50,pixBuff); //正下方图标闪烁
            break;

            case 11:
                pixBuff.load("./img2/52.png");//52.jpg
                paintBuff.drawPixmap(280,535,255,50,pixBuff); //正下方图标闪烁
            break;


            case 12:
                 pixBuff.load("./img2/53.png");//53.jpg
                 paintBuff.drawPixmap(280,535,255,50,pixBuff); //正下方图标闪烁
            break;

            case 13:
                 pixBuff.load("./img2/54.png");//54.jpg
                 paintBuff.drawPixmap(280,535,255,50,pixBuff); //正下方图标闪烁
            break;

            case 14:
                pixBuff.load("./img2/55.png");//55.jpg
                paintBuff.drawPixmap(280,535,255,50,pixBuff); //正下方图标闪烁
            break;

        }
        j++;
        break;
    }
 /******************************************************************************************************/

}


void Widget::func()
{

     QString timeStr= QTime::currentTime().toString();     //绘制当前的时间
     QString dateStr = QDate::currentDate().toString("yyyy-MM-dd");

     ui->lcdNumber_2->display(dateStr);
     ui->lcdNumber->display(timeStr);

     //qDebug()<<"timstr: "<<timeStr<<endl;
     //qDebug()<<"dateStr: "<<dateStr<<endl;
#if 0
     /*设置系统时间*/
     if(OK == true)
     {
     QString str1 = """";
     str1 += "date -s ";
     str1 += Datesetup.left(10);
     str1 += """";

     //system("clock -w");
     system("hwclock --hctosys");
     system(str1.toLatin1().data());

     //时间
     QString str2 = """";
     str2 += "date -s ";
     str2 += Datesetup.mid(11,9);
     str2 += """";
     system(str2.toLatin1().data());
    }
#endif
}

void Widget::on_lineEdit_2_textEdited(const QString &arg1)
{
    bool ok = true;
    numtmp = arg1.toInt(&ok,10);

}
//进入设置界面
void Widget::on_pushButton_clicked()
{
    //this->hide();
    this->close();
    dialog.show();
    dialog.exec();
    this->show();
}


//进入倒车界面 按键
void Widget::on_pushButton_2_clicked()
{
    //this->hide();
    ok = true;
    this->close();
    cameraobj.show();
    cameraobj.exec();

    this->show();
}


//测试用
void Widget::on_lineEdit_2_editingFinished()
{
    QString tmp = ui->lineEdit_2->text();
#if 0
    wsj2 = tmp.toShort();
    wsj4 = wsj2;
#endif
//    flagRight = wsj2;
//    flagGL = wsj2;
//    flagFDJGZ = wsj2;
#if 1
    fadongzhuansu = tmp.toShort();
   // DC = fadongzhuansu;

    //tmpflag = ZhuangSu;
    if(DC >7)
    {
         DC=0;
         ui->lineEdit_2->setText("2");
           //emit sendcamersignal();
//         system(" echo none > /sys/class/leds/led-run/trigger");
//         system("echo 1 > /sys/class/leds/led-run/brightness ");

         QMouseEvent* press=new QMouseEvent(QEvent::MouseButtonPress,QPoint(2,2), Qt::LeftButton,Qt::LeftButton,Qt::NoModifier);
         QApplication::postEvent(ui->pushButton_2,press);
         QMouseEvent* release=new QMouseEvent(QEvent::MouseButtonRelease,QPoint(2,2),Qt::LeftButton,Qt::LeftButton,Qt::NoModifier);
         QApplication::postEvent(ui->pushButton_2,release);

    }
#endif
}


//测试倒车信号来时，显示倒车视频。
//
void Widget::cameraslot()
{
    this->hide();
    //this->close();

    cameraobj.show();
    cameraobj.exec();

    this->show();


    qDebug()<<"daoche:"<<DC<<endl;
}


//void Widget::mousePressEvent(QMouseEvent *e)

//{

//    ui->pushButton_4->setText(tr("(%1,%2)").arg(e->x()).arg(e->y()));

//    if(fadongzhuansu > 7)
//    {

//    }
//}




void Widget::on_lineEdit_3_editingFinished()
{
#if 0
    QString wtmp = ui->lineEdit_3->text();
    int nu2 = wtmp.toInt();
    if(nu2>0)
    {
        wsj1 = 1;
        wsj3 = 1;
//        flagLeft = 1;
//        flagJY = 1;
    }
    else
    {
        wsj1 = 0;
        wsj3 = 0;
//        flagLeft = 0;
//        flagJY = 0;
    }
#endif

}
