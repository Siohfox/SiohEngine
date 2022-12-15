#include "Resource.h"

std::string SiohEngine::Resource::GetPath() const
{
    return m_path;
}

void SiohEngine::Resource::Load()
{
    OnLoad();
}
