#ifndef CUBEWIDGET_H
#define CUBEWIDGET_H

#include<QGLWidget>

/* Оси вращения */
enum class Axis {
    X,
    Y,
    Z
        };

class CubeWidget : public QGLWidget
{
    Q_OBJECT

public:
    explicit CubeWidget(QWidget *parent = nullptr);
    ~CubeWidget();

    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int w, int h) override;

    void rotate(Axis axis, int angle); // Вращение куба

private:
      /* Углы */
      GLfloat xAngle;
      GLfloat yAngle;
      GLfloat zAngle;

      QColor faceColors[6]; // Цвета граней

private:
    void drawCube(); // Отрисовка куба

};

#endif // CUBEWIDGET_H
