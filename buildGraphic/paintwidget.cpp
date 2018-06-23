#include "paintwidget.h"
PaintWidget::PaintWidget(QWidget *parent) : QWidget(parent)
{
    setMouseTracking(true);
    size=45;
    borderSide=30;
    //
    nameY="Y";
    nameX="X";
    startRangeX=15;
    endRangeX=30;
    startRangeY=0;
    endRangeY=2;

    mousPos.setX(30);
    mousPos.setY(30);
    //
    /*
    MyPoint a;
    a.x=15;
    a.y=1;
    relationXY.append(a);
    a.x=16;
    a.y=1;
    relationXY.append(a);
    a.x=17;
    a.y=1;
    relationXY.append(a);
    a.x=18;
    a.y=1;
    relationXY.append(a);
    a.x=19;
    a.y=2;
    relationXY.append(a);
    */
    setFunction("1.1=y");
}
/*
PaintWidget::PaintWidget(QString x, QString y, QWidget *parent) : QWidget(parent)
{

}*/

PaintWidget::~PaintWidget()
{

}


void PaintWidget::setNameAxes(QString x,QString y)
{
    nameX=x;
    nameY=y;
}

void PaintWidget::setRangeX_axis(int start, int end)
{
    startRangeX=start;
    endRangeX=end;
}

void PaintWidget::setRangeY_axis(int start, int end)
{
    startRangeY=start;
    endRangeY=end;
}
//
void PaintWidget::drawGraphic(QPainter &painter)
{

    int kol=relationXY.size();
    for(int i=0; i<kol; i++)
    {
        painter.drawPoint( getPhysicPos(relationXY[i]) );
    }

}

//
void PaintWidget::paintAxis(QPainter &painter)
{
    int sizeDevision=5;

    painter.setPen(QPen(Qt::black,2,Qt::SolidLine));
    setFont(QFont("Arial", 12, 100, 0));
    //
    width=borderSide*2+(endRangeX-startRangeX)*size;
    height=borderSide*2+(endRangeY-startRangeY)*size;

    painter.drawLine(borderSide,height-borderSide,width,height-borderSide);//X
    painter.drawLine(width,height-borderSide,width-sizeDevision,height-borderSide-(sizeDevision/2));
    painter.drawLine(width,height-borderSide,width-sizeDevision,height-borderSide+(sizeDevision/2));
    painter.drawText(width-10,height-borderSide+17,nameX);

    painter.drawLine(borderSide,height-borderSide,borderSide,0);//Y
    painter.drawLine(borderSide,0,borderSide-(sizeDevision/2),sizeDevision);
    painter.drawLine(borderSide,0,borderSide+(sizeDevision/2),sizeDevision);
    painter.drawText(borderSide-15,15,nameY);

    //разметка
    //painter.drawText(5,height-10,"0");
    //X
    int kol=endRangeX-startRangeX+1;
    for(int i=0; i<kol; i++)
    {
        int pos=i*size+borderSide;
        painter.drawLine(pos,height-borderSide,pos,height-borderSide+sizeDevision);
        QString str;
        painter.drawText(pos-7,height-borderSide+sizeDevision+15,str.setNum(startRangeX+i) );
        //(QString).setNum(startRangeX+i)
    }
    //Y
    kol=endRangeY-startRangeY+1;
    for(int i=0; i<kol; i++)
    {
        int pos=height-i*size-borderSide;
        painter.drawLine(borderSide-sizeDevision,pos,borderSide,pos);
        QString str;
        painter.drawText(borderSide-sizeDevision-23,pos+5,str.setNum(startRangeY+i));
        //(QString).setNum(startRangeX+i)
    }

}

//

void PaintWidget::paintFirst()
{
    QPainter painter(this);
    painter.setPen(QPen(Qt::black,2,Qt::SolidLine));
    setFont(QFont("Arial", 12, 100, 0));
    //
    //painter.drawLine(10,3,20,30);
    this->update();
}

bool PaintWidget::setFunction(QString func)
{
    fuction=func;
    calc=new Calculator(fuction);
    relationXY=calc->getPoints();
    return true;//на случай ошибки
}

void PaintWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
    QPainter painter(this);
    painter.setPen(QPen(Qt::black,2,Qt::SolidLine));
    setFont(QFont("Arial", 12, 100, 0));

    //painter.drawLine(10,3,1000,10);
    //QString position=QString("[ %1 : %2 ]").arg(mousPos.x()).arg(mousPos.y());


    //
    MyPoint h=getAbstractPos(mousPos);
    QString position=QString("[ %1 : %2 ]").arg( QString::number(h.x, 'f', 2) ).arg( QString::number(h.y, 'f', 2) );
    //

    painter.drawText(mousPos.x(),mousPos.y() ,position);

    paintAxis(painter);
    if(!fuction.isEmpty())
        drawGraphic(painter);

}

 void PaintWidget::mouseMoveEvent(QMouseEvent *event)
{
    mousPos=event->pos();
    //
    MyPoint h=getAbstractPos(mousPos);
    mousPos=getPhysicPos(h);
    //
    //int posX=5;
    //int posY=34;
    //QString position=QString("[ %1: %2 ]").arg(posX, posY);

    //QPainter painter(this);
    //painter.setPen(QPen(Qt::red,2,Qt::SolidLine));
    //setFont(QFont("Arial", 12, 100, 0));
    //
    //painter.drawText(event->pos().x(),event->pos().y(),position);
    //
    //painter.drawText(5,10,"000000");

    this->update();//обновить
    event->accept();//не пускать дальше событие

}

 //
MyPoint PaintWidget::getAbstractPos(QPoint &p)//возвращает дробное значение
{
    MyPoint abstrct;
    abstrct.x=(p.x()-borderSide)/1.0/size+startRangeX;
    abstrct.y=(height-p.y()-borderSide)/1.0/size+startRangeY;

    return abstrct;
}

QPoint PaintWidget::getPhysicPos(MyPoint &p)//возвращает целые значения на виджете
{
    QPoint physic;
    physic.setX( (p.x-startRangeX)*size+borderSide );
    physic.setY( height-(p.y-startRangeY)*size-borderSide );

    return physic;
}
