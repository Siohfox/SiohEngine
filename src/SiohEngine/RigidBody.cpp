#include "RigidBody.h"

#include "Entity.h"
#include "Core.h"
#include "Transform.h"


namespace SiohEngine
{
    void RigidBody::Start()
    {
        m_collision.isColliding = false;
        m_collision.collider = GetEntity()->GetComponent<BoxCollider>();
    }

    void RigidBody::OnTick()
    {

        m_collision.colliders.clear();
        GetEntity()->GetCore()->Find<BoxCollider>(m_collision.colliders);


        m_collision.isColliding = false;
        m_collision.other.reset();

        for (size_t i = 0; i < m_collision.colliders.size(); i++)
        {
            // Check if it's colliding with itself, if so skip over
            if (m_collision.colliders.at(i)->GetEntity() == GetEntity())
            {
                continue;
            }

            if (m_collision.colliders.at(i)->Colliding(*m_collision.collider))
            {
                m_collision.other = m_collision.colliders.at(i);
                m_collision.isColliding = true;
            }
        }
    }

    Collision RigidBody::CheckCollision()
    {
        return m_collision;
    }

}