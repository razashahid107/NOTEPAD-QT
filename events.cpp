#include "events.h"
#include "ui_events.h"

Events::Events(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Events)
{
    ui->setupUi(this);
}

Events::~Events()
{
    delete ui;
}

void Events::on_reminderTitle_blockCountChanged(int newBlockCount)
{
    QDir Location;
    Location.currentPath();
}


void Events::on_pushButton_clicked()
{
        // Pop up to get the address
        QString saveAddres = QFileDialog::getSaveFileName();
//        setAddress(saveAddres.toStdString());
        // qDebug() << saveAddres;
        fstream fout;

//        string FileName = FileAddress;
        // opens an existing csv file or creates a new file.
//        fout.open(FileName, ios::out);
        string name;

        // Insert the data to file
//        QString Data = ui->textEdit_notes->toPlainText();
//        qDebug() << Data;
//        string strData = Data.toStdString();
//        fout << strData;
}

