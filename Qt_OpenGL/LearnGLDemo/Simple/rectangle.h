#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "../RenderBase.h"

class RectangleDemo : public RenderBase
{
    Q_OBJECT
public:
    explicit RectangleDemo(QObject *parent = nullptr);
    ~RectangleDemo();
    virtual bool initializeGL() override;
    virtual bool paintGL() override;
signals:
private:
    unsigned int VBO, VAO;
    unsigned int shaderProgram;
};
#endif
