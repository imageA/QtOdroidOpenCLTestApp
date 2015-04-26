#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>
#include <QDebug>
#include "global.h"

using namespace cv;
using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void Init();

private:
    void OpenCVTest();

private slots:
    void Start();
    void Stop();
    void printOutput();

    void on_cb_ExampleList_currentIndexChanged(int index);

public:

private:
    Ui::MainWindow *ui;
    IplImage*   imagerd;
    QProcess* proc;
};

#endif // MAINWINDOW_H
