#ifndef CAMERA_SYS_H
#define CAMERA_SYS_H
#include "global_func.h"
#include "../RenderBase.h"

class CameraSysDemo : public RenderBase
{
    Q_OBJECT
public:
    explicit CameraSysDemo(QObject *parent = nullptr);
    ~CameraSysDemo();
    virtual bool initializeGL() override;
    virtual bool paintGL() override;
signals:
private:
    unsigned int VBO, VAO;
    unsigned int shaderProgram;
    unsigned int texture1, texture2;
};
#endif
