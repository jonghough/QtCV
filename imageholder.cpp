#include "imageholder.h"
#include "ui_imageholder.h"

ImageHolder::ImageHolder(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ImageHolder)
{
    ui->setupUi(this);
}

ImageHolder::~ImageHolder()
{
    delete ui;
}
