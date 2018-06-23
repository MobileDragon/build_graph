#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    PaintWidget *w= new PaintWidget;
    //QWidget *w=new QWidget;
    w->setMinimumHeight(100);
    w->setMinimumWidth(100);


    ui->verticalLayout->addWidget(w);
    ui->verticalLayout->setMargin(0);
    //


    //buidPanel();
    //ui->verticalLayout_2->setSizeConstraint();
    //w->paintFirst();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::buidPanel()
{
    QGridLayout *panel = new QGridLayout;
    panel->SetMaximumSize;
    QLabel *funkL=new QLabel("Функция:");
    funkL->setMaximumWidth(65);
    panel->addWidget(funkL, 0, 0);
    QLineEdit *funcE=new QLineEdit();
    funcE->setMaximumWidth(150);
    panel->addWidget(funcE, 0, 1, 1, 2);
    QPushButton *make1B = new QPushButton("Продолжить");
    make1B->setMaximumWidth(215);
    panel->addWidget(make1B, 1, 0, 1, 3);
    //panel->addWidget(button4, 2, 0);
    //panel->addWidget(button5, 2, 1);

    ui->verticalLayout_2->addLayout(panel);
    QSpacerItem *space1 = new QSpacerItem(3,16);
    ui->verticalLayout_2->addSpacerItem(space1);

}

void MainWindow::SetNewVal()
{
    DLineEdit *button = (DLineEdit*) sender();
}
