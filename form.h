#ifndef FORM_H
#define FORM_H

#include <QWidget>

#include "mainwindow.h"

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();
    void paintEvent(QPaintEvent *event);

private:
    Ui::Form *ui;
};

#endif // FORM_H
