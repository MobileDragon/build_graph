#ifndef PAINTWIDGET_H
#define PAINTWIDGET_H

#include <QWidget>

#include <QLine>
#include <QPainter>
#include <QMouseEvent>
#include "mypoint.h"
#include "calculator.h"

class PaintWidget : public QWidget
{
    Q_OBJECT


public:
    Calculator* calc;
    QString nameY;
    QString nameX;
    QString fuction;
    int startRangeX;
    int endRangeX;
    int startRangeY;
    int endRangeY;
    int size;//множитель увеличения
    int borderSide;//отступы для цыфр

    QList<MyPoint> relationXY;//карта точек
    //
    QPoint mousPos;
    //
    int width;
    int height;

    explicit PaintWidget(QWidget *parent = 0);

    void setNameAxes(QString x,QString y);//название осей
    void setRangeX_axis(int start, int end);
    void setRangeY_axis(int start, int end);
    //
    MyPoint getAbstractPos(QPoint& p);
    QPoint getPhysicPos(MyPoint& p);

    //PaintWidget(QString x,QString y,QWidget *parent = 0);
    ~PaintWidget();
    bool setFunction(QString func);//запись функции

    void paintFirst();//построение координатной оси
    void drawGraphic(QPainter &painter);//нанесение relationXY на график

    void paintAxis(QPainter &painter);//построение осей

    virtual void paintEvent(QPaintEvent *event);
    virtual  void mouseMoveEvent(QMouseEvent *event);

signals:

public slots:
};

#endif // PAINTWIDGET_H
