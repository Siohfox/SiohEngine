cmake_minimum_required(VERSION 3.0)
project(SIOHENGINE)

include_directories(
	src
	contrib/windows-cl-amd64/include
)

link_directories(
	${PROJECT_SOURCE_DIR}/contrib/windows-cl-amd64/lib
)

add_library(rend
 src/rend/Animation.cpp
 src/rend/Buffer.cpp
 src/rend/Mesh.cpp
 src/rend/Model.cpp
 src/rend/ModelRenderer.cpp
 src/rend/RenderTexture.cpp
 src/rend/Renderer.cpp
 src/rend/Shader.cpp
 src/rend/Texture.cpp
 src/rend/rendmath.cpp
)
target_link_libraries(rend glew32 opengl32)

add_library(SiohEngine
	src/SiohEngine/SiohEngine.h

	src/SiohEngine/SiohMath.h
	
	src/SiohEngine/Core.h
	src/SiohEngine/Core.cpp

	src/SiohEngine/Entity.h
	src/SiohEngine/Entity.cpp

	src/SiohEngine/TriangleRenderer.h
	src/SiohEngine/TriangleRenderer.cpp

	src/SiohEngine/Component.h
	src/SiohEngine/Component.cpp

	src/SiohEngine/Transform.h
	src/SiohEngine/Transform.cpp

	src/SiohEngine/Time.h
	src/SiohEngine/Time.cpp

	src/SiohEngine/AudioClip.h
	src/SiohEngine/AudioClip.cpp

	src/SiohEngine/AudioSource.h
	src/SiohEngine/AudioSource.cpp
)

target_link_libraries(SiohEngine rend SDL2 SDL2main openal32)

add_executable(game
	src/game/main.cpp
)

target_link_libraries(game SiohEngine)