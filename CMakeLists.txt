cmake_minimum_required(VERSION 3.0)
project(SIOHENGINE)

include_directories(
	src
	contrib/windows-cl-amd64/include
)

link_directories(
	${PROJECT_SOURCE_DIR}/contrib/windows-cl-amd64/lib
)

add_library(SiohEngine
	src/SiohEngine/SiohEngine.h
	
	src/SiohEngine/Core.h
	src/SiohEngine/Core.cpp

	src/SiohEngine/Entity.h
	src/SiohEngine/Entity.cpp

	src/SiohEngine/TriangleRenderer.h
	src/SiohEngine/TriangleRenderer.cpp

	src/SiohEngine/Component.h
	src/SiohEngine/Component.cpp
)

target_link_libraries(SiohEngine SDL2 SDL2main)

add_executable(game
	src/game/main.cpp
)

target_link_libraries(game SiohEngine)