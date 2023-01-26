#include "imgui.h"
#include "imgui_internal.h"

namespace Window {
    int FrameCheck(int vp_id, int pass_check){
        if(pass_check){
            return 1;
        }
        return 0;
    }
    int ViewingFrame(){
        //get the current window ID
        int err;
        ImGuiIO& io = ImGui::GetIO();
        ImGuiWindow* window = ImGui::GetCurrentWindow();
        int win_ID = window->ID;
        //get the current viewport ID
        ImGuiViewport* viewport = ImGui::GetMainViewport();
        int viewport_ID = viewport->ID;
        err = FrameCheck(viewport_ID, 0);
        return 0;
    }
}