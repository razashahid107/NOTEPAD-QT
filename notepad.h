#ifndef NOTEPAD_H
#define NOTEPAD_H

#include <QMainWindow>
#include "databasehandler.h"

namespace Ui {
class Notepad;
}

class Notepad : public QMainWindow
{
    Q_OBJECT

public:
    explicit Notepad(QWidget *parent = nullptr);
    ~Notepad();

private slots:
    void on_save_pushbutton_clicked();

private:
    Ui::Notepad *ui;
};

#endif // NOTEPAD_H
