#include "gui.h"
#include "global.h"
#include "Utils.h"
#include "utils/gui-util.hpp"

void Gui::Render()
{
	auto& vars = Vars::GetInstance();
	
    ImGui::Begin("##Taiga74164", nullptr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar);
    {
        ImGui::BeginGroup();
        {
            ImGui::PushStyleColor(ImGuiCol_ChildBg, IM_COL32(0, 0, 0, 0));
            GuiUtil::CenterText("Solo Leveling Cheeto", 0, 0);
            ImGui::Spacing();
            ImGui::Spacing();
            ImGui::PopStyleColor();
        }
        ImGui::EndGroup();

		GuiUtil::RainbowLine();
		ImGui::PushStyleColor(ImGuiCol_ChildBg, IM_COL32(0, 0, 0, 0));
		ImGui::BeginChild("##LeftSide", ImVec2(100, GuiUtil::GetY()), TRUE);
		ImGui::PopStyleColor();
		{
			ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 5);

#define MENU_MODULES(name, tab) ImGui::PushStyleColor(ImGuiCol_Button, m_MenuTab == (tab) ? active : inactive); \
		     ImGui::Button(name, ImVec2(90 - 10, 22)); \
		     if (ImGui::IsItemClicked()) m_MenuTab = tab; \
		     ImGui::PopStyleColor()

			MENU_MODULES("Features", 0);
			MENU_MODULES("Misc", 1);
			MENU_MODULES("Hotkeys", 2);
			MENU_MODULES("About", 3);

#undef MENU_MODULES
		}
		ImGui::EndChild();

		GuiUtil::LineVertical();

		ImGui::PushStyleColor(ImGuiCol_ChildBg, IM_COL32(0, 0, 0, 0));
		ImGui::BeginChild("##RightSide", ImVec2(GuiUtil::GetX(), GuiUtil::GetY()), TRUE);
		ImGui::PopStyleColor();
		ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImGuiCol_Button ? active : inactive);
		switch (m_MenuTab)
		{
		case 0: // Features
			ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(2, 2));
			ImGui::BeginGroup();

			//ImGui::CheckboxFill("Animation Speed", &vars.PlayerSpeed.value());
			//if (vars.PlayerSpeed.value())
			//	ImGui::SliderFloat("Speed", &vars.PlayerSpeedValue.value(), 1.0f, 20.0f, "%.1f");

			ImGui::CheckboxFill("Instant Regen", &vars.InstantRegen.value()); HELPMAKER("Press Run");

			ImGui::CheckboxFill("God Mode", &vars.GodMode.value());

			ImGui::CheckboxFill("Damage Hack", &vars.DamageHack.value());
			if (vars.DamageHack.value())
				ImGui::SliderInt("Value", &vars.DamageHackValue.value(), 10000, 100000000, "%d");

			ImGui::EndGroup();
			ImGui::PopStyleVar();
			break;
		case 1: // Misc
			ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(2, 2));
			ImGui::BeginGroup();

			ImGui::CheckboxFill("FPS Unlock", &vars.FPSUnlock.value());
			if (vars.FPSUnlock.value())
				ImGui::SliderInt("FPS", &vars.FPSValue.value(), 5, 360, "%d");
			
			ImGui::CheckboxFill("Fov Changer", &vars.FovChanger.value());
			if (vars.FovChanger.value())
				ImGui::SliderFloat("Fov", &vars.Fov.value(), 1.0f, 360.0f, "%.1f");

			ImGui::CheckboxFill("Skip Intro Movie", &vars.SkipIntroMovie.value()); HELPMAKER("This will skip the intro movie when you start the game");

			ImGui::CheckboxFill("Disable Web View", &vars.DisableWebView.value()); HELPMAKER("Disables WebView pop-up every time you enter the game");

			ImGui::EndGroup();
			ImGui::PopStyleVar();
			break;
		case 2: // Hotkeys
			//ImGui::InputHotkey("PlayerSpeed", vars.PlayerSpeed);

			break;
		case 3: // About
			ImGui::Spacing();
			ImGui::Text("tess runs ts");
			ImGui::TextURL("saint", "https://silv.ws");
			break;
		}

		ImGui::PopStyleColor();
		ImGui::EndChild();
    }

    ImGui::End();
}