#include "Resource.h"

namespace SiohEngine
{
    std::string Resource::GetPath() const
    {
        return m_path;
    }

    void Resource::Load()
    {
        OnLoad();
    }
}
