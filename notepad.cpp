#include "notepad.h"
#include "ui_notepad.h"
#include "mainwindow.h"
#include "QDir"

Notepad::Notepad(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Notepad)
{

    ui->setupUi(this);
    QDir qdirectory;
    fstream myfile;
    QString qtfilename = qdirectory.currentPath() + "/login.csv";
    qdirectory.remove(qtfilename);
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


void Notepad::on_actionLogout_triggered()
{
    // will push back to the main window when Logout is clicked
    MainWindow *mui;
    mui = new MainWindow(this);
    mui->show();
    hide();
}


void Notepad::on_actionSave_triggered()
{
//    QFile file(QDir::current().absolutePath() + "/peatefinal.txt");
//    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
//    qDebug() << QDir::current().absolutePath();
}

