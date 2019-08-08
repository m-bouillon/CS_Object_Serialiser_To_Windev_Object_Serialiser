#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QString findType(QString);
    QString checkLine(QString);
    QString findTypeAbreviation(QString type);
    int cpt;

    QString serialName;
    QString typeName;
    QString varName;

private slots:
    void checkText();
    void copyClipBoard();
};

#endif // MAINWINDOW_H
