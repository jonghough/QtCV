#ifndef FEATUREWINDOW_H
#define FEATUREWINDOW_H

#include <QMainWindow>
#include <QString>
#include <stdlib.h>
#include <vector>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <QWidget>
#include <QLabel>
#include "QContextMenuEvent"

namespace Ui {
class FeatureWindow;
}

class FeatureWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit FeatureWindow(QWidget *parent = 0);
    ~FeatureWindow();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void saveImage();
    void goMainWindow();
    void goSobelWindow();

private:
    cv::Mat _image1;
    cv::Mat _image2;
    cv::Mat _result;
    QMenu *fileMenu, *optionsMenu;
    QAction *mainAct, *edgedetectAct, *saveAct;
    Ui::FeatureWindow *ui;
    void contextMenuEvent(QContextMenuEvent *event) Q_DECL_OVERRIDE;

    void createActions();
    void createMenus();

};

#endif // FEATUREWINDOW_H
