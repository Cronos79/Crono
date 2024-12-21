#include "EditorLayer.h"
#include "imgui.h"

using namespace Crono;

namespace CEditor
{
	EditorLayer::EditorLayer()
		: Layer("EditorLayer")
	{
	}

	void EditorLayer::OnAttach()
	{
		CR_INFO("Hello from EditorLayer::OnAttach");
	}

	void EditorLayer::OnDetach()
	{
	}

	void EditorLayer::OnImGuiRender()
	{
		ImGuiIO& io = ImGui::GetIO(); (void)io;
		ImGui::Begin("FPS");
		ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / io.Framerate, io.Framerate);
		ImGui::End();
	}
} // namespace Crono