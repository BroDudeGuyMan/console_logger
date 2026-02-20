#include <console_logger/console_logger.h>

#include <string>
#include <iostream>


void logger::info(std::string& msg) {
	std::cout << "[INFO   ] " << msg << std::endl;
}
void logger::input(std::string& msg) {
	std::cout << "[INPUT  ] " << msg << std::endl;
	std::cout << "\t\t >>>";
}
void logger::warning(std::string& msg) {
	std::cout << "[WARNING] " << msg << std::endl;
}
void logger::error(std::string& msg) {
	std::cout << "[ERROR  ] " << msg << std::endl;
}
void logger::fatal(std::string& msg) {
	std::cout << "[FATAL  ] " << msg << std::endl;
}
