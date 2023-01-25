#include <GLFW/glfw3.h>
#include <imgui.h>

#include "viewport.hpp"

using namespace ImGui;

namespace ViewPort {
	void ViewPort_Init() {
		Begin("Viewport");
		Text("No item detected.");
		Button("Add a gerber or step file.");
		End();
	}
}
//TODO: add util for lib version checking
// int *glf_version_major = (int*)GLFW_VERSION_MAJOR;
// assert(glf_version_major <= 3);
// printf("Version %d is not the correct version, please update GLFW", GLFW_VERSION_MAJOR);
