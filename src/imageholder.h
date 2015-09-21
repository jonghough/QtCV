#ifndef IMAGEHOLDER_H
#define IMAGEHOLDER_H

#include <QWidget>

namespace Ui {
class ImageHolder;
}

class ImageHolder : public QWidget
{
    Q_OBJECT

public:
    explicit ImageHolder(QWidget *parent = 0);
    ~ImageHolder();

private:
    Ui::ImageHolder *ui;
};

#endif // IMAGEHOLDER_H
