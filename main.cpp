#include "mainwindow.h"
#include "transparant.h"

#include <QApplication>
#include <QScreen>
#include <QDebug>
#include <QLabel>
#include <QSysInfo>
#include <QHostInfo>
#include <QNetworkInterface>
#include <QTextEdit>
#include <QFontMetrics>

#include <algorithm>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

    QScreen *screen = QApplication::primaryScreen();
    QRect rect = screen->geometry();
    int width = rect.width();
    int height = rect.height();

    QLabel label("???");
    label.setStyleSheet("QLabel {color: yellow; font-size:100px;}");
    label.setWindowFlags(Qt::Tool | Qt::FramelessWindowHint);
    label.setAttribute(Qt::WA_TranslucentBackground);
    label.setWindowFlag(Qt::WindowStaysOnBottomHint);

//    int posX = rect.x();
//    int posY = rect.y();
    label.move(width/2 - label.width()/2, height/5);
    label.setText(QSysInfo::machineHostName());
    label.setScreen(screen);
    label.show();

    QFontMetrics fm(label.font());
    int pixelsWide = fm.horizontalAdvance(label.text());
    int pixelsHigh = fm.height();
    qDebug() << pixelsWide;
    qDebug() << pixelsHigh;
    label.resize(pixelsWide, pixelsHigh);
    label.move(width/2 - label.width()/2, height/5);

    qDebug() << "----------";
    qDebug() << QHostInfo::localHostName();
    qDebug() << QHostInfo::localDomainName();

    QString msg;
    QList<QNetworkInterface> interfaces = QNetworkInterface::allInterfaces();
    for (auto &interface: interfaces) {
        qDebug() << interface.name();
        msg += interface.name() + "\n";
        QList<QHostAddress> addresses = interface.allAddresses();
        for (auto &address: addresses) {
            if (QAbstractSocket::IPv4Protocol == address.protocol()) {
                qDebug() << "\t" << address.toString() << ": " <<  address.protocol();
            }
        }
    }

//    QTextEdit *edit = new QTextEdit();
//    edit->setReadOnly(true);
//    edit->setText(msg);
//    edit->show();


    return a.exec();
}
