#include "featurewindow.h"
#include "ui_featurewindow.h"
#include "edgedetectwindow.h"
#include "mainwindow.h"
#include "imagehandler.h"
#include "featuredetector.h"
#include <stdlib.h>
#include <QString>
#include <QFileDialog>
#include <QImage>

FeatureWindow::FeatureWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FeatureWindow)
{
    ui->setupUi(this);
    createActions();
    createMenus();
    this->showMaximized();
}

FeatureWindow::~FeatureWindow()
{
    delete ui;
}

void FeatureWindow::on_pushButton_clicked()
{
    ImageHandler imageHandler;
    _image1 = imageHandler.handleImage(this);
    QLabel * ql = ui->image1;
    imageHandler.setImage(*ql, _image1, QImage::Format_RGB888);
    if(!_image1.empty() && !_image2.empty()){
         featuredetector fd(_image1, _image2);
         _result = fd.testFeatures();
     }
}

void FeatureWindow::on_pushButton_2_clicked()
{
    ImageHandler imageHandler;
    _image2 = imageHandler.handleImage(this);
    QLabel * ql = ui->image2;
    imageHandler.setImage(*ql, _image2, QImage::Format_RGB888);

    if(!_image1.empty() && !_image2.empty()){
         featuredetector fd(_image1, _image2);
         _result = fd.testFeatures();
     }
}

void FeatureWindow::saveImage(){
    if( _result.empty())
        return;
    else{
        ImageHandler im;
        im.saveImage(_result);
    }
}

/**
 * @brief FeatureWindow::goMain
 * Opens the main window.
 */
void FeatureWindow::goMainWindow(){
    MainWindow* mw = new MainWindow();
    mw->show();
    hide();
}

/**
 * @brief MainWindow::goSobelWindow
 * Opens the edge detection window.
 */
void FeatureWindow::goSobelWindow(){
    EdgeDetectWindow* edgeDetectWindow = new EdgeDetectWindow();
    edgeDetectWindow->show();
    hide();
}

void FeatureWindow::createActions()
{
    mainAct = new QAction(tr("&Main"), this);
    connect(mainAct, SIGNAL(triggered()), this, SLOT(goMainWindow()));

    edgedetectAct = new QAction(tr("&Feature detection"), this);
    connect(edgedetectAct, SIGNAL(triggered()), this, SLOT(goFeatureWindow()));

    saveAct = new QAction(tr("&Save resut"),this);
    connect(saveAct, SIGNAL(triggered()), this, SLOT(saveImage()));
}

void FeatureWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(mainAct);
    fileMenu->addAction(edgedetectAct);

    optionsMenu = menuBar()->addMenu(tr("&Options"));
    optionsMenu->addAction(saveAct);
}

void FeatureWindow::contextMenuEvent(QContextMenuEvent *event)
{
    QMenu menu(this);
    menu.exec(event->globalPos());
}



