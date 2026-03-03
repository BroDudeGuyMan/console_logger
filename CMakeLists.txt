cmake_minimum_required(VERSION 3.2)

project(console_logger
	VERSION 1.0.3
	DESCRIPTION
	"A simple C++ wrapper for making uniform console output."
	LANGUAGES CXX
)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(console_logger)
add_library(console_logger::console_logger ALIAS console_logger)

set_target_properties(
	console_logger
	PROPERTIES VERSION ${PROJECT_VERSION}
	SOVERSION ${PROJECT_VERSION_MAJOR}
)

target_sources(console_logger
	PRIVATE
	src/console_logger.cpp
)

target_compile_features(
	console_logger
	PUBLIC cxx_std_17
)

target_include_directories(
	console_logger
	PRIVATE src
	PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

include(GenerateExportHeader)

set_target_properties(console_logger PROPERTIES CXX_VISIBILITY_PRESET "hidden"
						VISIBILITY_INLINES_HIDDEN TRUE)

generate_export_header(
	console_logger
	EXPORT_FILE_NAME
	export/console_logger/export_console_logger.hpp
)

target_include_directories(
	console_logger
	PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/export>
	$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

include(GNUInstallDirs)

install(
	TARGETS console_logger
	EXPORT console_loggerTargets
	LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
	ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
	RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
	INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(
	FILES "${CMAKE_CURRENT_BINARY_DIR}/export/console_logger/export_console_logger.hpp"
	DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/console_logger
)

include(CMakePackageConfigHelpers)

write_basic_package_version_file(
	"console_loggerConfigVersion.cmake"
	VERSION ${PROJECT_VERSION}
	COMPATIBILITY SameMajorVersion)

configure_package_config_file(
	"${CMAKE_CURRENT_LIST_DIR}/cmake/console_loggerConfig.cmake.in"
	"${CMAKE_CURRENT_BINARY_DIR}/console_loggerConfig.cmake"
	INSTALL_DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/cmake/console_logger
)

install(
	EXPORT console_loggerTargets
	FILE console_loggerTargets.cmake
	NAMESPACE console_logger::
	DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/cmake/console_logger
)
