#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

/* События */
private slots:
    void on_xSlider_valueChanged(int value); // Событие изменения X по слайдеру
    void on_ylSlider_valueChanged(int value); // Событие изменения Y по слайдеру
    void on_zSlider_valueChanged(int value); // Событие изменения Z по слайдеру


private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
