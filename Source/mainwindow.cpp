#include "ui_mainwindow.h"
#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    Init();
}

MainWindow::~MainWindow()
{
    delete ui;
}
/*
void MainWindow::Test()
{
    QProcess proc;

    QString proc_str;
    QStringList proc_str_list;

    proc_str = "-c ./opencv_perf_ocl --gtest_filter=OCL_BlendLinearFixture_BlendLinear.BlendLinear/0 --perf_run_cpu=true";
    proc_str_list << proc_str;
    proc.start("/bin/bash", proc_str_list);
    //proc.readallout

}*/

void MainWindow::Start()
{
    int index = ui->cb_ExampleList->currentIndex();
    int filter_index = ui->cb_LibraryList->currentIndex();
    QString result = "";


    if(index == QT_EXAMPLE_PERFORMANCE_H)
    {

        QString proc_str;
        QStringList proc_str_list;

        if(filter_index == LIBRARY_BlendLinear)
            proc_str = "./opencv_perf_ocl --gtest_filter=OCL_BlendLinearFixture_BlendLinear.BlendLinear/6";
        else if(filter_index == LIBRARY_Sobel)
            proc_str = "./opencv_perf_ocl --gtest_filter=OCL_SobelFixture_Sobel.Sobel/15";
        else if(filter_index == LIBRARY_GaussianBlur)
            proc_str = "./opencv_perf_ocl --gtest_filter=OCL_GaussianBlurFixture_GaussianBlur.GaussianBlur/47";
        else if(filter_index == LIBRARY_Multiply)
            proc_str = "./opencv_perf_ocl --gtest_filter=OCL_MulFixture_Multiply.Multiply/23";
        else if(filter_index == LIBRARY_CvtColor)
            proc_str = "./opencv_perf_ocl --gtest_filter=OCL_CvtColorFixture_CvtColor.CvtColor/10";

        if(!ui->rb_cl_on->isChecked())
            proc_str.append(" --perf_run_cpu=true");

        proc_str.append(" | grep 'OK'");

        proc_str_list << "-c" << proc_str;
        proc->start("/bin/bash", proc_str_list);
        proc->waitForFinished();
        qDebug() << "finished1";
    }
}

void MainWindow::printOutput()
{
    qDebug() << "wait finished";

    QByteArray byteArray = proc->readAllStandardOutput();
    QStringList strLines = QString(byteArray).split("\n");
    if(!ui->rb_cl_on->isChecked())
        ui->te_Result->append("[CPU MODE]");
    else
        ui->te_Result->append("[GPU MODE]");

    foreach (QString line, strLines){

        ui->te_Result->append(line);
    }
}

void MainWindow::Stop()
{
    int index = ui->cb_ExampleList->currentIndex();

    if(index == QT_EXAMPLE_SQUARE_H)
    {
    }
    else if(index == QT_EXAMPLE_HOG_H)
    {
    }
}

void MainWindow::Init()
{
    //ui->gb_oclList->setVisible(false);

    proc = new QProcess(this);

    // Event
    connect(ui->bt_Start,SIGNAL(clicked()), this, SLOT(Start()));
    connect(ui->bt_Stop,SIGNAL(clicked()), this, SLOT(Stop()));

    connect(proc, SIGNAL(readyReadStandardOutput()), this, SLOT(printOutput()));

    // OpenCV Version
    ui->lb_Version->setText(QString("OpenCV Version : ").append(CV_VERSION));
}

// OpenCV Porting Simply Test
void MainWindow::OpenCVTest()
{
    //imagerd = cvLoadImage("./pic1.png");
    //QImage image = QImage((const unsigned char*)(imagerd->imageData), imagerd->width,imagerd->height,QImage::Format_RGB888).rgbSwapped();

}


void MainWindow::on_cb_ExampleList_currentIndexChanged(int index)
{
    if(index == 3)
    {
        //ui->gb_oclList->setVisible(false);
    }
    else
    {
        //ui->gb_oclList->setVisible(true);
    }
}
