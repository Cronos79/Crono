// Copyright 2024 CronoGames
#pragma once
#include "Crono.h"
#include <Crono/Core/Window.h>

namespace CEditor
{
	/// <summary>
	/// Main entry point for the editor application.
	/// </summary>
	class EditorApp : public Crono::Application
	{
	public:
		/// <summary>
		/// Constructor and Destructor.
		/// </summary>
		EditorApp(Crono::WindowProps props);
		~EditorApp();

	};
} // namespace CEditor
