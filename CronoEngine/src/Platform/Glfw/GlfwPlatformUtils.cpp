#include "crpch.h"
#include "Crono/Utils/PlatformUtils.h"

#include <GLFW/glfw3.h>
#define GLFW_EXPOSE_NATIVE_WIN32
#include <GLFW/glfw3native.h>


namespace Crono
{
	float Time::GetTime()
	{
		return glfwGetTime();
	}
}