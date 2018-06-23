#include "dlineedit.h"


DLineEdit::DLineEdit(QString id, QWidget *parent) :
    QLineEdit(parent)
{
    EditID=id;
}

QString DLineEdit::getID()
{
    return EditID;
}

DLineEdit::~DLineEdit()
{

}
