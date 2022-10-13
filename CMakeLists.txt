cmake_minimum_required(VERSION 3.0)
project(SIOHENGINE)

include_directories(
	src
)

add_library(SiohEngine
	src/SiohEngine/SiohEngine.h
	
	src/SiohEngine/Core.h
	src/SiohEngine/Core.cpp

	src/SiohEngine/Entity.h
	src/SiohEngine/Entity.cpp

	src/SiohEngine/Component.h
	src/SiohEngine/Component.cpp
)

add_executable(game
	src/game/main.cpp
)

target_link_libraries(game SiohEngine)