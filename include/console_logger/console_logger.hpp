#pragma once

#include <console_logger/export_console_logger.hpp>
#include <string>

/// Namespace for the entire logging library.
namespace CONSOLE_LOGGER_EXPORT logger {
	/**
	 * Optional function to make sure Windows terminals will render colors. Colors are enabled by default, but if the environment has them completely disabled, ANSI codes will render as gibberish.
	 */
	void init();
	/**
	 * For simple messages and notifications.
	 * @param[in] msg `const std::string` to be displayed to the user.
	 */
	void    info(const std::string& msg);
	/**
	 * For developers to find crucial info and validate data.
	 * @param[in] msg 'const std::string' to be displayed, const std::to_string() works.
	 */
	void debug(const std::string& msg);
	/**
	 * For prompting the user for input. Adds '>>>' to let the user know its a pompt.
	 * @param[in] msg `const std::string` to be displayed to the user.
	 */
	void   input(const std::string& msg);
	/**
	 * For letting the user know about possible issues.
	 * @param[in] msg either an `e.what()` or a custom warning.
	 */
	void warning(const std::string& msg);
	/**
	 * For showing the user system error messages that will impact functionality.
	 * @param[in] msg either an `e.what()` or a custom error message.
	 */
	void   error(const std::string& msg);
	/** 
	 * For alerting to an error that will completely halt the program or cause destructive behavior.
	 * @param[in] msg either `e.what()` or a custom error message.
	 */
	void   fatal(const std::string& msg);
}
