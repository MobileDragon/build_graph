#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <QList>
#include <QStack>
#include <QMap>
#include "mypoint.h"
class Calculator//пока без sin cos ex итак далее
{
public:
    Calculator(QString myformul);

    QString broken;
    QString func;
    QList<MyPoint> relationXY;//значения у от х, для построения графика
    QStack<QChar> formul;//стек символов формулы
    void WriteFormul();//переписывание функции в стак отдельных символов для удобства

    //
    QString nameX;//выбирается пользователем
    QString nameY;//узнается калькулятором
    float startX;//нижний предел диапазона значений
    float endX;//веррхний предел диапазона значений
    float step;//шаг изменения аргумента функции(х)

    //
    QList<QString> getListVariable(); //метод получения списка переменных
    //список переменных используется для создания карты их значений
    QList<MyPoint> getPoints();

    QMap<QString,float> arrVariable;//карта на которую опирается калькулятор при вычислении значений
    QMap<QString,float> getArrVariable();//РЕАЛИЗОВАТЬ
    //float getValue(QString name);//получить значение переменной
    bool setArrVariable(QMap<QString,float>);//РЕАЛИЗОВАТЬ
    //метод задания значений коэфициентов-предоставляет карту с именами переменных,
                                                    //для указания их значений
    bool setFunctionArgument(QString name, float start, float end, float step);
    //как узнать переменную, для которой задается диапазон-передается имя сюда^
    //
    float expr();//сумма, низший приоретет
    float factor();//произведение
    float brackets();//выражение под скобками

    float variable();
};

#endif // CALCULATOR_H
