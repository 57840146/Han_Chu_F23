set(HEADER_FILES
	include/Beaver.h
	BeaverApp.h
	Utilities.h
	GameWindow.h
	WindowImplementation.h
	GLFWCode/GLFWImplementation.h
)

set(SOURCE_FILES
	GameWindow.cpp
	GLFWCode/GLFWImplementation.cpp
)

add_definitions(-DBV_DEBUG=2)
add_definitions(-DBEAVER_LIB)

include_directories(../Beaver)
include_directories(../glfw/include)

add_library(Beaver SHARED ${HEADER_FILES} ${SOURCE_FILES})

target_precompile_headers(Beaver PRIVATE pch.h)

target_link_libraries(Beaver glfw)