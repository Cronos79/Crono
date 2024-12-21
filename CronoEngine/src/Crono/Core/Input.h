#pragma once
#include "Crono/Core/KeyCodes.h"
#include "Crono/Core/MouseCodes.h"

namespace Crono
{
	class Input
	{
	public:
		virtual bool IsKeyPressed(KeyCode key);
		virtual bool IsMouseButtonPressed(MouseCode button);
		virtual float GetMouseX();
		virtual float GetMouseY();
	};
}