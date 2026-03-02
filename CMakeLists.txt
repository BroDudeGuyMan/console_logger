cmake_minimum_required(VERSION 3.2)
project(console_logger 
	VERSION 1.0.0
	LANGUAGES CXX
)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(console_logger src/console_logger.cpp)
add_library(console_logger::console_logger ALIAS console_logger)

target_include_directories(console_logger
	PUBLIC
	 $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	 $<INSTALL_INTERFACE:include>
)

include(CMakePackageConfigHelpers)

install(
	TARGETS console_logger
	EXPORT console_loggerTargets
	ARCHIVE DESTINATION lib
	LIBRARY DESTINATION lib
	RUNTIME DESTINATION bin
)

install(
	EXPORT console_loggerTargets
	FILE console_loggerTargets.cmake
	NAMESPACE console_logger::
	DESTINATION lib/cmake/console_logger
)

configure_package_config_file(
	cmake/console_loggerConfig.cmake.in
	${CMAKE_CURRENT_BINARY_DIR}/console_loggerConfig.cmake
	INSTALL_DESTINATION lib/cmake/console_logger
)

write_basic_package_version_file(
	${CMAKE_CURRENT_BINARY_DIR}/console_loggerConfigVersion.cmakek
	VERSION ${PROJECT_VERSION}
	COMPATIBILITY SameMajorVersion
)

install(
	FILES
	${CMAKE_CURRENT_BINARY_DIR}/console_loggerConfig.cmake
	${CMAKE_CURRENT_BINARY_DIR}/console_loggerConfigVersion.cmake
	DESTINATION lib/cmake/console_logger
)

install(DIRECTORY include/ DESTINATION include)
