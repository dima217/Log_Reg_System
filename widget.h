#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QtSql>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QImage>

class Log_Reg : public QWidget
{
    Q_OBJECT

public:
    Log_Reg(QWidget *parent = nullptr);
    QLabel* label_make(QString& pcmd);
    QPushButton *end = new QPushButton();
    QPushButton *end_in = new QPushButton();

    QLineEdit *Login;
    QLineEdit *Password;
    QLineEdit *Phone_number;
    QLineEdit *Email;

    QLineEdit *Login_in;
    QLineEdit *Password_in;

    QFrame *border;
    QFrame *choose;
    QFrame *border_Log_in;
private:
    QSqlDatabase database;
public slots:
    void endLog();
    void chooseO();
    void log_Check();
};
#endif // WIDGET_H
