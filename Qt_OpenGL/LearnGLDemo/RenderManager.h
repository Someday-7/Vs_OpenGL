#ifndef RENDERMANAGER_H
#define RENDERMANAGER_H

#include <QObject>
#include <map>
#include "RenderBase.h"

class RenderManager : public QObject
{
    Q_OBJECT
public:
    explicit RenderManager(QObject* parent = nullptr);
    ~RenderManager();
    void buildRenderObj();
    std::shared_ptr<RenderBase> getCurrentRenderObj();
private:
    std::map<RENDER_OBJECT,std::shared_ptr<RenderBase> > m_mapEnumObj;
};

#endif // RENDERMANAGER_H
