
#pragma once

#pragma comment(lib, "windowsapp")

#include "WinColor.hpp"

#include <windows.h>
#include "winrt/Windows.UI.ViewManagement.h"


COLORREF GetAccentColor(void)
{
    winrt::Windows::UI::ViewManagement::UISettings uiSettings;

    winrt::Windows::UI::Color color(uiSettings.GetColorValue(winrt::Windows::UI::ViewManagement::UIColorType::Accent));

    return RGB(color.R, color.G, color.B);
}

COLORREF GetBackgroundColor(void)
{
    winrt::Windows::UI::ViewManagement::UISettings uiSettings;

    winrt::Windows::UI::Color color(uiSettings.GetColorValue(winrt::Windows::UI::ViewManagement::UIColorType::Background));

    return RGB(color.R, color.G, color.B);
}


