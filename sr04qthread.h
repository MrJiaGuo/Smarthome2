#ifndef SR04QTHREAD_H
#define SR04QTHREAD_H

#include <QObject>
#include <QThread>
class SR04Qthread : public QThread
{
    Q_OBJECT
public:
    explicit SR04Qthread(QObject *parent = 0);
    void run();
signals:
    void SR04_isDone(int num);
public slots:

private:
    int sr04fd;
};

#endif // SR04QTHREAD_H
