#ifndef SIOHENGINE_CAMERA_H
#define SIOHENGINE_CAMERA_H

#include <iostream>
#include "Component.h"

namespace SiohEngine
{
	struct Camera : Component
	{
		/**
		 * @brief A getter for the projection of the camera
		 * @return The projection matrix of the camera
		*/
		mat4 GetProjection();

		/**
		 * @brief A getter for the view of the camera
		 * @return The viewing matrix of the camera
		*/
		mat4 GetView();

		/**
		 * @brief A setter to apply an instance of the main camera
		 * @param cam The camera to apply as a main camera
		*/
		void SetMainCam(std::shared_ptr<Camera> cam) { m_main = cam; }

		/**
		 * @brief A getter for the main camera
		 * @return A pointer to the main camera
		*/
		static std::shared_ptr<Camera> GetMainCam();

	private:
		mat4 m_projection = mat4(1.0f); ///< The projection matrix
		mat4 m_view = mat4(1.0f); ///< The viewing matrix

		static std::shared_ptr<Camera> m_main; ///< The main camera

	};
}
#endif