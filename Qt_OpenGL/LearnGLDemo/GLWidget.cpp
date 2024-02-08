#include "GLWidget.h"
#include <QDebug>
#include <QEvent>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QWheelEvent>

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
    qDebug()<<__FILE__<<" "<<__FUNCTION__<<" iWidth:"<<iWidth<<" height:"<<height;
}

void GLWidget::paintGL()
{
    qDebug()<<__FILE__<<" "<<__FUNCTION__;
    m_renderManager.getCurrentRenderObj()->paintGL();
}

bool GLWidget::event(QEvent *e)
{
    if(QEvent::MouseMove == e->type()
            || QEvent::MouseButtonPress == e->type()
            || QEvent::MouseButtonRelease == e->type()
            || QEvent::MouseButtonDblClick == e->type()){
        QMouseEvent* pMouseEvent = dynamic_cast<QMouseEvent*>(e);
        if(pMouseEvent){
            if(QEvent::MouseButtonRelease == pMouseEvent->type()){
                m_renderManager.getCurrentRenderObj()->setCameraKeyMouseReleased(pMouseEvent->button(),pMouseEvent->localPos());
            }
        }
    }
    else if(QEvent::KeyRelease == e->type()){
        QKeyEvent* pKeyEvent = dynamic_cast<QKeyEvent*>(e);
        if(pKeyEvent){
            if(QEvent::KeyRelease == pKeyEvent->type()){
                m_renderManager.getCurrentRenderObj()->setCameraKeyPressed((Qt::Key)pKeyEvent->key());
            }
        }
    }
    else if(QEvent::Wheel == e->type()){
        QWheelEvent* pWheelEvent = dynamic_cast<QWheelEvent*>(e);
        if(pWheelEvent){
                m_renderManager.getCurrentRenderObj()->setCameraWheelEvent(pWheelEvent->angleDelta());
        }
    }
    QOpenGLWidget::event(e);
    return true;
}
