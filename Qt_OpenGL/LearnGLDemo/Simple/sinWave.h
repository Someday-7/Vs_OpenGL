#ifndef SINWAVE_H
#define SINWAVE_H
#include "../RenderBase.h"
#include <vector>

class sinWave : public RenderBase
{
    Q_OBJECT
public:
    explicit sinWave(QObject *parent = nullptr);
    ~sinWave();
    virtual bool initializeGL() override;
    virtual bool paintGL() override;
signals:
private:
    // 波形数据
    unsigned int VBO, VAO;
    unsigned int shaderProgram;
};
#endif // SINWAVE_H
