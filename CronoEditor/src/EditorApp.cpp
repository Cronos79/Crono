// Copyright 2024 CronoGames
#include "EditorApp.h"
#include "Crono/Platform/Win32/Win32EntryPoint.cpp"

namespace CEditor
{
	EditorApp::EditorApp()
	{
	}
	EditorApp::~EditorApp()
	{
	}

	void EditorApp::Update(float deltaTime)
	{
		//OutputDebugStringA("Hello from EditorApp::Update\n");
	}

} // namespace CEditor

Crono::Application* CreateApplication()
{
	return new CEditor::EditorApp();
}