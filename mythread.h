#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QtCore>
#include <iostream>
#include <fstream>

using namespace std;

class MyThread:public QThread    // Inherited QThread
{
public:
    MyThread();
    void run();         // Virtual Function Override via QThread Class
};

#endif // MYTHREAD_H
