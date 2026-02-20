cmake_minimum_required(VERSION 3.2)
project(console_logger LANGUAGES CXX)

add_library(console_logger src/console_logger.cpp)
target_include_directories(console_logger
	PUBLIC
	 ${CMAKE_CURRENT_SOURCE_DIR}/include
)
