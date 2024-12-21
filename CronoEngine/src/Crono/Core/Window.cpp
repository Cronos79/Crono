// Copyright 2024 CronoGames
#include "crpch.h"
#include "Window.h"

#ifdef CR_PLATFORM_GLFW
#include <Platform/Glfw/GlfwWindow.h>
#endif


namespace Crono
{
	Scope<Window> Window::Create(const WindowProps& props)
	{
#ifdef CR_PLATFORM_GLFW
		return CreateScope<GlfwWindow>(props);
#else
		//HZ_CORE_ASSERT(false, "Unknown platform!");
		return nullptr;
#endif
	}

}