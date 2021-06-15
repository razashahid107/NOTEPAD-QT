#include "notepad.h"
#include "ui_notepad.h"

Notepad::Notepad(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Notepad)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);
    QDir qdirectory;
    fstream myfile;
    QString qtfilename = qdirectory.currentPath() + "/login.csv";
    qdirectory.remove(qtfilename);
    for (int n = 1; n < 1000; n++){
        QString tmp = QString::number(n);
    }
}

Notepad::~Notepad()
{
    delete ui;
}

void Notepad::on_save_pushbutton_clicked()
{
    // Pop up to get the address
    QString saveAddres = QFileDialog::getSaveFileName();
    setAddress(saveAddres.toStdString());
    fstream fout;
    string FileName = FileAddress;
    // opens an existing csv file or creates a new file.
    fout.open(FileName, ios::out);
    string name;

    // Insert the data to file
    QString Data = ui->textEdit_notes->toPlainText();
    qDebug() << Data;
    string strData = Data.toStdString();
    fout << strData;
}

void Notepad::on_Copy_push_button_clicked()
{
    ui->textEdit_notes->copy();
}

void Notepad::on_Cut_Push_Button_clicked()
{
    ui->textEdit_notes->cut();
}

void Notepad::on_Paste_Push_Button_clicked()
{
    ui->textEdit_notes->paste();
}


string Notepad::getAddress(){
    return FileAddress;
}

void Notepad::setAddress(string x){
    FileAddress = x;
}

void Notepad::on_save_pushbutton_2_clicked()
{
    fstream fout;
    string FileName;
    if (FileAddress.length() == 0){
        QString saveAddres = QFileDialog::getSaveFileName();
        setAddress(saveAddres.toStdString());
        FileName = FileAddress;
    }
    else {
        FileName = FileAddress;
    }

    // opens an existing csv file or creates a new file.
    fout.open(FileName, ios::out);
    string name;

    // Insert the data to file
    QString Data = ui->textEdit_notes->toPlainText();
    qDebug() << Data;
    string strData = Data.toStdString();
    fout << strData;
}

void Notepad::on_Reminders_clicked()
{
    this->hide();
    Reminders rui;
    rui.setModal(true);
    rui.exec();
}

void Notepad::on_Notes_clicked()      // Events
{

}


void Notepad::on_Open_clicked()
{
    QString saveAddres = QFileDialog::getOpenFileName();
    qDebug() << saveAddres;
    setAddress(saveAddres.toStdString());
    ifstream file;
    string FileName = FileAddress;
//    file.open(FileName);

    QString temp_string = ""; string final_string = "";
//    while (!EOF){
//        temp_string += FileName.readLine();
//        final_string += temp_string;
//    }


    QFile inputFile(QString::fromStdString(FileName));
    if (inputFile.open(QIODevice::ReadOnly))
    {
       QTextStream in(&inputFile);
       while (!in.atEnd())  // indicating unitl not EOF
       {
          QString line = in.readLine();
          final_string += line.toStdString();

       }
//       inputFile.close();
    }
    qDebug() << QString::fromStdString(final_string);


    ui->textEdit_notes->setPlainText(QString::fromStdString(final_string));

    //    plain_text_edit->setPlainText(QString::fromStdString(final_string));
}

void Notepad::on_pushButton_2_clicked()
{
    // will push back to the main window when Logout is clicked
    QDir qdirectory2;
    QString qtfilename = qdirectory2.currentPath() + "/initialscrcheck.csv";
    string filename2 = qtfilename.toStdString();
    qdirectory2.remove(qtfilename);
    this->hide();
    MainWindow mui;
    mui.setModal(true);
    mui.exec();
}


void Notepad::on_pushButton_clicked()
{
    ui->textEdit_notes->undo();
}


void Notepad::on_pushButton_4_clicked()
{
    ui->textEdit_notes->redo();
}

void Notepad::on_Quit_Push_button_clicked()
{
    QCoreApplication::exit();   // allows us to quit the application as a whole
}

