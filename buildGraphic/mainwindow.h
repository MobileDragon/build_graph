#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>
#include <QTextEdit>
#include <QSpacerItem>
#include <QLineEdit>

#include "paintwidget.h"
#include "dlineedit.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void buidPanel();

private:
    Ui::MainWindow *ui;

    void SetNewVal();
};

#endif // MAINWINDOW_H
