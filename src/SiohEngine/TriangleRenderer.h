#include "Component.h"

#include <rend/rend.h>

namespace SiohEngine
{
	/**
	* Triangle renderer specifically for rendering rasterized triangles
	*/
	struct TriangleRenderer : Component
	{
		//! A constructor for triangle renderer.
		/*!
		  Constructs triangle renderer by giving m_shader the shader
		  files and additionally loading the triangle using the rend
		  library.
		*/
		TriangleRenderer();

	private:
		rend::Mesh m_mesh;     ///< A member variable to hold the mesh for the triangle
		rend::Shader m_shader; ///< A member variable to hold the shader files

		/**
		* Uses the required information to display the triangle to the screen.
		*/
		void OnDisplay();
	};
}