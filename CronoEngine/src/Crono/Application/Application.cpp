// Copyright 2024 CronoGames
#include "crpch.h"
#include "Application.h"
#include <Crono/Core/Base.h>

namespace Crono
{
	Application::Application()
	{
	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		float deltaTime = 0.0f;
		CR_INFO("Application starting");
		while (true)
		{
			Update(deltaTime);
		}
	}

} // namespace Crono