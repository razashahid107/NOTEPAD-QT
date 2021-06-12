#ifndef EVENTS_H
#define EVENTS_H

#include <QMainWindow>
#include <QDir>
#include <mainwindow.h>

namespace Ui {
class Events;
}

class Events : public QMainWindow
{
    Q_OBJECT

public:
    explicit Events(QWidget *parent = nullptr);
    ~Events();

private slots:
    void on_reminderTitle_blockCountChanged(int newBlockCount);

    void on_pushButton_clicked();

private:
    Ui::Events *ui;
};

#endif // EVENTS_H
