#ifndef DASHBOARD_H
#define DASHBOARD_H
#include <QDialog>
#include "notepad.h"
#include "reminders.h"
#include "events.h"
namespace Ui {class DashBoard;}class DashBoard : public QDialog
{    Q_OBJECT
 public:
     explicit DashBoard(QWidget *parent = nullptr);
     ~DashBoard();
 private slots:
     void on_Note_pb_clicked();
     void on_Events_pb_clicked();
     void on_Reminder_pb_clicked();
     void on_Tasks_pb_2_clicked();  // quit wala button
 private:
      Ui::DashBoard *ui;
};

#endif // DASHBOARD_H
