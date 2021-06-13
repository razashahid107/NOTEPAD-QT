#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QtCore>
#include <iostream>
#include <fstream>

using namespace std;

class MyThread: public QThread
{
public:
    MyThread();
    void run();
};

#endif // MYTHREAD_H
