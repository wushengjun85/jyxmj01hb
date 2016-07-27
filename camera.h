#ifndef CAMERA_H
#define CAMERA_H
#include"camera_thread.h"
#include"dialog.h"


#include <QImage>
#include <QPixmap>
#include <QCloseEvent>
#include <QDialog>

namespace Ui {
class camera;
}

class camera : public QDialog
{
    Q_OBJECT
    
public:
    explicit camera(QWidget *parent = 0);
    ~camera();

public slots:
   void show_picture(const QImage &img);
   void start_thread(void);
   void stop_thread();


    
private slots:
   void on_pushButton_clicked();
   void Daoche();



   void on_pushButton_2_clicked();

private:
    Ui::camera *ui;
    video_thread *video;

    Dialog dialogset;

protected:
    void paintEvent(QPaintEvent *event);

signals:
    void back();
    void clicked();
    void camerastartsignal();

    void stopcamerasignal();
};

#endif // CAMERA_H
