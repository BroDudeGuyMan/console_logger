#pragma once

#include <string>

namespace logger {
	/**
	 * Optional function to make sure Windows terminals will render colors. Colors are enabled by default, but if the environment has them completely disabled, ANSI codes will render as gibberish.
	 */
	void init();
	/**
	 * For simple messages and notifications.
	 * @param[in] msg `std::string` to be displayed to the user.
	 */
	void    info(std::string& msg);
	/**
	 * For prompting the user for input. Adds '>>>' to let the user know its a pompt.
	 * @param[in] msg `std::string` to be displayed to the user.
	 */
	void   input(std::string& msg);
	/**
	 * For letting the user know about possible issues.
	 * @param[in] msg either an `e.what()` or a custom warning.
	 */
	void warning(std::string& msg);
	/**
	 * For showing the user system error messages that will impact functionality.
	 * @param[in] msg either an `e.what()` or a custom error message.
	 */
	void   error(std::string& msg);
	/** 
	 * For alerting to an error that will completely halt the program or cause destructive behavior.
	 * @param[in] msg either `e.what()` or a custom error message.
	 */
	void   fatal(std::string& msg);
}
