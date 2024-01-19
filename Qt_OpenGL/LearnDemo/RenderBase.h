#ifndef RENDERBASE_H
#define RENDERBASE_H

#include <QObject>
#include "global_func.h"

enum RENDER_OBJECT{
    RENDER_UBIFORM = 0,
    RENDER_RECTANGLE,
    RENDER_END
};

class RenderBase : public QObject
{
    Q_OBJECT
public:
    explicit RenderBase(QObject *parent = nullptr);
    virtual bool initializeGL() = 0;
    virtual bool paintGL() = 0;
signals:

};

#endif // RENDERBASE_H
