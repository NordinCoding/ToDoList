#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QStandardPaths>
#include <QMessageBox>
#include <QtDebug>


MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);  

    QFile file(path);

    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", file.errorString());
    }

    QTextStream in(&file);

    while(!in.atEnd()) {
        QListWidgetItem *item = new QListWidgetItem(in.readLine(), ui->listWidget);
        if(item->checkState())
        {
            item->setCheckState(Qt::Checked);
        }
        else
        {
            item->setCheckState(Qt::Unchecked);
        }

        item->setForeground(QBrush(Qt::black));

        ui->listWidget->addItem(item);
        item->setFlags(item->flags() | Qt::ItemIsEditable | Qt::ItemIsUserCheckable);

    }

    file.close();
}

MainWindow::~MainWindow()
{
    QFile file(path);

    if(!file.open(QIODevice::ReadWrite | QIODevice::Truncate)) {
        QMessageBox::information(0, "error", file.errorString());
    }

    QTextStream out(&file);

    for (int i = 0; i < ui->listWidget->count(); ++i) {
        out<<ui->listWidget->item(i)->text()<<"\n";
    }

    file.close();

    delete ui;
}

QString task;

void MainWindow::on_addTaskbtn_1_clicked()
{
    task = ui->toDoInput->text();
    int len = task.length();
    if (len != 0)
    {
        QListWidgetItem *item = new QListWidgetItem(task);
        item->setCheckState(Qt::Unchecked);
        ui->listWidget->addItem(item);
        item->setFlags(item->flags() | Qt::ItemIsEditable | Qt::ItemIsUserCheckable);
        ui->toDoInput->clear();
        ui->toDoInput->setFocus();
    }
}


void MainWindow::on_removeTaskbtn_1_clicked()
{
    QList<int> checked;

    for (int i = 0; i < ui->listWidget->count(); ++i) {
        QListWidgetItem *item = ui->listWidget->item(i);
        if(item->checkState())
            {
                checked.append(i);
            }
    }

    for (int i = checked.size() - 1; i >= 0; --i) {
        QListWidgetItem *item = ui->listWidget->item(checked[i]);
        delete item;
    }
}


void MainWindow::on_toDoInput_returnPressed()
{

}

