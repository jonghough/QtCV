#include "edgedetectwindow.h"
#include "ui_edgedetectwindow.h"
#include "mainwindow.h"
#include "featurewindow.h"
#include "imagehandler.h"
#include "sobel.h"
#include "Canny.h"
#include "laplace.h"

/**
 * @brief EdgeDetectWindow::EdgeDetectWindow
 * @param parent
 */
EdgeDetectWindow::EdgeDetectWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EdgeDetectWindow)
{
    ui->setupUi(this);
    createActions();
    createMenus();
    QWidget::setWindowTitle ("Sobel filter window");
    this->showMaximized();

    //cache the initial dimensions of the QLabels.
    _image1Size = ui->sobelImage1->size();
}

EdgeDetectWindow::~EdgeDetectWindow()
{
    delete ui;
}

/**
 * @brief EdgeDetectWindow::on_SelectButton_clicked
 * Sobel button clicked.
 */
void EdgeDetectWindow::on_SelectButton_clicked()
{
    ImageHandler imageHandler;
    cv::Mat image = imageHandler.handleImage(this);
    QLabel * ql = ui->sobelImage1;
    ql->resize(_image1Size.width(), _image1Size.height());
    imageHandler.setImage(*ql, image, QImage::Format_RGB888);
    filterSobel(image);

}

/**
 * @brief SobelWindow::filterSobel
 * Performs sobel filter on image, using the sliders to
 * get threshold and max value parameters.
 * @param image
 */
void EdgeDetectWindow::filterSobel(cv::Mat image){
    const int thresh1 = ui->horizontalSlider->value();
    int max= ui->horizontalSlider_2->value();
    if(max < thresh1)
        max = thresh1;

    cv::Mat sobImage = sobelFilterThreshold(image, thresh1, max);
    ImageHandler ImageHandler;
    QLabel * ql = ui->sobelImage2;
    ql->resize(_image1Size.width(), _image1Size.height());
    ImageHandler.setImage(*ql, sobImage, QImage::Format_RGB888);

}

/**
 * @brief SobelWindow::drawCannyEdges
 * @param image
 */
void EdgeDetectWindow::drawCannyEdges(cv::Mat image){
    const int thresh1 = ui->horizontalSlider_3->value();
    int maxThresh = ui->horizontalSlider_4->value();
    if(maxThresh < thresh1)
        maxThresh = thresh1;

    cv::Mat cannyImage = cannyEdges(image,thresh1, maxThresh);

    ImageHandler ImageHandler;
    QLabel * ql = ui->cannyImage2;
    ql->resize(_image1Size.width(), _image1Size.height());
    ImageHandler.setImage(*ql, cannyImage, QImage::Format_Indexed8);

}

/**
 * @brief EdgeDetectWindow::drawLaplacian
 * @param image
 */
void EdgeDetectWindow::drawLaplacian(cv::Mat image){

    cv::Mat lap = laplacian(image,7);

    ImageHandler ImageHandler;
    QLabel * ql = ui->laplaceImage2;
    ql->resize(_image1Size.width(), _image1Size.height());
    ImageHandler.setImage(*ql, lap, QImage::Format_Indexed8);

}

/**
 * @brief EdgeDetectWindow::on_SelectButton_2_clicked
 * Canny button clicked.
 */
void EdgeDetectWindow::on_SelectButton_2_clicked()
{
    ImageHandler imageHandler;
    cv::Mat image = imageHandler.handleImage(this);
    QLabel * ql = ui->cannyImage1;

    ql->resize(_image1Size.width(), _image1Size.height());
    imageHandler.setImage(*ql, image, QImage::Format_RGB888);
    drawCannyEdges(image);
}


/**
 * @brief EdgeDetectWindow::on_laplaceButton_clicked
 * Laplacian button clicked.
 */
void EdgeDetectWindow::on_laplaceButton_clicked()
{
    ImageHandler imageHandler;
    cv::Mat image = imageHandler.handleImage(this);
    QLabel * ql = ui->laplaceImage1;

    ql->resize(_image1Size.width(), _image1Size.height());
    imageHandler.setImage(*ql, image, QImage::Format_RGB888);
    drawLaplacian(image);
}


/**
 * @brief FeatureWindow::goMain
 * Opens the main window.
 */
void EdgeDetectWindow::goMainWindow(){
    MainWindow* mw = new MainWindow();
    mw->show();
    hide();
}

/**
 * @brief MainWindow::goSobelWindow
 * Opens the edge detection window.
 */
void EdgeDetectWindow::goFeatureWindow(){
    EdgeDetectWindow* edgeDetectWindow = new EdgeDetectWindow();
    edgeDetectWindow->show();
    hide();
}

void EdgeDetectWindow::createActions()
{
    mainAct = new QAction(tr("&Main"), this);
    connect(mainAct, SIGNAL(triggered()), this, SLOT(goMainWindow()));

    featureAct = new QAction(tr("&Feature detection"), this);
    connect(featureAct, SIGNAL(triggered()), this, SLOT(goSobelWindow()));
}

void EdgeDetectWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(mainAct);
    fileMenu->addAction(featureAct);

}
