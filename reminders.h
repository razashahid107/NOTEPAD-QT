#ifndef REMINDERS_H
#define REMINDERS_H

#include <QMainWindow>

namespace Ui {
class Reminders;
}

class Reminders : public QMainWindow
{
    Q_OBJECT

public:
    explicit Reminders(QWidget *parent = nullptr);
    ~Reminders();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Reminders *ui;
};

#endif // REMINDERS_H
