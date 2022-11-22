#include <iostream>
#include "Component.h"

namespace SiohEngine
{
	struct Camera : Component
	{
		/** Camera default constructor
		*/
		//Camera();

		mat4 GetProjection();
		mat4 GetView();

		void SetMainCam(std::shared_ptr<Camera> cam) { m_main = cam; }
		static std::shared_ptr<Camera> GetMainCam();

	private:
		mat4 m_projection = mat4(1.0f);
		mat4 m_view = mat4(1.0f);

		static std::shared_ptr<Camera> m_main;

	};
}