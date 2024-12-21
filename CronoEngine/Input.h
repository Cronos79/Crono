#pragma once
#include "Crono/Core/KeyCodes.h"
#include "Crono/Core/MouseCodes.h"

//#include <glm/glm.hpp>

namespace Crono
{

	class Input
	{
	public:
		static bool IsKeyPressed(KeyCode key);
		static bool IsMouseButtonPressed(MouseCode button);
		//static glm::vec2 GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();
	private:
		Input* s_Instance;
	};
}