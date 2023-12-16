set(HEADER_FILES
	
)

set(SOURCE_FILES
	main.cpp
)

add_executable(Game_HC ${HEADER_FILES} ${SOURCE_FILES})

target_link_libraries(Game_HC Gehc)

include_directories(../Gehc/include)