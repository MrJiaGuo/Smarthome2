#ifndef ADCQTHREAD_H
#define ADCQTHREAD_H
#include <QThread>
#include <QObject>
#include <adcbeep.h>


class AdcQthread : public QThread
{
    Q_OBJECT
public:
    explicit AdcQthread(QObject *parent = 0);
    void run();
signals:
    void isDone(int num);
public slots:

private:
    int adcfd;
};

#endif // ADCQTHREAD_H
