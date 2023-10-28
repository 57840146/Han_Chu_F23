set(HEADER_FILES
	include/Gehc.h
	GehcApp.h
	Utilities.h
	GameWindow.h
	WindowImplementation.h
	GLFWCode/GLFWImplementation.h
)

set(SOURCE_FILES
	GameWindow.cpp
	GLFWCode/GLFWImplementation.cpp
)

add_definitions(-DHC_DEBUG=2)
add_definitions(-DGEHC_LIB)

include_directories(../Gehc)
include_directories(../glfw/include)

add_library(Gehc SHARED ${HEADER_FILES} ${SOURCE_FILES})

target_precompile_headers(Gehc PRIVATE pch.h)

target_link_libraries(Gehc glfw)