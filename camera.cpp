#include "camera.h"
#include "ui_camera.h"
#include <QDebug>

#include<QTime>
#include<QTimer>
#include<QPainter>
#include<QString>

bool ok;

extern  unsigned char wsjtmpflag;

extern unsigned char DC;

uchar numjy = 0;
//extern unsigned char SouSa;
//extern unsigned char tmpflag;

//extern unsigned char KL;
//extern unsigned char SK;





/********************************************************************************************************************/
//正下方图标闪烁

//extern uchar j;
//extern uchar jflag;
//extern unsigned char  mybufflag[15];
//extern unsigned char  myindex[15];





/*******************************************************************************************************************/



/********************************************************************************************************************/
//2016 6.1  wushengjun
//定义变量 控制图标闪烁。
//
/********************************************************************************************************************/
extern uchar j;
extern uchar jflag;
extern uchar mm;
extern uchar jjjflag;
extern unsigned char  mybufflag[15];
extern unsigned char  myindex[15];
extern unsigned char  countBuff;


extern unsigned char flagLeft;  //左转
extern unsigned char countLeft; //左转

extern unsigned char flagBattery;//电瓶指示灯

extern unsigned char flagWidthlamp; //示宽灯

extern unsigned char  flagYG; //远光灯

extern unsigned char  flagSW; //水温

extern unsigned char  flagJG; //近光灯

extern unsigned char  flagJY; //机油

extern unsigned char  flagLCM; //粮仓满

extern unsigned char   flagFDJYR; //发动机预热

extern unsigned char   flagGL; //过滤

extern unsigned char   flagYL; //油量

extern unsigned char  flagYeyayouwen;//液压油温

extern unsigned char    flagECU;//ecu

extern unsigned char    flagPark;//停车

extern unsigned char   flagFDJGZ; //发动机故障

extern unsigned char   flagRight; //右转

extern unsigned char  flagyouxiangman;//油量满报警
extern unsigned char  flagyouliangdi; //油量低报警



extern unsigned char  flagCanfault;//Can 通信故障
extern unsigned char  flagJinqifault;//进气温度传感器故障
extern unsigned char  flagYalisenserfault;//增压压力传感器故障

extern unsigned char  flagSwSenserfault; //水温传感器故障
extern unsigned char  flagTulunzhoufault;//凸轮轴故障
extern unsigned char flagQulunzhoufault;//曲轴故障

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
extern unsigned char DC;  //倒车信号（倒车+） 7,
extern unsigned char SK;  //位置灯（位置灯+） 6,
extern unsigned char SouSa;//手刹指示灯（手刹指示灯+） 5,
extern unsigned char Zuozhuan; //左转向灯（左转向灯）4,
extern unsigned char Youzhuan;  //右转向灯（右转向灯）3,
extern unsigned char YuanGuang; //远光指示灯（远光指示灯） 2,
extern unsigned char Jinguang; //近光指示灯（近光指示灯） 1,


//第二个字节
extern uchar youshuifenli;  //油水分离 6,
extern uchar fadongjiguzhang;//发动机故障 5,
extern uchar yure; //预热 4,
extern uchar liangman; //粮满 3,
extern uchar KL;  //空滤报警开关（空滤-） 2,
extern uchar CongDian; //充电指示灯-  1,


//第三个字节
extern uchar kg6;//开关6 6，
extern uchar kg5;//开关5 5，
extern uchar kg4;//开关4 4,
extern uchar kg3;//开关3 3,
extern uchar kg2;//开关2 2,
extern uchar kg1;//开关1 1,


//第二个字节
extern uchar out6;//输出6 6，
extern uchar out5;//输出5 5,
extern uchar out4;//输出4 4,


//第一个字节
extern uchar out3;//输出3 3,
extern uchar out2;//输出2 2,
extern uchar out1;//输出1 1,

//频率量
extern ushort  shengyunqi;    //升运器
extern ushort  futuoqi;       //复脱器
extern ushort  zhouliuguntong;//轴流滚筒
extern ushort  shisu; //时速

//模拟量
//18FF04F6
extern unsigned char YouLiang;     //油量（油量）
extern unsigned char Yeyayouwen; //液压油油温（液压油油温）
extern unsigned int   MiJi;      //米计（预留）
extern unsigned int   LiCheng;   //里程（预留）


//发动机 数据


//18FEEE00
extern unsigned char SuiWen;//水温；
extern unsigned int  jiyouyali; //机油压力

//0CF00400

extern ushort fadongzhuansu; //发动机转速


//18FECA00
//故障报文
extern ulong guzhangbaowen; //故障报文
extern uint  spn;//spn 码
extern uchar fmi;//fmi 码
//预热指示灯
//18FEE400

extern uchar yurezhishideng;//18FEE400

//小时计
//18FEE500
extern unsigned int XiaoshiJi; //小时计

/********************************************************************************************************************/



camera::camera(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::camera)
{
    ui->setupUi(this);
    resize(800,600);

    QTimer *secondtime = new QTimer(this);
    connect(secondtime, SIGNAL(timeout()), this, SLOT(update()));  //连接信号槽，定时器超时触发窗体更新

    //connect(ui->show_ptn,SIGNAL(clicked()),this,SLOT(start_thread()));

    //connect(ui->stop_ptn,SIGNAL(clicked()),this,SLOT(stop_thread()));

    //connect(ui->quit_ptn,SIGNAL(clicked()),this,SLOT(close()));


    connect(this,SIGNAL(camerastartsignal()),this,SLOT(start_thread()));
    connect(this,SIGNAL(stopcamerasignal()),this,SLOT(stop_thread()));

    /*****************************************************************************/
    //2016.6.30
    //connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(on_pushButton_clicked()));
    secondtime->start(500);
    /*****************************************************************************/



    setWindowFlags(windowFlags()|Qt::FramelessWindowHint|Qt::WindowTitleHint); //删除 最小化、最大化、关闭按钮
    camera::move(0,0);//回到原来主窗口的位置
}

void camera::Daoche()
{
    qDebug()<<"cjjdkjflasdkjflskf"<<DC<<endl;
    this->close();
}


void camera::start_thread()
{
    video = new video_thread();
    video->start();
    connect(video,SIGNAL(image_data(const QImage &)),this,SLOT(show_picture(const QImage &)));

}
void camera::show_picture(const QImage &img)
{


     ui->show_label->setPixmap(QPixmap::fromImage(img));
     ui->show_label->setScaledContents(true);//图片自适应label大小 等比例大小,缩放问题解决。

     //全屏显示 要加条件判断
#if 0
     ui->show_label->resize(img.width(),img.height());
     ui->show_label->move(0,0);
#endif
}
void camera::stop_thread()
{
    delete video;
}


//返回主界面
void camera::on_pushButton_clicked()
{
    ok = false;
    qDebug()<<"camera :: daoche:"<<ok<<DC<<endl;
    this->close();
}

void camera::paintEvent(QPaintEvent *event)
{
    QPainter dp(this);
    QPixmap dppix;
    dppix.load("./img2/camera2.bmp");
    dp.drawPixmap(0,0,800,600,dppix);

//    ui->label->setText(QString::number(SouSa,10));
//    ui->label_2->setText(QString::number(KL,10));
//    ui->label_3->setText(QString::number(SK,10));


/**************************************************************************************************************/
//显示时间 。2016.7.12
    QString timeStr1= QTime::currentTime().toString();     //绘制当前的时间
    QString dateStr1 = QDate::currentDate().toString("yyyy-MM-dd");

    ui->lcdNumber_2->display(dateStr1);
    ui->lcdNumber->display(timeStr1);
/**************************************************************************************************************/
//测试摄像头直接采集图像并显示
//
#if 1
    if ((ok == true)&&(numjy == 0))
    {
         numjy = 1;
         emit camerastartsignal();
    }
    else if ((ok == false)&&(numjy==1))
    {

        numjy = 0;
        qDebug()<<"stopcamera::"<<ok<<DC<<endl;
        emit stopcamerasignal();
    }

#endif



/************************************************************************************************/
//2016.7.8
//加载里程图片
    QPainter paintLicheng(this);
    QPixmap pixLicheng;

    pixLicheng.load("./img2/35.png");//14.jpg
    paintLicheng.drawPixmap(625,380,96,27,pixLicheng);


/************************************************************************************************/

    ui->label->setText(QString::number(YouLiang)); //油量（油量）
    ui->label_2->setText(QString::number(jiyouyali)); //机油压力
    ui->label_3->setText(QString::number(Yeyayouwen));//液压油油温（液压油油温）
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

    ui->label_14->setText(QString::number(fadongzhuansu));

    ui->label_15->setText(QString::number(shisu));
/************************************************************************************************/
    if((DC == 0)&&(wsjtmpflag == 1)) //返回主界面。
    {
        //emit back();
        QMouseEvent* pressdialog=new QMouseEvent(QEvent::MouseButtonPress,QPoint(2,2), Qt::LeftButton,Qt::LeftButton,Qt::NoModifier);
        QApplication::postEvent(ui->pushButton,pressdialog);
        QMouseEvent* releasedialog=new QMouseEvent(QEvent::MouseButtonRelease,QPoint(2,2),Qt::LeftButton,Qt::LeftButton,Qt::NoModifier);
        QApplication::postEvent(ui->pushButton,releasedialog);
        wsjtmpflag = 0;
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

/*****************************************************************************************************/
//2016.7.23
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
 #if 1
                    QPainter paintBuff(this);
                    QPixmap pixBuff;

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
            jjjflag = jflag;
            jflag = 0;



        if (j >= jjjflag)
            j = 0;

        countBuff++;
       // qDebug()<<"countBuff::"<<countBuff<<endl;
        if (countBuff>1)
            countBuff = 0;
        switch(countBuff)
        {
          case 1:
            switch(myindex[j])
            {

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
#endif

}


camera::~camera()
{
    delete ui;
}

void camera::on_pushButton_2_clicked()
{
    this->close();
    dialogset.show();
    dialogset.exec();
    this->show();
}

