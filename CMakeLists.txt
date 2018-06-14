cmake_minimum_required (VERSION 2.6)
PROJECT (BlockSnake)
SET (CMAKE_CXX_STANDARD 11)


INCLUDE_DIRECTORIES(./Include)

if(APPLE)
	FIND_LIBRARY(COCOA_LIBRARY Cocoa)
	FIND_PACKAGE(OpenGL REQUIRED)
	INCLUDE_DIRECTORIES(${OPENGL_INCLUDE_DIR})

	SET(
		PLATFORM_HEADERS
		./Include/MacApp.h
	)

	SET(
		PLATFORM_LIBS
		${COCOA_LIBRARY} 
		${OPENGL_LIBRARIES}
	)

	SET(
		PLATFORM_SOURCES
		src/MacApp.mm
	)
ELSE()
	FIND_PACKAGE(OpenGL REQUIRED)
	FIND_PACKAGE(X11 REQUIRED)
	FIND_PACKAGE(GLEW REQUIRED)

	SET(
		PLATFORM_INCLUDES
		${OPENGL_INCLUDE_DIR} 
		${GLEW_INCLUDE_DIRS}
	)

	SET(
		PLATFORM_HEADERS
		./Include/GnuApp.hpp
	)

	SET(
		PLATFORM_LIBS
		${GLEW_LIBRARIES} 
		${OPENGL_LIBRARIES} 
		${X11_LIBRARIES}
	)


	ADD_DEFINITIONS( "-g -Wall  -O0" )

	SET(
		PLATFORM_SOURCES
		src/GnuApp.cpp
	)
ENDIF()


# Global dependencies shared across platforms
SET (
	BLOCKSNAKE_SOURCES
	${PLATFORM_SOURCES}
	src/Application.cpp
	src/AssetManager.cpp
	src/AssetNotFoundException.cpp
	src/Background.cpp
	src/Fruit.cpp
	src/GameObject.cpp
	src/GameOverScene.cpp
	src/MainMenu.cpp
	src/PrimitiveCube.cpp
	src/PrimitiveForm.cpp
	src/PrimitiveQuad.cpp
	src/ProgramAsset.cpp
	src/Scene.cpp
	src/ShaderAsset.cpp
	src/SnakeBody.cpp
	src/SnakeHead.cpp
	src/SnakeScene.cpp
	src/TextureAsset.cpp
)

SET (
	BLOCKSNAKE_HEADERS
	${PLATFORM_INCLUDE}
	./Include/Math/Matrix4x4.hpp
	./Include/Math/Utilities.hpp
	./Include/Math/Vector2.hpp
	./Include/Math/Vector3.hpp
	./Include/Math/Vector4.hpp
	./Include/Application.hpp
	./Include/AssetManager.hpp
	./Include/AssetNotFoundException.hpp
	./Include/Background.hpp
	./Include/Fruit.hpp
	./Include/GameObject.hpp
	./Include/GameOverScene.hpp
	./Include/Globals.hpp
	./Include/KeyCodes.hpp
	./Include/MainMenu.hpp
	./Include/PrimitiveCube.hpp
	./Include/PrimitiveForm.hpp
	./Include/PrimitiveQuad.hpp
	./Include/ProgramAsset.hpp
	./Include/Renderer.hpp
	./Include/Resource.hpp
	./Include/Scene.hpp
	./Include/ShaderAsset.hpp
	./Include/SnakeBody.hpp
	./Include/SnakeHead.hpp
	./Include/SnakeScene.hpp
	./Include/TextureAsset.hpp
)

ADD_EXECUTABLE(BlockSnake ${BLOCKSNAKE_HEADERS} ${BLOCKSNAKE_SOURCES})

INCLUDE_DIRECTORIES(BlockSnake ${PLATFORM_INCLUDES})

TARGET_LINK_LIBRARIES(BlockSnake ${PLATFORM_LIBS})





