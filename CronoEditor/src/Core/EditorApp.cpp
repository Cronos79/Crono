// Copyright 2024 CronoGames
#include "EditorApp.h"
#include "Platform/Win32/Win32EntryPoint.cpp"
#include "EditorLayer.h"

namespace CEditor
{
	EditorApp::EditorApp()
	{
		PushLayer(new EditorLayer());
	}
	EditorApp::~EditorApp()
	{
	}

} // namespace CEditor

Crono::Application* CreateApplication()
{
	return new CEditor::EditorApp();
}