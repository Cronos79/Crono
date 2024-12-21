#pragma once
#include "Crono.h"

namespace CEditor
{
	class EditorLayer : public Crono::Layer
	{
	public:
		EditorLayer();
		virtual ~EditorLayer() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;

		virtual void OnImGuiRender() override;
	};
}
