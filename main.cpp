#include "widget.h"

#include <QWidget>
#include <QLabel>
#include <QApplication>
#include <QGridLayout>
#include <QFrame>
#include <QLineEdit>
#include <QPushButton>
#include <QGraphicsDropShadowEffect>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Log_Reg window;

    QImage *background = new QImage(":/fone/secwin.jpg");
    QBrush *brush = new QBrush;
    brush->setTextureImage(*background);
    window.setWindowTitle("Log-Reg System");
    window.resize(800, 470);
    QPalette palette;
    palette.setBrush(QPalette::Window, *brush);
    window.setPalette(palette);
    window.show();
    return a.exec();
}

