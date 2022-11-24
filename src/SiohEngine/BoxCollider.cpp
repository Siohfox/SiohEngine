#include "BoxCollider.h"
#include "Entity.h"
#include "Transform.h"

namespace SiohEngine
{
    BoxCollider::BoxCollider()
    {
        m_size = vec3(1.0f);
        m_offset = vec3(0.0f);
    }

    bool BoxCollider::Colliding(const BoxCollider& _other)
    {
        vec3 a = GetEntity()->GetTransform()->GetPosition();
        vec3 b = _other.GetEntity()->GetTransform()->GetPosition();
        vec3 ahs = m_size / 2.0f;
        vec3 bhs = _other.m_size / 2.0f;

        // X collision
        if (a.x > b.x)
        {
            if (b.x + bhs.x < a.x - ahs.x)
            {
                return false;
            }
        }
        else
        {
            if (a.x + ahs.x < b.x - bhs.x)
            {
                return false;
            }
        }

        // Y collision
        if (a.y > b.y)
        {
            if (b.y + bhs.y < a.y - ahs.y)
            {
                return false;
            }
        }
        else
        {
            if (a.y + ahs.y < b.y - bhs.y)
            {
                return false;
            }
        }

        // Z collision
        if (a.z > b.z)
        {
            if (b.z + bhs.z < a.z - ahs.z)
            {
                return false;
            }
        }
        else
        {
            if (a.z + ahs.z < b.z - bhs.z)
            {
                return false;
            }
        }
        return true;
    }
}
