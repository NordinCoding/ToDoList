#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardPaths>
#include <QPushButton>
#include <QStyledItemDelegate>
#include <QtMultimedia>
#include <QFileDialog>
#include <QStyle>
#include <QSoundEffect>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QSoundEffect *efx;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addTaskbtn_1_clicked();

    void on_removeTaskbtn_1_clicked();

    void on_toDoInput_1_returnPressed();

private:
    Ui::MainWindow *ui;
    QMediaPlayer *M_Player;

    QString pathTaskFile = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "\\toDoFileDev.txt";
};
#endif // MAINWINDOW_H
