#pragma once
#include "Crono/Core/Base.h"
#include "Crono/Core/Timestep.h"
#include "Crono/Events/Event.h"

namespace Crono
{

	class Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer() = default;

		virtual void OnAttach()
		{
		}
		virtual void OnDetach()
		{
		}
		virtual void OnUpdate(Timestep ts)
		{
		}
		virtual void OnImGuiRender()
		{
		}
		virtual void OnEvent(Event& event)
		{
		}

		const std::string& GetName() const
		{
			return m_DebugName;
		}
	protected:
		std::string m_DebugName;
	};

}
