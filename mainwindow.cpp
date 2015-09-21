#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_imageholder.h"
#include "imageholder.h"
#include <QFileDialog>
#include "filters.h"
#include "qdebug.h"
#include "QVBoxLayout"
#include "QScrollArea"
#include "QWidget"
#include <QGridLayout>

/**
 * @brief MainWindow::MainWindow
 * @param parent
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    imageVec = new std::vector<QLabel*>();
    createActions();
    createMenus();
    QWidget::setWindowTitle ("OpenCV 3.0 + QT");

    QScrollArea* sa = new QScrollArea(this);
    sa->setWidget(ui->gridLayoutWidget);
    sa->setFixedSize( QSize(500,600));
    sa->move(550,10);

    int i = 0; int j = 0;

    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
        QLabel* imageLabel = new QLabel("",ui->gridLayoutWidget);

        imageLabel->setFixedHeight(200);
        imageLabel->setFixedWidth(150);
        imageLabel->setBackgroundRole(QPalette::Dark);
        ui->gridLayout->addWidget(imageLabel,i,j,0);
       imageVec->push_back(imageLabel);
        }
    }
    ui->gridLayoutWidget->setFixedSize(QSize(500, 650));
    ((QGridLayout)(ui->gridLayoutWidget)).setColumnMinimumWidth(0,150);
    ((QGridLayout)(ui->gridLayoutWidget)).setColumnMinimumWidth(1,150);
    ((QGridLayout)(ui->gridLayoutWidget)).setColumnMinimumWidth(2,150);
    this->showMaximized();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_selectImageButton_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("open image"),".",tr("Image Files(*.jpg)"));

    filters f = filters(*imageVec->at(0), filename);
    f.setMainImage(*ui->imageLabel);
    f.modifyImage(*imageVec->at(0), filters::BARREL);
    f.modifyImage(*imageVec->at(1), filters::FISHEYE);
    f.modifyImage(*imageVec->at(2), filters::CARTOON);
    f.modifyImage(*imageVec->at(3), filters::CANNY);
    f.modifyImage(*imageVec->at(4), filters::SOBEL);
    f.modifyImage(*imageVec->at(5), filters::PIXELATE);
    f.modifyImage(*imageVec->at(6), filters::GRABCUT);
    f.modifyImage(*imageVec->at(7), filters::RIPPLE);
    f.modifyImage(*imageVec->at(8), filters::PROJECTIVE);
}

void  MainWindow::goFeatureWindow()
{
    _fWindow = new FeatureWindow();
    _fWindow->show();
    hide();
}


void MainWindow::goSobelWindow(){
    EdgeDetectWindow* edgeDetectWindow = new EdgeDetectWindow();
    edgeDetectWindow->show();
    hide();
}

void MainWindow::createActions()
{
    featureAction = new QAction(tr("&Feature detection"), this);
    featureAction->setToolTip("Detect common features in images and find objects from one image in another image.");
    connect(featureAction, SIGNAL(triggered()), this, SLOT(goFeatureWindow()));

    sobelAction = new QAction(tr("&Edge detection"), this);
    sobelAction->setToolTip("Perform simple Sobel filtering on an image.");
    connect(sobelAction, SIGNAL(triggered()), this, SLOT(goSobelWindow()));
}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(featureAction);
    fileMenu->addAction(sobelAction);
}

void MainWindow::contextMenuEvent(QContextMenuEvent *event)
{
    QMenu menu(this);
    menu.exec(event->globalPos());
}
