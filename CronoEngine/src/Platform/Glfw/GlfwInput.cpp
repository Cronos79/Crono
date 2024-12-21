#include "crpch.h"
#include "GlfwInput.h"

#include "Crono/Application/Application.h"
#include <GLFW/glfw3.h>




namespace Crono
{
	glm::vec2 GlfwInput::GetMousePosition()
	{
		auto* window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);

		return { (float)xpos, (float)ypos };
	}

	bool GlfwInput::IsKeyPressed(KeyCode key)
	{
		auto* window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		auto state = glfwGetKey(window, static_cast<int32_t>(key));
		return state == GLFW_PRESS;
	}

	bool GlfwInput::IsMouseButtonPressed(MouseCode button)
	{
		auto* window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		auto state = glfwGetMouseButton(window, static_cast<int32_t>(button));
		return state == GLFW_PRESS;
	}

	float GlfwInput::GetMouseX()
	{
		return GetMousePosition().x;
	}

	float GlfwInput::GetMouseY()
	{
		return GetMousePosition().y;
	}

}
