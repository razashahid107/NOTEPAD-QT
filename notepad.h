#ifndef NOTEPAD_H
#define NOTEPAD_H

#include <QDialog>
#include "mainwindow.h"
#include <reminders.h>

using namespace std;

namespace Ui {
class Notepad;
}

class Notepad : public QDialog
{
    Q_OBJECT
private:
    std::string FileAddress = "";

public:
    explicit Notepad(QWidget *parent = nullptr);
    void setAddress(string);
    string getAddress();
    void on_actionOpen_triggered();
    ~Notepad();

private slots:
    void on_save_pushbutton_clicked();

    void on_Copy_push_button_clicked();

    void on_save_pushbutton_2_clicked();

    void on_Cut_Push_Button_clicked();

    void on_Paste_Push_Button_clicked();

    void on_Reminders_clicked();

    void on_Notes_clicked();

    void on_pushButton_clicked();

    void on_Open_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::Notepad *ui;
};

#endif // NOTEPAD_H
