#include "precompiled.h"

#include "Core/Log.h"

#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>

namespace SmartGL
{
	namespace Core
	{
		Shared<spdlog::logger> Logger::s_Logger;

		void Logger::Init()
		{
			std::vector<spdlog::sink_ptr> logSinks;
			logSinks.emplace_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());

			#if defined(SMART_COMPILER_MINGW) || defined(SMART_PLATFORM_LINUX)
						std::string path = "SmartGL/SmartGL.log";
			#else
						std::string path = "../SmartGL/SmartGL.log";
			#endif

			logSinks.emplace_back(std::make_shared<spdlog::sinks::basic_file_sink_mt>(path.c_str(), true));

			logSinks[0]->set_pattern("%^[%T] %n: %v%$");
			logSinks[1]->set_pattern("[%T] [%l] %n: %v");

			s_Logger = std::make_shared<spdlog::logger>("LOG", begin(logSinks), end(logSinks));
			spdlog::register_logger(s_Logger);
			s_Logger->set_level(spdlog::level::trace);
			s_Logger->flush_on(spdlog::level::trace);
		}

		void Logger::Shutdown()
		{
			s_Logger.reset();
			spdlog::drop_all();
		}
	}
}
