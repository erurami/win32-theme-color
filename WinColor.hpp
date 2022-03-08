
#pragma once

#include <windows.h>

COLORREF GetAccentColor(void);
COLORREF GetAccentDark1Color(void);
COLORREF GetAccentDark2Color(void);
COLORREF GetAccentDark3Color(void);
COLORREF GetAccentLight1Color(void);
COLORREF GetAccentLight2Color(void);
COLORREF GetAccentLight3Color(void);
COLORREF GetBackgroundColor(void);
COLORREF GetForegroundColor(void);

// "A" : Accent
// "B" : Background
// "F" : Foreground
// "A1B2F3" means Accent 1 Background 2 and Foreground 3

// mustn't include more than two digit number use same color twice
// don't have to be in order. (Can be "B3F1A5")
// don't have to be in capital letter. (Can be "b1A3F4")

// when any error occured, returns RGB(255, 0, 0)
COLORREF GetBlendedTheme(char* strBlendCode);

#include "WinColor.ipp"

