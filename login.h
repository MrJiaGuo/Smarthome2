#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QTimer>
namespace Ui {
class login;
}

class login : public QWidget
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = 0);
    ~login();

private slots:
    void on_rfidbt_clicked();
    void update_rfid();
    void on_bt1_clicked();

    void on_bt6_clicked();

    void on_bt2_clicked();

    void on_bt3_clicked();

    void on_bt4_clicked();

    void on_bt5_clicked();

    void on_bt7_clicked();

    void on_bt8_clicked();

    void on_bt9_clicked();

    void on_bt0_clicked();

    void on_delete_bt_clicked();

    void on_enter_bt_clicked();

private:
    Ui::login *ui;
    int rfid_fd;
    QTimer *rfid_timer;
};

#endif // LOGIN_H
