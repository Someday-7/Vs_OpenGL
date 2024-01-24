#include "GLWidget.h"
#include <QDebug>
GLWidget::GLWidget(QWidget* parent) : QOpenGLWidget(parent)
{

}

GLWidget::~GLWidget()
{

}

void GLWidget::initializeGL()
{
    qDebug()<<__FILE__<<" "<<__FUNCTION__;
    m_renderManager.getCurrentRenderObj()->initializeGL();
}

void GLWidget::resizeGL(int iWidth, int height)
{
    qDebug()<<__FILE__<<" "<<__FUNCTION__<<" "<<iWidth<<" x "<<height;
}

void GLWidget::paintGL()
{
    qDebug()<<__FILE__<<" "<<__FUNCTION__;
    m_renderManager.getCurrentRenderObj()->paintGL();
}
