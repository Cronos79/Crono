// Copyright 2024 CronoGames
#pragma once

#include <memory>

#ifdef CR_DEBUG
	#if defined(HZ_PLATFORM_WINDOWS)
		#define CR_DEBUGBREAK() __debugbreak()
	#elif defined(HZ_PLATFORM_LINUX)
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

#include "Crono/Core/Log.h"