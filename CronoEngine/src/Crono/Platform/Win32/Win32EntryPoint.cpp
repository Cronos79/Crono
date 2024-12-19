// Copyright 2024 CronoGames
#include "Crono/Application/Application.h"
#include "WinIncludes.h"
#include <Crono/Core/Log.h>

/// <summary>
/// Define this function in the CLIENT
/// </summary>
/// <returns>Application instance</returns>
extern Crono::Application* CreateApplication();

/// <summary>
/// WinMain entry point
/// </summary>
/// <param name="hInstance">Windows param</param>
/// <param name="hPrevInstance">Windows param</param>
/// <param name="lpCmdLine">Windows param</param>
/// <param name="nCmdShow">Windows param</param>
/// <returns></returns>
int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	Crono::Log::Init();
	Crono::Application* app = CreateApplication();
	app->Run();
	delete app;
	return 0;
}

/// <summary>
/// Called in debug for extra logging
/// </summary>
/// <returns></returns>
int main()
{
	return WinMain(GetModuleHandle(NULL), NULL, GetCommandLineA(), SW_SHOW);
}	