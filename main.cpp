#include "mainwindow.h"

#include <QApplication>
#include <QListWidgetItem>
#include <QListWidget>
#include <QFile>
#include <QString>
#include <QSettings>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QApplication::setStyle("Fusion");

    QFile file(":/resources/stylesheet.qss");
    if (file.open(QFile::ReadOnly)) {
        QString styleSheet = file.readAll();
        a.setStyleSheet(styleSheet);
    }
    else {
        qDebug() << "Failed to load stylesheet:" << file.errorString();
    }

    MainWindow w;
    w.show();
    return a.exec();
}
