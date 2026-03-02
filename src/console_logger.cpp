#include <console_logger/console_logger.h>


#include <string>
#include <iostream>

namespace ansi {
	constexpr const char* reset    = "\033[0m";
	constexpr const char* red      = "\033[31m";
	constexpr const char* green    = "\033[32m";
	constexpr const char* yellow   = "\033[33m";
	constexpr const char* blue     = "\033[34m";
	constexpr const char* bold_red = "\033[1;31m";
}

namespace logger::detail {
	inline bool color_enabled = true;
	inline const char* emit(const char* code) {
		return color_enabled ? code : "";
	}
}

#ifdef _WIN32
#include <windows.h>
bool enable_ansi_colors() {
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hOut == INVALID_HANDLE_VALUE)
		return false;

	DWORD dwMode = 0;
	if (!GetConsoleMode(hOut, &dwMode))
		return false;

	dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;

	if (!SetConsoleMode(hOut, dwMode))
		return false;

	return true;
}
#endif
void logger::init() {
#ifdef _WIN32
	detail::color_enabled = enable_ansi_colors();
#else
	detail::color_enabled = true;
#endif
}

void logger::info(std::string& msg) {
	std::cout << std::endl
		<< detail::emit(ansi::green)
		<< "[INFO   ] "
		<< detail::emit(ansi::reset)
		<< msg
		<< std::endl;
}
void logger::input(std::string& msg) {
	std::cout << std::endl
		<< detail::emit(ansi::blue)
		<< "[INPUT  ] "
		<< detail::emit(ansi::reset)
		<< msg
		<< std::endl
		<< "\t\t >>>";
}
void logger::warning(std::string& msg) {
	std::cout << std::endl
		<< detail::emit(ansi::yellow)
		<< "[WARNING] "
		<< detail::emit(ansi::reset)
		<< msg
		<< std::endl;
}
void logger::error(std::string& msg) {
	std::cout << std::endl
		<< detail::emit(ansi::red)
		<< "[ERROR  ] "
		<< detail::emit(ansi::reset)
		<< msg
		<< std::endl;
}
void logger::fatal(std::string& msg) {
	std::cout << std::endl
		<< detail::emit(ansi::bold_red)
		<< "[FATAL  ] "
		<< detail::emit(ansi::reset)
		<< msg
		<< std::endl;
}
