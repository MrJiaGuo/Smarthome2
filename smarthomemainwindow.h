#ifndef SMARTHOMEMAINWINDOW_H
#define SMARTHOMEMAINWINDOW_H

#include <QWidget>
#include <QTimer>

namespace Ui {
class SmartHomeMainWindow;
}

class SmartHomeMainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit SmartHomeMainWindow(QWidget *parent = 0);
    ~SmartHomeMainWindow();

private slots:
    void on_cameraBt_clicked();
    
    void on_pushButton_clicked();

    void on_recordBt_clicked();

    void update_dht11();

    void ir_dealDone(int num);//ir

private:
    Ui::SmartHomeMainWindow *ui;
    QTimer *DHT11_Timer;
    int dht11_fd;
};

#endif // SMARTHOMEMAINWINDOW_H
