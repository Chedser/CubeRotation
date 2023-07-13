#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

/*  Вращение куба вокруг оси X по слайдеру */
void MainWindow::on_xSlider_valueChanged(int value)
{
        ui->cube->rotate(Axis::X, value);
        ui->xLabelValue->setNum(value);

}

/*  Вращение куба вокруг оси Y по слайдеру */
void MainWindow::on_ylSlider_valueChanged(int value)
{
     ui->cube->rotate(Axis::Y, value);
     ui->yLabelValue->setNum(value);
}

/*  Вращение куба вокруг оси Z по слайдеру */
void MainWindow::on_zSlider_valueChanged(int value)
{
   ui->cube->rotate(Axis::Z, value);
   ui->zLabelValue->setNum(value);
}


