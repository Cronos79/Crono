// Copyright 2024 CronoGames
#pragma once

#include <memory>

#ifdef CR_DEBUG
	#if defined(CR_PLATFORM_WINDOWS)
		#define CR_DEBUGBREAK() __debugbreak()
	#elif defined(CR_PLATFORM_LINUX)
		#include <signal.h>
		#define CR_DEBUGBREAK() raise(SIGTRAP)
	#else
		//#error "Platform doesn't support debugbreak yet!"
	#endif
		#define CR_ENABLE_ASSERTS
	#else
		#define CR_DEBUGBREAK()
#endif

#define BIT(x) (1 << x)

#define CR_BIND_EVENT_FN(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }

namespace Crono
{

	template<typename T>
	using Scope = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Ref = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}

}

#include "Crono/Core/Log.h"