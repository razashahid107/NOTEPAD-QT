#include "welcome.h"
#include "ui_welcome.h"

Welcome::Welcome(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Welcome)
{
    ui->setupUi(this);
    this->setWindowTitle("Welcome Screen");
    this->setWindowState(Qt::WindowMaximized);
    QDir qdirectory;
    fstream myfile;
    QString qtfilename = qdirectory.currentPath() + "/login.csv";
    qdirectory.remove(qtfilename);
}

Welcome::~Welcome()
{
    delete ui;
}

void Welcome::on_pushButton_clicked()
{
    MainWindow mui;
    mui.setModal(true);
    mui.exec();
    hide();
}
