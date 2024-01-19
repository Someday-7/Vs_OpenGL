#include "RenderManager.h"
#include "Simple/rectangle.h"

RenderManager::RenderManager(QObject* parent) : QObject(parent)
{
    buildRenderObj();
}

RenderManager::~RenderManager()
{

}

void RenderManager::buildRenderObj()
{
    m_mapEnumObj[RENDER_RECTANGLE] = std::make_shared<RectangleDemo>();
}

std::shared_ptr<RenderBase> RenderManager::getCurrentRenderObj()
{
    return m_mapEnumObj[RENDER_RECTANGLE];
}
