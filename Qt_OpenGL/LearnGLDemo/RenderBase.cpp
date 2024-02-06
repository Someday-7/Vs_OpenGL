#include "RenderBase.h"
#include <QPointF>

RenderBase::RenderBase(QObject *parent) : QObject(parent)
{

}

void RenderBase::setCameraWheelEvent(QPoint qpAngleData)
{
    m_Camera.ProcessMouseScroll(qpAngleData.y());
}

void RenderBase::setCameraKeyPressed(Qt::Key qKey)
{
    if(qKey == Qt::Key_Escape){
       exit(0);
    }
    else if(qKey == Qt::Key_W){
        m_Camera.ProcessKeyboard(FORWARD, global_llDeltaTime);
    }
    else if(qKey == Qt::Key_S){
        m_Camera.ProcessKeyboard(BACKWARD, global_llDeltaTime);
    }
    else if(qKey == Qt::Key_A){
        m_Camera.ProcessKeyboard(LEFT, global_llDeltaTime);
    }
    else if(qKey == Qt::Key_D){
        m_Camera.ProcessKeyboard(RIGHT, global_llDeltaTime);
    }
}

void RenderBase::setCameraKeyMouseReleased(Qt::MouseButton qMouseBtn, const QPointF& qpFMousePox)
{
    if(qMouseBtn != Qt::MouseButton::MiddleButton){
        float xpos = qpFMousePox.x();
        float ypos = qpFMousePox.y();

        if (global_fFirstMouse)
        {
            global_fLastX = xpos;
            global_flastY = ypos;
            global_fFirstMouse = false;
        }

        float xoffset = xpos - global_fLastX;
        float yoffset = global_flastY - ypos; // reversed since y-coordinates go from bottom to top

        global_fLastX = xpos;
        global_flastY = ypos;

        m_Camera.ProcessMouseMovement(xoffset, yoffset);
    }
}
