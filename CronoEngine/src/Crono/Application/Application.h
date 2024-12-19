// Copyright 2024 CronoGames
#pragma once

namespace Crono
{
	/// <summary>
	/// Main game application class.
	/// Contains the main game loop.
	/// </summary>
	class Application
	{
	public:
		/// <summary>
		/// Constructor.
		/// </summary>
		Application();
		/// <summary>
		/// Destructor.
		/// </summary>
		virtual ~Application();

		/// <summary>
		/// Main game loop
		/// </summary>
		void Run();

		/// <summary>
		/// To be defined in CLIENT
		/// </summary>
		/// <param name="deltaTime">Time passed per frame</param>
		virtual void Update(float deltaTime) = 0;
	};
}

/// <summary>
/// Define this function in the CLIENT
/// </summary>
/// <returns>Application instance</returns>
Crono::Application* CreateApplication();