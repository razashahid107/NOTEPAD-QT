#include "events.h"
#include "ui_events.h"

Events::Events(QWidget *parent) :
    QDialog(parent),
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
//        QString saveAddres = QFileDialog::getSaveFileName();


        int counter;
        fstream fout;
        string counter_Address = "C:/Users/User/OneDrive - National University of Sciences & Technology/Uni STUDY/Semester 2/OOP/OOP Proj/NOTEPAD 2/NOTEPAD-QT/Sample Events/counter.txt";
        // opens counter.txt where the counter exists for filename
        fout.open(counter_Address, ios::out);
        ifstream file;
        QString temp_string = ""; string final_string = "";
        QFile inputFile(QString::fromStdString(counter_Address));
        if (inputFile.open(QIODevice::ReadOnly))
        {
           QTextStream in(&inputFile);
           while (!in.atEnd())  // indicating unitl not EOF
           {
              QString line = in.readLine();
              final_string += line.toStdString();
           }
        }
        counter = stoi(final_string);
        counter++;
        fout << to_string(counter);

        // now we shift to writing the event
        string Address = "C:/Users/User/OneDrive - National University of Sciences & Technology/Uni STUDY/Semester 2/OOP/OOP Proj/NOTEPAD 2/NOTEPAD-QT/Sample Events/" + to_string(counter) + ".txt";
        fout.open(Address, ios::out);



        // Insert the data to file
        QString Data = ui->Current_Event->toPlainText();
//        qDebug() << Data;
        string strData = Data.toStdString();
        fout << strData;



        temp_string = ""; final_string = "";
        string Prev_File_Add = "C:/Users/User/OneDrive - National University of Sciences & Technology/Uni STUDY/Semester 2/OOP/OOP Proj/NOTEPAD 2/NOTEPAD-QT/Sample Events/" + to_string(counter - 1) + ".txt";
        QFile inputFile2(QString::fromStdString(Prev_File_Add));
        if (inputFile2.open(QIODevice::ReadOnly))
        {
           QTextStream in(&inputFile2);
           while (!in.atEnd())  // indicating unitl not EOF
           {
              QString line = in.readLine();
              final_string += line.toStdString();
           }
        }

        string prev_note_string = final_string;

        // we'll put the previous note which will be counter - 1 .txt
        if (counter < 2){
             ui->Previous_Event->setPlainText("***NO PREVIOUS NOTES***");
        }
        else {

            ui->Previous_Event->setPlainText(QString::fromStdString(prev_note_string));
        }


        QString Prev_Data = ui->Previous_Event->toPlainText();

}
