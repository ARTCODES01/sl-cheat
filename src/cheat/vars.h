#pragma once

#include "ConfigEntry.hpp"
#include "Hotkey.h"

class Vars final : public Singleton<Vars>
{
public:
	Vars() = default;

	// Features
	CONFIG_ENTRY_HOTKEY(bool, HideRevealMenu, true, Hotkey());

	// Misc
	CONFIG_ENTRY_HOTKEY(bool, FPSUnlock, true, Hotkey());
	CONFIG_ENTRY(int, FPSValue, 240);
	CONFIG_ENTRY_HOTKEY(bool, FovChanger, false, Hotkey());
	CONFIG_ENTRY(float, Fov, 60.0f);
	CONFIG_ENTRY_HOTKEY(bool, SkipIntroMovie, true, Hotkey());
	CONFIG_ENTRY_HOTKEY(bool, DisableWebView, true, Hotkey());
};
