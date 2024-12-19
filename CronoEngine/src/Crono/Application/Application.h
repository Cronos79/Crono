// Copyright 2024 CronoGames
#pragma once
#include "../Core/Window.h"
#include "../Events/ApplicationEvent.h"

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

		/// <summary>
		/// Event handler
		/// </summary>
		/// <param name="e"></param>
		void OnEvent(Event& e);

	private:
		/// <summary>
		/// Close event
		/// </summary>
		/// <param name="e"></param>
		/// <returns></returns>
		bool OnWindowClose(WindowCloseEvent& e);
		/// <summary>
		/// Resize event
		/// </summary>
		/// <param name="e"></param>
		/// <returns></returns>
		bool OnWindowResize(WindowResizeEvent& e);

	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};
}

/// <summary>
/// Define this function in the CLIENT
/// </summary>
/// <returns>Application instance</returns>
Crono::Application* CreateApplication();