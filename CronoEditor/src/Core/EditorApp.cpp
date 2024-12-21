// Copyright 2024 CronoGames
#include "EditorApp.h"
#include "Platform/Win32/Win32EntryPoint.cpp"
#include "EditorLayer.h"

namespace CEditor
{
	EditorApp::EditorApp(Crono::WindowProps props)
		: Crono::Application(props)
	{
		PushLayer(new EditorLayer());
	}
	EditorApp::~EditorApp()
	{
	}

} // namespace CEditor

Crono::Application* CreateApplication()
{
	Crono::WindowProps props = {};
	props.Title = "Crono Editor";
	props.Width = 1920;
	props.Height = 1080;
	return new CEditor::EditorApp(props);
}