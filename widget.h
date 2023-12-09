#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QtSql>
#include <QSqlDatabase>

class Log_Reg : public QWidget
{
    Q_OBJECT

public:
    Log_Reg(QWidget *parent = nullptr);
    QLabel* label_make(QString& pcmd);
private:
    QSqlDatabase database;
public slots:
    void endLog();
};
#endif // WIDGET_H
