// Copyright 2024 CronoGames
#include "crpch.h"
#include "Window.h"

#ifdef CR_PLATFORM_WINDOWS
#include <Platform/Win32/Win32Window.h>
#endif


namespace Crono
{
	Scope<Window> Window::Create(const WindowProps& props)
	{
#ifdef CR_PLATFORM_WINDOWS
		return CreateScope<Win32Window>(props);
#else
		//HZ_CORE_ASSERT(false, "Unknown platform!");
		return nullptr;
#endif
	}

}