#pragma once

#include <string>

namespace logger {
	void    info(std::string& msg);
	void   input(std::string& msg);
	void warning(std::string& msg);
	void   error(std::string& msg);
	void   fatal(std::string& msg);
}
