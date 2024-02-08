#include "RenderBase.h"
#include <QPointF>
#include <QDebug>

RenderBase::RenderBase(QObject *parent) : QObject(parent)
{

}

void RenderBase::setCameraWheelEvent(QPoint qpAngleData)
{
    qDebug()<<"qpAngleData:"<<qpAngleData;
    m_Camera.ProcessMouseScroll(qpAngleData.y());
}

void RenderBase::setCameraKeyPressed(Qt::Key qKey)
{
    if(qKey == Qt::Key_Escape){
       exit(0);
    }
    else if(qKey == Qt::Key_W){
        m_Camera.ProcessKeyboard(FORWARD, m_llDeltaTime);
    }
    else if(qKey == Qt::Key_S){
        m_Camera.ProcessKeyboard(BACKWARD, m_llDeltaTime);
    }
    else if(qKey == Qt::Key_A){
        m_Camera.ProcessKeyboard(LEFT, m_llDeltaTime);
    }
    else if(qKey == Qt::Key_D){
        m_Camera.ProcessKeyboard(RIGHT, m_llDeltaTime);
    }
}

void RenderBase::setCameraKeyMouseReleased(Qt::MouseButton qMouseBtn, const QPointF& qpFMousePox)
{
    if(qMouseBtn != Qt::MouseButton::MiddleButton){
        float xpos = qpFMousePox.x();
        float ypos = qpFMousePox.y();

        if (m_bFirstMouse)
        {
            m_fLastX = xpos;
            m_fLastY = ypos;
            m_bFirstMouse = false;
        }

        float xoffset = xpos - m_fLastX;
        float yoffset = m_fLastY - ypos; // reversed since y-coordinates go from bottom to top

        m_fLastX = xpos;
        m_fLastY = ypos;

        m_Camera.ProcessMouseMovement(xoffset, yoffset);
    }
}
