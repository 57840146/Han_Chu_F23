set(HEADER_FILES
	include/Beaver.h
	BeaverApp.h
	Utilities.h
)

set(SOURCE_FILES
	placeholder.cpp
)

add_definitions(-DBV_DEBUG=2)
add_definitions(-DBEAVER_LIB)

if(WIN32)
	add_definitions(-DBEAVER_MSCPP)
elseif(LINUX)
	add_definitions(-DBEAVER_LINUX)
elseif(APPLE)
	add_definitions(-DBEAVER_APPLE)
endif()

add_library(Beaver SHARED ${HEADER_FILES} ${SOURCE_FILES})

target_precompile_headers(Beaver PRIVATE pch.h)