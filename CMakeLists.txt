cmake_minimum_required(VERSION 3.2)
project(console_logger LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(console_logger src/console_logger.cpp)
target_include_directories(console_logger
	PUBLIC
	 $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	 $<INSTALL_INTERFACE:include>
)

install(TARGETS console_logger
	EXPORT console_loggerTargets
	ARCHIVE DESTINATION lib
	LIBRARY DESTINATION lib
	RUNTIME DESTINATION bin
)

install(DIRECTORY include/
	DESTINATION include
)
