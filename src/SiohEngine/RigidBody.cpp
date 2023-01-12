#include "RigidBody.h"

#include "Entity.h"
#include "Core.h"


namespace SiohEngine
{
    void RigidBody::Start()
    {
        m_collision.isColliding = false;
        m_collision.collider = GetEntity()->GetComponent<BoxCollider>();
    }

    void RigidBody::OnTick()
    {
        GetEntity()->GetCore()->Find<BoxCollider>(m_collision.colliders);



        for (size_t i = 0; i < m_collision.colliders.size(); i++)
        {
            // Check if it's colliding with itself, if so skip over
            if (m_collision.colliders.at(i)->GetEntity() == GetEntity())
            {
                continue;
            }

            if (m_collision.colliders.at(i)->Colliding(*m_collision.collider))
            {
                //std::cout << "Colliding!\n";
                m_collision.isColliding = true;
            }
            else
            {
                m_collision.isColliding = false;
            }

            //std::cout << m_collision.isColliding << std::endl;
        }
    }

    Collision RigidBody::CheckCollision()
    {
        return m_collision;
    }

}