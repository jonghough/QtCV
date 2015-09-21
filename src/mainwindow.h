#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "imageholder.h"
#include <QMainWindow>
#include <QString>
#include <stdlib.h>
#include <vector>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "QWidget"
#include "QLabel"
#include "featurewindow.h"
#include "edgedetectwindow.h"
#include "QContextMenuEvent"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    std::vector<QLabel*> *imageVec;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_selectImageButton_clicked();
    void goFeatureWindow();
    void goSobelWindow();

private:
    Ui::MainWindow *ui;
    FeatureWindow *_fWindow;
    void contextMenuEvent(QContextMenuEvent *event) Q_DECL_OVERRIDE;
    void createActions();
    void createMenus();
    QMenu *fileMenu;
    QAction *featureAction, *sobelAction;
};

#endif // MAINWINDOW_H
