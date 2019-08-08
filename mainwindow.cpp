#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QRegularExpression>
#include <QClipboard>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->ptOutput->setReadOnly(true);
    QObject::connect(ui->ptEntry,SIGNAL(textChanged()),this,SLOT(checkText()));
    QObject::connect(ui->pbClear,SIGNAL(clicked()),ui->ptEntry,SLOT(clear()));
    QObject::connect(ui->pbCopyToClipBoard, SIGNAL(clicked()),this,SLOT(copyClipBoard()));
    this->serialName = "";
    this->typeName = "";
    this->varName = "";
    this->cpt = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::findType(QString type)
{
    if(type.contains("string"))
        return "Chaîne";
    else if(type.contains("int"))
        return "Entier";
    else if(type.contains("double"))
        return "Numérique";
    else if(type.contains("bool"))
        return "Booléen";
    else if(type.contains("long"))
        return "Numérique";
    else
        return "Variant";
}

QString MainWindow::findTypeAbreviation(QString type)
{
    if(type == "string")
        return "m_s";
    else if(type == "int")
        return "m_n";
    else if(type == "double")
        return "m_r";
    else if(type == "bool")
        return "m_b";
    else if(type == "long")
        return "m_x";
    else
        return "m_v";
}


QString MainWindow::checkLine(QString ligne)
{
    this->cpt = 0;
    this->typeName = "";
    this->varName = "";
    if(ligne.contains("DataMember"))
    {
        this->cpt = 1;
        QRegularExpression re(".* \"(.*)\".*");
        QRegularExpressionMatch match = re.match(ligne);
        if (match.hasMatch()) {
            this->serialName = match.captured(1);
            qDebug() << this->serialName;
        }
    }
    else if(ligne.contains("{ get; set; }"))
    {
        this->cpt = 2;
        QRegularExpression reg("^\\S*\\s+(\\S+)\\s+(\\S+)");
        QRegularExpressionMatch match = reg.match(ligne);
        if (match.hasMatch()) {
            this->typeName = match.captured(1);
            this->varName = match.captured(2);
        }
    }
    if(cpt == 2){
        if(this->typeName != "" && this->varName != "")
            return "m_" + this->varName + " est un " + findType(this->typeName) + ", Sérialise = \"" + this->serialName + "\"\n";
    }



    return "";
}

void MainWindow::checkText()
{
    this->ui->ptOutput->clear();
    if(ui->ptEntry->toPlainText().isEmpty() == false)
        this->ui->ptOutput->setPlainText("m_nId est un entier, Sérialise = \"id\"\n");

    QString text = ui->ptEntry->toPlainText();
    QString ligne;
    for(int i = 0; i<text.length(); i++)
    {
        if(text[i] != '\n')
            ligne += text[i];
        else{
            ligne.remove(QRegularExpression("^\\s+"));
            ui->ptOutput->setPlainText(ui->ptOutput->toPlainText() + checkLine(ligne));
            ligne = "";
        }
    }
}

void MainWindow::copyClipBoard()
{
    QClipboard *clipboard = QGuiApplication::clipboard();
    clipboard->setText(this->ui->ptOutput->toPlainText());
}
