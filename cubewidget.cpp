#include "cubewidget.h"

CubeWidget::CubeWidget(QWidget *parent):QGLWidget(parent){
       setFormat(QGLFormat(QGL::DoubleBuffer | QGL::DepthBuffer));

       /* Углы */
       xAngle = 0;
       yAngle = 0;
       zAngle = 0;

       /* Цвета граней */
       faceColors[0] = Qt::red;
       faceColors[1] = Qt::green;
       faceColors[2] = Qt::blue;
       faceColors[3] = Qt::cyan;
       faceColors[4] = Qt::yellow;
       faceColors[5] = Qt::magenta;
}

CubeWidget::~CubeWidget(){}

void CubeWidget::initializeGL()
{
        glShadeModel(GL_FLAT);
        glEnable(GL_DEPTH_TEST);
        glEnable(GL_CULL_FACE);

}

void CubeWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    drawCube();

}

void CubeWidget::resizeGL(int width, int height)
{
        glViewport(0, 0, width, height);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        GLfloat x = (GLfloat)width / height;
        glFrustum(-x, x, -1.0, 1.0, 4.0, 15.0); // Камера
        glMatrixMode(GL_MODELVIEW);
}

/* ГЛАВНЫЙ МЕТОД ЛОГИКИ ПРОГРАММЫ */
void CubeWidget::rotate(Axis axis, int angle)
{

    switch(axis){
        case Axis::X: xAngle = angle;
                      glRotatef(xAngle, 1, 0, 0);
                      break;
        case Axis::Y: yAngle = angle;
                      glRotatef(yAngle, 0, 1, 0);
                      break;
        case Axis::Z: zAngle = angle;
                      glRotatef(zAngle, 0, 0, 1);
                      break;
    }

    updateGL(); //Повторная прорисовка
}

/* Отрисовка куба */
void CubeWidget::drawCube()
{
    static const GLfloat coords[6] [4] [3] = {
           { { +1.0, -1.0, +1.0 }, { +1.0, -1.0, -1.0 },
           { +1.0, +1.0, -1.0 }, { +1.0, +1.0, +1.0 } },
           { { -1.0, -1.0, -1.0 }, { -1.0, -1.0, +1.0 },
           { -1.0, +1.0, +1.0 }, { -1.0, +1.0, -1.0 } },
           { { +1.0, -1.0, -1.0 }, { -1.0, -1.0, -1.0 },
           { -1.0, +1.0, -1.0 }, { +1.0, +1.0, -1.0 } },
           { { -1.0, -1.0, +1.0 }, { +1.0, -1.0, +1.0 },
           { +1.0, +1.0, +1.0 }, { -1.0, +1.0, +1.0 } },
           { { -1.0, -1.0, -1.0 }, { +1.0, -1.0, -1.0 },
           { +1.0, -1.0, +1.0 }, { -1.0, -1.0, +1.0 } },
           { { -1.0, +1.0, +1.0 }, { +1.0, +1.0, +1.0 },
           { +1.0, +1.0, -1.0 }, { -1.0, +1.0, -1.0 } }
       };

       glMatrixMode(GL_MODELVIEW);
       glLoadIdentity();
       glTranslatef(0.0, 0.0, -10.0); // Отодвинуть куб назад от камеры

       /* Вращение */
       glRotatef(xAngle, 1.0, 0.0, 0.0);
       glRotatef(yAngle, 0.0, 1.0, 0.0);
       glRotatef(zAngle, 0.0, 0.0, 1.0);

       /* Создание куба */
       for (int i = 0; i < 6; ++i) { // Грани
           glLoadName(i);
           glBegin(GL_QUADS);
           qglColor(faceColors[i]);
           for (int j = 0; j < 4; ++j) { // Вершины
               glVertex3f(coords[i] [j] [0], coords[i] [j] [1],
               coords[i] [j] [2]);
           }
           glEnd();
       }
}
