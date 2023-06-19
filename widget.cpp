#include "widget.h"
#include "./ui_widget.h"
#include <cstdio>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    slider = ui->BrightControl;
    connect(slider, &QSlider::valueChanged, this, &Widget::setBrightness);

}

void Widget::setBrightness(int value) {
    char *buf = new char[10];
    sprintf(buf, "backlight %d", value);
    system(buf);
    delete[] buf;
}

Widget::~Widget()
{
    delete ui;
}

