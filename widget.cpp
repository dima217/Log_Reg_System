#include "widget.h"
#include <QWidget>
#include <QLabel>
#include <QApplication>
#include <QGridLayout>
#include <QFrame>
#include <QLineEdit>
#include <QPushButton>
#include <QGraphicsDropShadowEffect>
#include <QMessageBox>
#include <QDebug>

Log_Reg::Log_Reg(QWidget *parent)
    : QWidget(parent) {

    // Поле для кнопок
    choose = new QFrame(this);
    choose->setStyleSheet("border-style: outset; border-width: 2px; border-radius: 10px; border-color: white; padding: 4px;");
    QGridLayout* ptop = new QGridLayout();
    ptop->setContentsMargins(5, 5, 5, 5);
    ptop->setSpacing(15);
    choose->resize(250,50);

    QPushButton *sing_up = new QPushButton("Sing up");
    connect(sing_up, SIGNAL(clicked()), SLOT(chooseO()));

    sing_up->setStyleSheet("border-color: white; background-color: white; font: 10pt Tw Cen MT Condensed Extra Bold;");
    QGraphicsDropShadowEffect *shado = new QGraphicsDropShadowEffect();
    QGraphicsDropShadowEffect *shad = new QGraphicsDropShadowEffect();
    sing_up->setGraphicsEffect(shado);

    QPushButton *log_in = new QPushButton("Log in");
    connect(log_in, SIGNAL(clicked()), SLOT(chooseO()));

    log_in->setStyleSheet("border-color: white; background-color: white; font: 10pt Tw Cen MT Condensed Extra Bold;");
    log_in->setGraphicsEffect(shad);

    ptop->addWidget(sing_up, 0, 0);
    ptop->addWidget(log_in, 0, 1);
    choose->setLayout(ptop);
    choose->move(530, 307);
    choose->setAutoFillBackground(true);

    qDebug() << QSqlDatabase::drivers();


    // Поле для регеcтрации
    border = new QFrame(this);
    border->setStyleSheet("border-style: outset; border-width: 2px; border-radius: 10px; border-color: white; padding: 4px;");

    border->setLineWidth(10);
    border->resize(250, 235);
    border->move(530, 50);
    border->setAutoFillBackground(true);

    QGridLayout* ptopLayout = new QGridLayout();
    ptopLayout->setContentsMargins(10, 10, 10, 10);
    ptopLayout->setSpacing(15);

    QString log_line_field[4] = {"Login:", "Password:", "Phone number:", "Email:"};

    for (int i = 0; i < 4; i++) {
        QLabel* pcmd = label_make(log_line_field[i]);
        ptopLayout->addWidget(pcmd, i, 0);
    }

    Login = new QLineEdit();
     ptopLayout->addWidget(Login, 0, 1);
    Password = new QLineEdit();
     Password->setEchoMode(QLineEdit::Password);
     ptopLayout->addWidget(Password, 1, 1);
    Phone_number = new QLineEdit();
     ptopLayout->addWidget(Phone_number, 2, 1);
    Email = new QLineEdit();
    ptopLayout->addWidget(Email, 3, 1);

    end->setText("Sing up");
    end->setStyleSheet("background-color: white; border: 2px white; font: 10pt Tw Cen MT Condensed Extra Bold;");
    QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect();
    end->setGraphicsEffect(shadow);
    ptopLayout->addWidget(end, 4, 0, 1, 2);

    connect(end, SIGNAL(clicked()), SLOT(endLog()));


    border->setLayout(ptopLayout);

    // Поле для входа
    border_Log_in = new QFrame(this);
    border_Log_in->resize(250,235);
    border_Log_in->move(530, 50);
    ptop->setContentsMargins(5, 5, 5, 5);
    ptop->setSpacing(15);
    QGridLayout *ptopLayout1 = new QGridLayout();
    QString login_line_field[4] = {"Login:", "Password:"};

    for (int i = 0; i < 2; i++) {
        QLabel* pcmd = label_make(login_line_field[i]);
        ptopLayout1->addWidget(pcmd, i, 0);
    }
    border_Log_in->setStyleSheet("border-style: outset; border-width: 2px; border-radius: 10px; border-color: white; padding: 4px;");
    Login_in = new QLineEdit();
    ptopLayout1->addWidget(Login_in, 0, 1);
    Password_in = new QLineEdit();
    Password_in->setEchoMode(QLineEdit::Password);
    ptopLayout1->addWidget(Password_in, 1, 1);
    border_Log_in->setLayout(ptopLayout1);

    end_in->setText("Log in");
    end_in->setStyleSheet("background-color: white; border: 2px white; font: 10pt Tw Cen MT Condensed Extra Bold;");
    QGraphicsDropShadowEffect *shadow_in = new QGraphicsDropShadowEffect();
    end_in->setGraphicsEffect(shadow_in);
    connect(end_in, SIGNAL(clicked()), SLOT(log_Check()));
    ptopLayout1->addWidget(end_in, 3, 0, 1, 2);

    border_Log_in->hide();
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
    database.setUserName("newuser");
    database.setPassword("Sp88Lp2k88");
    database.setDatabaseName("usersbase");

    if(database.open()) {
       qDebug() << "Secsses";

        QString login = Login->text();
        QString password = Password->text();
        QString phone_number = Phone_number->text();
        QString email = Email->text();

        QSqlQuery qry;
        qry.prepare("INSERT INTO usersbase.users (Login, Password, Phone, Email)"
                    "VALUES(:Login, :Password, :Phone, :Email)");

        qry.bindValue(":Login", login);
        qry.bindValue(":Password", password);
        qry.bindValue(":Phone", phone_number);
        qry.bindValue(":Email", email);

        if(qry.exec()) {
            QMessageBox::information(this, "Inserted", "Successfully");
        }
        else {
            QMessageBox::information(this, "Not Inserted", "Unsuccessfully");
            qDebug() << qry.lastError().text();
        }
    }
    else {
        qDebug() << "Failed";
        QMessageBox::information(this, "Not Connected", "Database Is Not Connected");
        //QSqlDatabase::lastError()
        qDebug() << database.lastError().text();
    }
}

void Log_Reg::log_Check() {
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setUserName("newuser");
    db.setPassword("Sp88Lp2k88");
    db.setDatabaseName("usersbase");

    QString login = Login_in->text();
    QString password = Password_in->text();

    if (db.open()) {
    QSqlQuery query;

    query.prepare(QString("SELECT *FROM usersbase.users WHERE Login = :Login AND Password = :Password"));

    query.bindValue(":Login", login);
    query.bindValue(":Password", password);

    if (!query.exec()) {

        QMessageBox::information(this, "Failed", "Query is not execute");
        qDebug() << query.lastError().text();

    } else {

        while(query.next()) {

            QString loginFromDB = query.value(1).toString();
            QString passwordFromDB = query.value(2).toString();

            if (loginFromDB == login && passwordFromDB == password) {
                QMessageBox::information(this, "Seccess", "Login success!");
            }
            else {
                QMessageBox::information(this, "Failed", "Login Failed!");
            }
        }
    }

    } else {
        QMessageBox::information(this, "Error", "Database connection failed");
    }

}

void Log_Reg::chooseO() {
    QPushButton *button = (QPushButton*)sender();
    QString but = button->text();
    if (but == end->text()) {
        border_Log_in->hide();
        border->show();
   }
    else {
        border->hide();
        border_Log_in->show();
    }
}

