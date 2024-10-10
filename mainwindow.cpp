#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QStandardPaths>
#include <QMessageBox>
#include <QtDebug>
#include <QtMultimedia/QMediaPlayer>
#include <QSoundEffect>
#include <QAudioSource>

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QFile file(pathTaskFile);

    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", file.errorString());
    }

    ui->listWidget_1->setWordWrap(true);
    ui->listWidget_1->setStyleSheet("QListView QLineEdit{background:#FFF2D7; color:black;}");

    QTextStream in(&file);

    while(!in.atEnd()) {
        QListWidgetItem *item = new QListWidgetItem(in.readLine(), ui->listWidget_1);
        if(item->checkState())
        {
            item->setCheckState(Qt::Checked);
        }
        else
        {
            item->setCheckState(Qt::Unchecked);
        }

        item->setForeground(QBrush(Qt::black));

        item->setFlags(item->flags() | Qt::ItemIsEditable | Qt::ItemIsUserCheckable);
        ui->listWidget_1->addItem(item);

    }

    file.close();



    //create sound effect
    efx = new QSoundEffect(this);
    efx->setSource(QUrl("qrc:/resources/sounds/pop-6.wav"));
    efx->setVolume(0.50);
}

MainWindow::~MainWindow()
{
    QFile file(pathTaskFile);

    if(!file.open(QIODevice::ReadWrite | QIODevice::Truncate)) {
        QMessageBox::information(0, "error", file.errorString());
    }

    QTextStream out(&file);

    for (int i = 0; i < ui->listWidget_1->count(); ++i) {
        out<<ui->listWidget_1->item(i)->text()<<"\n";
    }

    file.close();

    delete ui;
}

QString task;
bool test;

void MainWindow::on_addTaskbtn_1_clicked()
{
    task = ui->toDoInput_1->text();
    int len = task.length();
    if (len != 0)
    {
        QListWidgetItem *item = new QListWidgetItem(task);
        item->setCheckState(Qt::Unchecked);
        ui->listWidget_1->addItem(item);
        item->setFlags(item->flags() | Qt::ItemIsEditable | Qt::ItemIsUserCheckable);
        ui->toDoInput_1->clear();
        ui->toDoInput_1->setFocus();
        efx->play();
    }
}


void MainWindow::on_removeTaskbtn_1_clicked()
{
    QList<int> checked;

    for (int i = 0; i < ui->listWidget_1->count(); ++i) {
        QListWidgetItem *item = ui->listWidget_1->item(i);
        if(item->checkState())
        {
            checked.append(i);
        }
    }

    for (int i = checked.size() - 1; i >= 0; --i) {
        QListWidgetItem *item = ui->listWidget_1->item(checked[i]);
        delete item;
    }
}


void MainWindow::on_toDoInput_1_returnPressed()
{
    task = ui->toDoInput_1->text();
    int len = task.length();
    if (len != 0)
    {
        QListWidgetItem *item = new QListWidgetItem(task);
        item->setCheckState(Qt::Unchecked);
        ui->listWidget_1->addItem(item);
        item->setFlags(item->flags() | Qt::ItemIsEditable | Qt::ItemIsUserCheckable);
        ui->toDoInput_1->clear();
        ui->toDoInput_1->setFocus();
        efx->play();
    }
}

