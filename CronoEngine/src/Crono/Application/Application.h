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
		Application(WindowProps props);	
		virtual ~Application();

		void Run();	

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);

		void PushOverlay(Layer* layer);

		static Application& Get()
		{
			return *s_Instance;
		}

		Window& GetWindow()
		{
			return *m_Window;
		}

	private:
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);

	private:	
		std::unique_ptr<Window> m_Window;	
		bool m_Running = true;
		LayerStack m_LayerStack;

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