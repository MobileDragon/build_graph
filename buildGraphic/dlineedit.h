#ifndef DLINEEDIT_H
#define DLINEEDIT_H

#include <QLineEdit>

class DLineEdit : public QLineEdit
{
public:
    DLineEdit();

    explicit DLineEdit(QString id, QWidget *parent = 0);
    ~DLineEdit();
    //static int ResID;   // Статическая переменная, счетчик номеров кнопок
    QString getID();

public slots:
private:
    QString EditID = 0;   // Локальная переменная, номер кнопки
};

#endif // DLINEEDIT_H
