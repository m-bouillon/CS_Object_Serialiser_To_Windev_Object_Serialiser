/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pbClear;
    QPushButton *pbCopyToClipBoard;
    QHBoxLayout *horizontalLayout;
    QPlainTextEdit *ptEntry;
    QPlainTextEdit *ptOutput;
    QLabel *label;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(940, 717);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setMinimumSize(QSize(874, 658));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        pbClear = new QPushButton(centralWidget);
        pbClear->setObjectName(QString::fromUtf8("pbClear"));

        horizontalLayout_3->addWidget(pbClear);

        pbCopyToClipBoard = new QPushButton(centralWidget);
        pbCopyToClipBoard->setObjectName(QString::fromUtf8("pbCopyToClipBoard"));

        horizontalLayout_3->addWidget(pbCopyToClipBoard);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        ptEntry = new QPlainTextEdit(centralWidget);
        ptEntry->setObjectName(QString::fromUtf8("ptEntry"));

        horizontalLayout->addWidget(ptEntry);

        ptOutput = new QPlainTextEdit(centralWidget);
        ptOutput->setObjectName(QString::fromUtf8("ptOutput"));

        horizontalLayout->addWidget(ptOutput);


        verticalLayout->addLayout(horizontalLayout);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "C# object converter to windev object", nullptr));
        pbClear->setText(QApplication::translate("MainWindow", "Clear", nullptr));
        pbCopyToClipBoard->setText(QApplication::translate("MainWindow", "Copier dans le presse papier", nullptr));
        label->setText(QApplication::translate("MainWindow", "V1.0 - Outil de conversion pour classe objet C# vers Windev", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
