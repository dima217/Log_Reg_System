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
    window.setWindowTitle("Log-Reg System");
    window.resize(800, 470);
    QPalette palette;
    palette.setBrush(window.backgroundRole(), QBrush(QPixmap(":/fone/secwin.jpg")));
    window.setPalette(palette);
    window.show();
    return a.exec();
}

