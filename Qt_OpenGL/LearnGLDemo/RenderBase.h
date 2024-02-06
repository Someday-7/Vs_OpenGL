#ifndef RENDERBASE_H
#define RENDERBASE_H

#include <QObject>
#include "global_func.h"
#include "Camera.h"
#include "MyShader.h"

class RenderBase : public QObject
{
    Q_OBJECT
public:
    explicit RenderBase(QObject *parent = nullptr);
    virtual bool initializeGL() = 0;
    virtual bool paintGL() = 0;
    //shader

    //camera
    void setCameraWheelEvent(QPoint);
    void setCameraKeyPressed(Qt::Key qKey);
    void setCameraKeyMouseReleased(Qt::MouseButton, const QPointF& qpFMousePox);
protected:
    MyShader m_Shader;
    Camera  m_Camera;
signals:

};

#endif // RENDERBASE_H
