// Copyright 2024 CronoGames
#pragma once
#include "Crono/Core/Core.h"
#include "spdlog/spdlog.h"

namespace Crono
{
	/// <summary>
	/// spdlog wrapper
	/// </summary>
	class Log
	{
	public:
		/// <summary>
		/// Initialize the logger
		/// </summary>
		static void Init();

		/// <summary>
		/// Get the core logger
		/// </summary>
		/// <returns>Logger</returns>
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger()
		{
			return s_CoreLogger;
		}

		/// <summary>
		/// Get the client logger
		/// </summary>
		/// <returns>Logger</returns>
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger()
		{
			return s_ClientLogger;
		}

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Log macros
// Debug
#ifdef _DEBUG
#define CR_CORE_TRACE(...)    ::Crono::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define CR_CORE_INFO(...)     ::Crono::Log::GetCoreLogger()->info(__VA_ARGS__)
#define CR_CORE_WARN(...)     ::Crono::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define CR_CORE_ERROR(...)    ::Crono::Log::GetCoreLogger()->error(__VA_ARGS__)
#define CR_CORE_FATAL(...)    ::Crono::Log::GetCoreLogger()->critical(__VA_ARGS__)

#define CR_TRACE(...)         ::Crono::Log::GetClientLogger()->trace(__VA_ARGS__)
#define CR_INFO(...)          ::Crono::Log::GetClientLogger()->info(__VA_ARGS__)
#define CR_WARN(...)          ::Crono::Log::GetClientLogger()->warn(__VA_ARGS__)
#define CR_ERROR(...)         ::Crono::Log::GetClientLogger()->error(__VA_ARGS__)
#define CR_FATAL(...)         ::Crono::Log::GetClientLogger()->critical(__VA_ARGS__)
#else
// Release
#define CR_CORE_TRACE(...)
#define CR_CORE_INFO(...)
#define CR_CORE_WARN(...)
#define CR_CORE_ERROR(...)
#define CR_CORE_FATAL(...)

#define CR_TRACE(...)	
#define CR_INFO(...)
#define CR_WARN(...)	
#define CR_ERROR(...)
#define CR_FATAL(...)
#endif
