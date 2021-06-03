#include "notepad.h"
#include "ui_notepad.h"

Notepad::Notepad(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Notepad)
{
    ui->setupUi(this);
}

Notepad::~Notepad()
{
    delete ui;
}

void Notepad::on_save_pushbutton_clicked()
{
    QString str = ui->textEdit_notes->toPlainText();
    std::string sstr = str.toStdString();
    qDebug() << str;
}
