#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardPaths>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addTaskbtn_1_clicked();

    void on_removeTaskbtn_1_clicked();

    void on_toDoInput_1_returnPressed();

private:
    Ui::MainWindow *ui;

    QString path = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "\\toDoFileDev.txt";
};
#endif // MAINWINDOW_H
