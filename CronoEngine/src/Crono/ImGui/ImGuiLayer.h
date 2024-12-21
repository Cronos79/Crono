#pragma once
#include "Crono/Core/Layer.h"

#include "Crono/Events/ApplicationEvent.h"
#include "Crono/Events/KeyEvent.h"
#include "Crono/Events/MouseEvent.h"

namespace Crono
{

	class ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnEvent(Event& e) override;

		void Begin();
		void End();

		void BlockEvents(bool block)
		{
			m_BlockEvents = block;
		}

		void SetDarkThemeColors();

		uint32_t GetActiveWidgetID() const;
	private:
		bool m_BlockEvents = true;
	};

}

