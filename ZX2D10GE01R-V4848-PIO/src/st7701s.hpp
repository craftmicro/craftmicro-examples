#pragma once

#include <CraftMicro.h>
#include <Arduino_GFX_Library.h>

using namespace craft;

class ST7701S: public Display {
public:
    ST7701S(int bufferHeight = 1, int pixelScale = 1);

    void drawPixel565(color565 color);
protected:
    Arduino_DataBus *bus;
    Arduino_ESP32RGBPanel *panel;
    Arduino_RGB_Display *gfx;
};
