// Copyright 2024 CronoGames
#include "crpch.h"
#include "Crono/Application/Application.h"
#include <Crono/Core/Log.h>

/// <summary>
/// This is for all Windows based applications. Even if the application uses GLFW.
/// </summary>

// Called in client
extern Crono::Application* CreateApplication();

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	Crono::Log::Init();
	Crono::Application* app = CreateApplication();
	app->Run();
	delete app;
	return 0;
}


int main()
{
	return WinMain(GetModuleHandle(NULL), NULL, GetCommandLineA(), SW_SHOW);
}	