
#pragma once

#pragma comment(lib, "windowsapp")

#include "WinColor.hpp"

#include <windows.h>
#include "winrt/Windows.UI.ViewManagement.h"


#define GET_COLOR_VALUE_FUNCTION(funcName, ColorType) \
COLORREF funcName(void)\
{\
    winrt::Windows::UI::ViewManagement::UISettings uiSettings;\
    winrt::Windows::UI::Color color(uiSettings.GetColorValue(winrt::Windows::UI::ViewManagement::UIColorType::ColorType));\
    return RGB(color.R, color.G, color.B);\
}


GET_COLOR_VALUE_FUNCTION(GetAccentColor      , Accent)
GET_COLOR_VALUE_FUNCTION(GetAccentDark1Color , AccentDark1)
GET_COLOR_VALUE_FUNCTION(GetAccentDark2Color , AccentDark2)
GET_COLOR_VALUE_FUNCTION(GetAccentDark3Color , AccentDark3)
GET_COLOR_VALUE_FUNCTION(GetAccentLight1Color, AccentLight1)
GET_COLOR_VALUE_FUNCTION(GetAccentLight2Color, AccentLight2)
GET_COLOR_VALUE_FUNCTION(GetAccentLight3Color, AccentLight3)
GET_COLOR_VALUE_FUNCTION(GetBackgroundColor  , Background)
GET_COLOR_VALUE_FUNCTION(GetForegroundColor  , Foreground)

