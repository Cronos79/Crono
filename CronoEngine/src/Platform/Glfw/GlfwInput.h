// Copyright (c) 2024 CronoGames. All Rights Reserved.
// File: C:\Projects\Crono\CronoEngine\src\Platform\Glfw\GlfwInput.h
// Date: 12/21/2024
// Author: Matt Brock
#pragma once
#include "Crono/Core/Input.h"
#include "glm/glm.hpp"

namespace Crono
{
	class GlfwInput : public Input
	{
	public:	
		glm::vec2 GetMousePosition();
		bool IsKeyPressed(KeyCode key) override;
		bool IsMouseButtonPressed(MouseCode button) override;
		float GetMouseX() override;
		float GetMouseY() override;

		// singleton
		static GlfwInput& Get()
		{
			static GlfwInput instance;
			return instance;
		}
	private:
		GlfwInput() = default;
		GlfwInput(const GlfwInput&) = delete;
		GlfwInput& operator=(const GlfwInput&) = delete;
	};
}


