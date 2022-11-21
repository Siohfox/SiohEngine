#include "Component.h"
#include <vector>
#include <rend/rend.h>
#include "SiohMath.h"

namespace SiohEngine
{
	/**
	* Component providing position information of the Entity.
	*/
	struct Transform : Component
	{
		Transform::Transform();

		/**
		* Generate the model matrix based on the position, rotation and
		* scale.
		*
		* \return The generated model matrix
		*/
		mat4 GetModel();

		/**
		* Set the position of an Entity.
		*
		* \param _position The new position of the Entity.
		*/
		void SetPosition(vec3 _position) { m_position = _position; }

		/**
		* Set the rotation of an Entity.
		*
		* \param _rotation The new rotation of the Entity.
		*/
		void SetRotation(vec3 _rotation) { m_rotation = _rotation; }

		/**
		* Set the scale of an Entity.
		*
		* \param _scale The new scale of the Entity.
		*/
		void SetScale(vec3 _scale)       { m_scale = _scale; }

		/**
		* Get the position of an Entity.
		*
		* \return The position of the Entity.
		*/
		vec3 GetPosition() { return m_position; }

		/**
		* Get the rotation of an Entity.
		*
		* \return The rotation of the Entity.
		*/
		vec3 GetRotation() { return m_rotation; }

		/**
		* Get the scale of an Entity.
		*
		* \return The scale of the Entity.
		*/
		vec3 GetScale()    { return m_scale; }		

	private:
		vec3 m_position; ///< X, Y, Z location of Entity.
		vec3 m_rotation; ///< Rotation of object in eular angles
		vec3 m_scale;    ///< Scale of Entity.

		int m_angle;     ///< Test for sine wave

	};
}
