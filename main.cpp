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

    // not sure if i should use this
    // QApplication::setStyle("Fusion");
    MainWindow w;
    w.setWindowTitle("Task List");

    // read stylesheet
    QFile file(":/resources/stylesheet.qss");
    if (file.open(QFile::ReadOnly)) {
        QString styleSheet = file.readAll();
        a.setStyleSheet(styleSheet);
    }
    else {
        qDebug() << "Failed to load stylesheet:" << file.errorString();
    }


    w.show();
    return a.exec();
}
