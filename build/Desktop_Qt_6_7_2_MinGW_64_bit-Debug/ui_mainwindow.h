/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *toDoInput_1;
    QPushButton *addTaskbtn_1;
    QPushButton *removeTaskbtn_1;
    QListWidget *listWidget_1;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(453, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        toDoInput_1 = new QLineEdit(centralwidget);
        toDoInput_1->setObjectName("toDoInput_1");
        toDoInput_1->setGeometry(QRect(20, 40, 321, 31));
        toDoInput_1->setMouseTracking(false);
        toDoInput_1->setAutoFillBackground(false);
        toDoInput_1->setFrame(false);
        addTaskbtn_1 = new QPushButton(centralwidget);
        addTaskbtn_1->setObjectName("addTaskbtn_1");
        addTaskbtn_1->setGeometry(QRect(350, 40, 80, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("Sylfaen")});
        addTaskbtn_1->setFont(font);
        removeTaskbtn_1 = new QPushButton(centralwidget);
        removeTaskbtn_1->setObjectName("removeTaskbtn_1");
        removeTaskbtn_1->setGeometry(QRect(290, 510, 131, 31));
        listWidget_1 = new QListWidget(centralwidget);
        listWidget_1->setObjectName("listWidget_1");
        listWidget_1->setGeometry(QRect(40, 100, 371, 401));
        listWidget_1->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CursorShape::PointingHandCursor)));
        listWidget_1->setFrameShape(QFrame::Shape::Panel);
        listWidget_1->setFrameShadow(QFrame::Shadow::Plain);
        listWidget_1->setLineWidth(5);
        listWidget_1->setMidLineWidth(5);
        listWidget_1->setEditTriggers(QAbstractItemView::EditTrigger::DoubleClicked|QAbstractItemView::EditTrigger::EditKeyPressed);
        listWidget_1->setMovement(QListView::Movement::Static);
        listWidget_1->setProperty("isWrapping", QVariant(false));
        listWidget_1->setResizeMode(QListView::ResizeMode::Fixed);
        listWidget_1->setLayoutMode(QListView::LayoutMode::SinglePass);
        listWidget_1->setWordWrap(false);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 10, 71, 16));
        MainWindow->setCentralWidget(centralwidget);
        addTaskbtn_1->raise();
        removeTaskbtn_1->raise();
        label->raise();
        toDoInput_1->raise();
        listWidget_1->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 453, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        toDoInput_1->setPlaceholderText(QString());
        addTaskbtn_1->setText(QCoreApplication::translate("MainWindow", "Add Task", nullptr));
        removeTaskbtn_1->setText(QCoreApplication::translate("MainWindow", "Remove Checked", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Dev Build", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
