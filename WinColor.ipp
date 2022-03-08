
#pragma once

#pragma comment(lib, "windowsapp")

#include "WinColor.hpp"

#include <windows.h>
#include "winrt/Windows.UI.ViewManagement.h"

#include <string.h>


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


COLORREF GetBlendedTheme(char* strBlendCode)
{
    if (strBlendCode == NULL)
    {
        return RGB(255, 0, 0);
    }

    int r = 0;
    int g = 0;
    int b = 0;

    int blend_ratio_sum = 0;

    int code_length = (int)strlen(strBlendCode);
    for (int i = 0; i < code_length; i += 2)
    {
        if (strBlendCode[i + 1] <= 48 || strBlendCode[i + 1] >= 58)
        {
            return RGB(255, 0, 0);
        }

        int blend_amount = strBlendCode[i + 1] - 48;
        blend_ratio_sum += blend_amount;

        COLORREF color_to_blend;
        switch (strBlendCode[i])
        {
            case 'A':
            case 'a':
                color_to_blend = GetAccentColor();
                break;

            case 'B':
            case 'b':
                color_to_blend = GetBackgroundColor();
                break;

            case 'F':
            case 'f':
                color_to_blend = GetForegroundColor();
                break;

            default:
                return RGB(255, 0, 0);
        }

        r += GetRValue(color_to_blend) * blend_amount;
        g += GetGValue(color_to_blend) * blend_amount;
        b += GetBValue(color_to_blend) * blend_amount;
    }

    r /= blend_ratio_sum;
    g /= blend_ratio_sum;
    b /= blend_ratio_sum;

    return RGB(r, g, b);
}

