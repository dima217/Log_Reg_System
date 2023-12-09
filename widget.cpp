#include "widget.h"
#include <QWidget>
#include <QLabel>
#include <QApplication>
#include <QGridLayout>
#include <QFrame>
#include <QLineEdit>
#include <QPushButton>
#include <QGraphicsDropShadowEffect>
#include <QDebug>

Log_Reg::Log_Reg(QWidget *parent)
    : QWidget(parent) {

    qDebug() << QSqlDatabase::drivers();
    QFrame *border = new QFrame(this);

    border->setStyleSheet("border-style: outset; border-width: 2px; border-radius: 10px; border-color: white; padding: 4px;");

    QPalette pall;
    pall.setColor(border->backgroundRole(), Qt::blue);
    border->setPalette(pall);

    border->setLineWidth(10);
    border->resize(250, 235);
    border->move(530, 50);
    border->setAutoFillBackground(true);

    QGridLayout* ptopLayout = new QGridLayout();
    ptopLayout->setContentsMargins(10, 10, 10, 10);
    ptopLayout->setSpacing(15);

    QString log_field[4] = {"Login:", "Password:", "Phone number:", "Email:"};
    for (int i = 0; i < 4; i++) {
        QLabel* pcmd = label_make(log_field[i]);
        ptopLayout->addWidget(pcmd, i, 0);
    }

    for (int i = 0; i < 4; i++) {
    QLineEdit *e = new QLineEdit();
    ptopLayout->addWidget(e, i, 1);
    }

    QPushButton *end = new QPushButton();
    end->setText("Log in");
    end->setStyleSheet("background-color: white; border: 2px white; font: 10pt Tw Cen MT Condensed Extra Bold;");
    QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect();
    end->setGraphicsEffect(shadow);
    ptopLayout->addWidget(end, 4, 0, 1, 2);

    connect(end, SIGNAL(clicked()), SLOT(endLog()));

    border->setLayout(ptopLayout);
}

QLabel* Log_Reg::label_make(QString& pcmd) {
  QLabel *label = new QLabel();
  label->setText(pcmd);
  label->setStyleSheet("font-size: 15px; color: white; 	font: 75 10pt Perpetua Titling MT;");

  return label;
}

void Log_Reg::endLog() {
    database = QSqlDatabase::addDatabase("QMYSQL");
    database.setHostName("localhost");
    database.setUserName("root");
    database.setPassword("");
    database.setDatabaseName("usersbase");

    if(database.open()) {
       qDebug() << "Secsses";
    }
}


