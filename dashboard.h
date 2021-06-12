#ifndef DASHBOARD_H
#define DASHBOARD_H
#include "notepad.h"
#include "reminders.h"

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

private:
    Reminders *rui;
    Notepad *nui;
    Ui::DashBoard *ui;
};

#endif // DASHBOARD_H
