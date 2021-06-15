#ifndef WELCOME_H
#define WELCOME_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class Welcome;
}

class Welcome : public QDialog
{
    Q_OBJECT

public:
    explicit Welcome(QWidget *parent = nullptr);
    ~Welcome();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Welcome *ui;
};

#endif // WELCOME_H
