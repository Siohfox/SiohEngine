cmake_minimum_required(VERSION 3.0)
project(SIOHENGINE)



if(${CMAKE_SYSTEM_NAME} MATCHES "Emscripten")
  include_directories(
	src
    contrib/emcc-emscripten-wasm/include
  )

  link_directories(
    contrib/emcc-emscripten-wasm/lib
  )

  set(CMAKE_EXECUTABLE_SUFFIX ".html")
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -sNO_DISABLE_EXCEPTION_CATCHING --preload-file ${CMAKE_SOURCE_DIR}/resources@resources")
  set(LIBOPENAL openal)
  set(LIBOPENGL GL)
  set(LIBGLEW GLEW)

  else()

  include_directories(
	src
	contrib/windows-cl-amd64/include
	)

link_directories(
	${PROJECT_SOURCE_DIR}/contrib/windows-cl-amd64/lib
	)


set(LIBOPENAL openal32)
set(LIBOPENGL opengl32)
set(LIBGLEW glew32)
set(LIBSDL2MAIN SDL2main)

endif()



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
target_link_libraries(rend ${LIBGLEW} ${LIBOPENGL})


add_library(SiohEngine
	src/SiohEngine/SiohEngine.h

	src/SiohEngine/SiohMath.h
	
	src/SiohEngine/Core.h
	src/SiohEngine/Core.cpp

	src/SiohEngine/Entity.h
	src/SiohEngine/Entity.cpp

	src/SiohEngine/TriangleRenderer.h
	src/SiohEngine/TriangleRenderer.cpp

	src/SiohEngine/ModelRenderer.h
	src/SiohEngine/ModelRenderer.cpp

	src/SiohEngine/Component.h
	src/SiohEngine/Component.cpp

	src/SiohEngine/Transform.h
	src/SiohEngine/Transform.cpp

	src/SiohEngine/Time.h
	src/SiohEngine/Time.cpp

	src/SiohEngine/Camera.h
	src/SiohEngine/Camera.cpp

	src/SiohEngine/AudioClip.h
	src/SiohEngine/AudioClip.cpp

	src/SiohEngine/AudioSource.h
	src/SiohEngine/AudioSource.cpp

	src/SiohEngine/BoxCollider.h
	src/SiohEngine/BoxCollider.cpp

	src/SiohEngine/RigidBody.h
	src/SiohEngine/RigidBody.cpp

	src/SiohEngine/Debug.h
	src/SiohEngine/Debug.cpp

	src/SiohEngine/Resource.h
	src/SiohEngine/Resource.cpp

	src/SiohEngine/Input.h
	src/SiohEngine/Input.cpp

	src/SiohEngine/ShaderLoad.h
	src/SiohEngine/ShaderLoad.cpp

	src/SiohEngine/TextureLoad.h
	src/SiohEngine/TextureLoad.cpp

	src/SiohEngine/ModelLoad.h
	src/SiohEngine/ModelLoad.cpp

	src/SiohEngine/Cache.h
	src/SiohEngine/Cache.cpp

	src/SiohEngine/Skybox.h
	src/SiohEngine/Skybox.cpp
)

add_library(gamefiles
	src/gamefiles/Player.h
	src/gamefiles/Player.cpp

	src/gamefiles/Collectables.h

	src/gamefiles/GameManager.h
)

target_link_libraries(SiohEngine rend SDL2 ${LIBSDL2MAIN} ${LIBOPENAL})


add_executable(game
	src/game/main.cpp
)



target_link_libraries(game SiohEngine)
