// Copyright 2024 CronoGames
#include "crpch.h"
#include "Application.h"
#include <Crono/Core/Base.h>
#include <gl/GL.h>
#include <Crono/Events/ApplicationEvent.h>
#include "../Core/Log.h"
#include <ImGuiLayer.h>
#include "../Utils/PlatformUtils.h"

namespace Crono
{
	Application* Application::s_Instance = nullptr;

	Application::Application(WindowProps props)
	{
		m_Window = std::unique_ptr<Window>(Window::Create(props));
		m_Window->SetEventCallback(CR_BIND_EVENT_FN(Application::OnEvent));

		s_Instance = this;

		m_ImGuiLayer = new ImGuiLayer();
		PushOverlay(m_ImGuiLayer);
	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		float time = Time::GetTime();
		Timestep deltaTime = time - m_LastFrameTime;
		m_LastFrameTime = time;

		CR_INFO("Application starting");
		//ImGuiLayer imGuiLayer;
		while (m_Running)
		{
			glClearColor(1.0f, 0.1f, 0.1f, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			for (Layer* layer : m_LayerStack)
			{
				layer->OnUpdate(deltaTime);
			}
			m_ImGuiLayer->Begin();
			for (Layer* layer : m_LayerStack)
			{
				layer->OnImGuiRender();
			}
			m_ImGuiLayer->End();
			m_Window->OnUpdate();
			
		}
	}

	void Application::OnEvent(Event& e)
	{
		//CR_CORE_TRACE("{0}", e.ToString());
		//CR_PROFILE_FUNCTION();

		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(CR_BIND_EVENT_FN(Application::OnWindowClose));
		dispatcher.Dispatch<WindowResizeEvent>(CR_BIND_EVENT_FN(Application::OnWindowResize));

		for (auto it = m_LayerStack.rbegin(); it != m_LayerStack.rend(); ++it)
		{
			if (e.Handled)
				break;
			(*it)->OnEvent(e);
		}
	}

	void Application::PushLayer(Layer* layer)
	{
		//HZ_PROFILE_FUNCTION();

		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer* layer)
	{
		//HZ_PROFILE_FUNCTION();

		m_LayerStack.PushOverlay(layer);
		layer->OnAttach();
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}

	bool Application::OnWindowResize(WindowResizeEvent& e)
	{
		//HZ_PROFILE_FUNCTION();

		if (e.GetWidth() == 0 || e.GetHeight() == 0)
		{
			//m_Minimized = true;
			return false;
		}

		//m_Minimized = false;
		//Renderer::OnWindowResize(e.GetWidth(), e.GetHeight());

		return false;
	}

} // namespace Crono