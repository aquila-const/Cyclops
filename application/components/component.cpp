#include "imgui.h"
#include "component.hpp"
#include <string.h>
#include <stdio.h>
#include <implot.h>

//TODO: handle dynamic component attribution(generating)
namespace Component {
	void Sidebar_Init(const char* window_title)
	{
		ImGui::Begin(window_title, 0);
        if (ImGui::BeginTabBar("Plots")) {
            
            if (ImGui::BeginTabItem("Phase")) {
                if (ImPlot::BeginPlot("##Bode2")) {
                    ImPlot::SetupAxesLimits(1, 500, -180, 10);
                    ImPlot::SetupAxes("Frequency [Hz]", "Phase Angle [deg]");
                    ImPlot::SetupAxisScale(ImAxis_X1, ImPlotScale_Log10);
                    ImPlot::SetNextFillStyle(IMPLOT_AUTO_COL, 0.250f);
                   
                    ImPlot::EndPlot();
                }
                ImGui::EndTabItem();
            }
            
           
            ImGui::EndTabBar();
        }

		ImGui::End();
	}
}
