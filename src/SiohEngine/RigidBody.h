#ifndef SIOHENGINE_RIGIDBODY_H
#define SIOHENGINE_RIGIDBODY_H

#include <iostream>
#include "Component.h"
#include "BoxCollider.h"
#include <vector>
#include <memory>

namespace SiohEngine
{
	struct Collision
	{
	public:
		bool isColliding;
		std::vector<std::shared_ptr<BoxCollider>> colliders;
		std::shared_ptr<BoxCollider> collider;
	};

	struct RigidBody : Component
	{
		/**
		 * @brief A function to initialize variables.
		*/
		void Start();

		/**
		* @brief A function for ticking each frame.
		*/
		void OnTick();

		/**
		 * @brief A function to test if the object is currently colliding with another
		 * @return m_collision The data of whether the object is colliding and
		 * the information of which objects are involved
		*/
		Collision CheckCollision();

	private:
		Collision m_collision;
	};	
}
#endif