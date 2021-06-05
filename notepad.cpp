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


void Notepad::on_actionCopy_triggered()
{
    ui->textEdit_notes->copy();
}


void Notepad::on_actionCut_triggered()
{
    ui->textEdit_notes->cut();
}


void Notepad::on_actionPaste_triggered()
{
    ui->textEdit_notes->paste();
}


void Notepad::on_actionUndo_triggered()
{
    ui->textEdit_notes->undo();
}


void Notepad::on_actionRedo_triggered()
{
    ui->textEdit_notes->redo();
}

