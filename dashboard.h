#ifndef DASHBOARD_H
#define DASHBOARD_H
#include "notepad.h"
#include "reminders.h"
#include "events.h"

#include <QMainWindow>

namespace Ui {
class DashBoard;
}

class DashBoard : public QMainWindow
{
    Q_OBJECT

public:
    explicit DashBoard(QWidget *parent = nullptr);
    ~DashBoard();

private slots:
    void on_Note_pb_clicked();

    void on_Events_pb_clicked();

    void on_Reminder_pb_clicked();

    void on_actionLogout_triggered();

private:
    Ui::DashBoard *ui;
};

#endif // DASHBOARD_H
