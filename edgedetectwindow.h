#ifndef EDGEDETECTWINDOW_H
#define EDGEDETECTWINDOW_H

#include <QMainWindow>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

namespace Ui {
class EdgeDetectWindow;
}

class EdgeDetectWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit EdgeDetectWindow(QWidget *parent = 0);
    ~EdgeDetectWindow();

private slots:
    void on_SelectButton_clicked();
    void on_SelectButton_2_clicked();
    void on_laplaceButton_clicked();
    void goMainWindow();
    void goFeatureWindow();


private:
    Ui::EdgeDetectWindow *ui;
    void drawLaplacian(cv::Mat image);
    void filterSobel(cv::Mat image);
    void drawCannyEdges(cv::Mat image);
    //cache the original sizes of the QLabels.
    QSize _image1Size;
    QMenu *fileMenu;
    QAction *mainAct, *featureAct;
    void createActions();
    void createMenus();
};

#endif // EDGEDETECTWINDOW_H
