#ifndef EVENTS_H
#define EVENTS_H

#include <QDialog>
#include <mainwindow.h>

namespace Ui {
class Events;
}

class Events : public QDialog
{
    Q_OBJECT

public:
    explicit Events(QWidget *parent = nullptr);
    ~Events();

private slots:
    void on_reminderTitle_blockCountChanged(int newBlockCount);

    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    static int counter;
    Ui::Events *ui;
};

#endif // EVENTS_H
