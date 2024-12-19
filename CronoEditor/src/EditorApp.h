// Copyright 2024 CronoGames
#pragma once
#include "Crono.h"

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
		EditorApp();
		~EditorApp();

		/// <summary>
		/// Implementation from Crono::Application.
		/// Called every frame.
		/// </summary>
		/// <param name="deltaTime"></param>
		void Update(float deltaTime) override;

	};
} // namespace CEditor
