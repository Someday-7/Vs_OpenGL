#ifndef RENDERBASE_H
#define RENDERBASE_H

#include <QObject>
#include "Camera.h"
#include "MyShader.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <memory>

enum RENDER_OBJECT{
    RENDER_UBIFORM = 0,
    RENDER_RECTANGLE,
    RENDER_CAMERASYS,
    RENDER_SINWAVE,
    RENDER_END
};

class RenderBase : public QObject
{
    Q_OBJECT
public:
    explicit RenderBase(QObject *parent = nullptr);
    virtual bool initializeGL() = 0;
    virtual bool paintGL() = 0;
    // shader

    // camera
    void setCameraWheelEvent(QPoint);
    void setCameraKeyPressed(Qt::Key qKey);
    void setCameraKeyMouseReleased(Qt::MouseButton, const QPointF& qpFMousePox);
protected:
    MyShader m_Shader;
    unsigned int SCR_WIDTH = 800;
    unsigned int SCR_HEIGHT = 600;
    float m_fMixValue;
    // camera
    Camera m_Camera;
    float m_fLastX;
    float m_fLastY;
    bool m_bFirstMouse;

    // timing
    long long m_llDeltaTime;	// time between current frame and last frame
    long long m_llLastFrame;

signals:

};

#endif // RENDERBASE_H
