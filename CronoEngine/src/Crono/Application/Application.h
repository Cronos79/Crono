// Copyright 2024 CronoGames
#pragma once
#include "../Core/Window.h"
#include "../Events/ApplicationEvent.h"
#include <Crono/Core/LayerStack.h>
#include "ImGuiLayer.h"

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
		/// Event handler
		/// </summary>
		/// <param name="e"></param>
		void OnEvent(Event& e);

		/// <summary>
		/// Pushes a layer to the layer stack
		/// </summary>
		/// <param name="layer"></param>
		void PushLayer(Layer* layer);

		/// <summary>
		/// Pushes an overlay to the layer stack
		/// </summary>
		/// <param name="layer"></param>
		void PushOverlay(Layer* layer);

		/// <summary>
		/// Gets this application object
		/// </summary>
		/// <returns></returns>
		static Application& Get()
		{
			return *s_Instance;
		}

		/// <summary>
		/// Gets the window
		/// </summary>
		/// <returns></returns>
		Window& GetWindow()
		{
			return *m_Window;
		}

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
		/// <summary>
		/// Window abstract class. Not Win32 specific.
		/// </summary>
		std::unique_ptr<Window> m_Window;

		/// <summary>
		/// Is the application still running?
		/// </summary>
		bool m_Running = true;

		/// <summary>
		/// The layer stack
		/// </summary>
		LayerStack m_LayerStack;

		/// <summary>
		/// application object
		/// </summary>
		static Application* s_Instance;

		ImGuiLayer* m_ImGuiLayer;
		float m_LastFrameTime = 0.0f;
	};
}

/// <summary>
/// Define this function in the CLIENT
/// </summary>
/// <returns>Application instance</returns>
Crono::Application* CreateApplication();