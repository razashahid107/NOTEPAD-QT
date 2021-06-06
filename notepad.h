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

    void on_actionCopy_triggered();

    void on_actionCut_triggered();

    void on_actionPaste_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_actionLogout_triggered();

    void on_actionSave_triggered();

private:
    Ui::Notepad *ui;
};

#endif // NOTEPAD_H
