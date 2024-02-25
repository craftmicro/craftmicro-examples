#pragma once

#include <CraftMicro.h>
#include <TFT_eSPI.h>

using namespace craft;

class TFTDisplay : public Display {
public:
    TFT_eSPI tft = TFT_eSPI();

    TFTDisplay(int rotation = 0, int lineBufferHeight = 1, int pixelScale = 1 ) {
        tft.init();
        tft.setRotation(rotation);
        tft.fillScreen(TFT_BLACK);

        // TODO: lineBufferHeight > 1 is weird
        this->lineBufferHeight = lineBufferHeight;
        this->pixelScale = pixelScale;
        pixelFormat = PixelFormat::RGB565;
        width = tft.width();
        height = tft.height();
    }
    void beginDrawing(ClipRect& rect) {
        tft.startWrite();
        tft.setAddrWindow(rect.x, rect.y, rect.width, rect.height);
    }
    inline void drawPixel565(color565 color) {
        tft.pushBlock(color, 1);
    }
    void endDrawing() {
        tft.endWrite();
    }
};
