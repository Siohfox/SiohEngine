//#include "Skybox.h"
//#include "rend/rend.h"
//#include "Entity.h"
//#include "Transform.h"
//#include "Camera.h"
//
//namespace SiohEngine
//{
//	Skybox::Skybox() :
//		m_shader("../resources/shaders/basic.vert", "../resources/shaders/basic.frag"),
//		m_texture("../resources/skybox/maxwell/Daylight.png")
//	{
//		m_mesh.loadQuad();
//	}
//
//	Skybox::~Skybox()
//	{
//	}
//
//	void Skybox::OnDisplay()
//	{
//		rend::ModelRenderer mr(640, 480);
//		mr.shader(&m_shader);
//
//		mr.projection(Camera::GetMainCam()->GetProjection());
//		mr.view(Camera::GetMainCam()->GetView());
//
//		mr.depthTest(true);
//		mr.backfaceCull(true);
//		mr.blend(true);
//
//
//		//mr.texture(&m_texture);
//
//		//for (int i = 0; i < cubeMapTextures.size(); i++) {
//
//		//	//17a.Decode each cube map image into its raw image data.
//		//	if (convertImageToRawImage(cubeMapTextures.at(i))) {
//
//		//		//17b. if decompression was successful, set the texture parameters
//
//		//		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//		//		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//		//		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
//		//		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
//
//		//		//17c. load the image data into the current bound texture buffer
//		//		//cubeMapTarget[] contains the cube map targets
//		//		glTexImage2D(cubeMapTarget[i], 0, GL_RGBA, imageWidth, imageHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, &image[0]);
//
//
//		mr.render(); // This should be the final thing that runs here
//	}
//
//}
