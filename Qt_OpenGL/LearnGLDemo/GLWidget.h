#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QObject>
#include <QWidget>
#include <QOpenGLWidget>
#include "RenderManager.h"

class GLWidget : public QOpenGLWidget
{
    Q_OBJECT
public:
    explicit GLWidget(QWidget* parent = nullptr);
    ~GLWidget();
protected:
    virtual void initializeGL() override;
    virtual void resizeGL(int iWidth, int height) override;
    virtual void paintGL() override;
    bool event(QEvent *e) Q_DECL_OVERRIDE;
private:
    RenderManager m_renderManager;
};

#endif // GLWIDGET_H
