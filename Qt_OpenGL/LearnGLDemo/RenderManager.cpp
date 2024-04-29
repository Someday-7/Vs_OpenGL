#include "RenderManager.h"
#include "Simple/rectangle.h"
#include "Simple/cameraSys.h"
#include "Simple/sinWave.h"

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
    m_mapEnumObj[RENDER_CAMERASYS] = std::make_shared<CameraSysDemo>();
    m_mapEnumObj[RENDER_SINWAVE] = std::make_shared<sinWave>();
    m_eCurRenderType = RENDER_SINWAVE;
}

std::shared_ptr<RenderBase> RenderManager::getCurrentRenderObj()
{
    return m_mapEnumObj[m_eCurRenderType];
}
