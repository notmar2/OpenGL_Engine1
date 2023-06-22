#include "GUI.h"

void GUI::createFrame() {
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();
}

void GUI::begin() {
	ImGui::Begin("fak");
	ImGui::Text("Hasfjkañlsdfjaksd");
}

void GUI::checkbox(bool* check) {
	ImGui::Checkbox("Render", check);
}

void GUI::colorEdit(float color[3]) {
	ImGui::ColorEdit3("ColorPicker", color);
}

void GUI::render() {
	ImGui::End();
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void GUI::shutdown() {
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
}