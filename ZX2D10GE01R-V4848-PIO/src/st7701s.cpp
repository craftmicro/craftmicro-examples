#include "st7701s.hpp"

ST7701S::ST7701S() {
    bus = new Arduino_SWSPI(
        GFX_NOT_DEFINED /* DC */, 21 /* CS */,
        47 /* SCK */, 41 /* MOSI */, GFX_NOT_DEFINED /* MISO */);
    panel = new Arduino_ESP32RGBPanel(
        39 /* DE */, 48 /* VSYNC */, 40 /* HSYNC */, 45 /* PCLK */,
        10 /* R0 */, 16 /* R1 */, 9 /* R2 */, 15 /* R3 */, 46 /* R4 */,
        8 /* G0 */, 13 /* G1 */, 18 /* G2 */, 12 /* G3 */, 11 /* G4 */, 17 /* G5 */,
        47 /* B0 */, 41 /* B1 */, 0 /* B2 */, 42 /* B3 */, 14 /* B4 */,
        1 /* hsync_polarity */, 10 /* hsync_front_porch */, 10 /* hsync_pulse_width */, 10 /* hsync_back_porch */,
        1 /* vsync_polarity */, 14 /* vsync_front_porch */, 2 /* vsync_pulse_width */, 12 /* vsync_back_porch */);
    gfx = new Arduino_RGB_Display(
        480 /* width */, 480 /* height */, panel, 0 /* rotation */, true /* auto_flush */,
        bus, GFX_NOT_DEFINED /* RST */, st7701_type7_init_operations, sizeof(st7701_type7_init_operations));

    gfx->begin();
    gfx->fillScreen(BLACK);

    pinMode(38, OUTPUT);
    digitalWrite(38, HIGH);

    lineBufferHeight = 1;
    pixelScale = 4;
    pixelFormat = PixelFormat::RGB565;
    width = gfx->width();
    height = gfx->height();
}

void ST7701S::drawPixel565(color565 color) {
    gfx->writePixelPreclipped(_x, _y, color);
}

