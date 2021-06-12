#ifndef EVENTS_H
#define EVENTS_H

#include <QMainWindow>

namespace Ui {
class Events;
}

class Events : public QMainWindow
{
    Q_OBJECT

public:
    explicit Events(QWidget *parent = nullptr);
    ~Events();

private:
    Ui::Events *ui;
};

#endif // EVENTS_H
