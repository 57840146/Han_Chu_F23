set(HEADER_FILES
	include/Gehc.h
	GehcApp.h
	Events.h
	GameWindow.h
	Utilities.h
	GameWindow.h
	WindowImplementation.h
	GLFWCode/GLFWImplementation.h
	GLFWCode/OpenGLPicture.h
	GLFWCode/OpenGLRenderer.h
	GLFWCode/OpenGLShader.h
	Picture.h
	PictureImplementation.h
	Renderer.h
	RendererImplementation.h
	Shader.h
	ShaderImplementation.h
	Unit.h
	WindowImplementation.h
)

set(SOURCE_FILES
	Events.cpp
	GameWindow.cpp
	GLFWCode/GLFWImplementation.cpp
	GLFWCode/OpenGLPicture.cpp
	GLFWCode/OpenGLRenderer.cpp
	GLFWCode/OpenGLShader.cpp
	Picture.cpp
	Renderer.cpp
	Shader.cpp
	Unit.cpp
)

add_definitions(-DHC_DEBUG=2)
add_definitions(-DGEHC_LIB)

include_directories(../Gehc)
include_directories(../glfw/include)
include_directories(../glad/include)
include_directories(../stbi)


add_library(Gehc SHARED ${HEADER_FILES} ${SOURCE_FILES})

target_precompile_headers(Gehc PRIVATE pch.h)

target_link_libraries(Gehc glfw)
target_link_libraries(Gehc glad)
target_link_libraries(Gehc stbi)
