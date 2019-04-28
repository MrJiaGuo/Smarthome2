#ifndef IRQTHREAD_H
#define IRQTHREAD_H

#include <QObject>
#include <QThread>
class IrQthread : public QThread
{
    Q_OBJECT
public:
    explicit IrQthread(QObject *parent = 0);
    void run();
signals:
    void ir_isDone(int num);
public slots:

private:
    int ir_fd;
};

#endif // IRQTHREAD_H
