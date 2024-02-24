/*
 * Simple example of craft micro working on ZX2D10GE01R-V4848
 * Uses PlatformIO with Arduino framework, and GFX Library fpr Arduino for driving the display
 */

#include <CraftMicro.h>
#include "st7701s.hpp"
#include "ninja.h"

using namespace craft;

App* app;
PlySprite* ninjaSprite;

void setup() {
    Serial.begin(9600);

    // Create a new application
    app = new App(new ST7701S());

    // Set background color
    app->stage->backgroundColor(Color8888::SaddleBrown);

    ninjaSprite = PlySprite::Create(&ninja, 0, true);
    app->stage->addChild(ninjaSprite);
    ninjaSprite->origin(OriginType::center, true);
    ninjaSprite->x(app->stage->width() / 2);
    ninjaSprite->y(app->stage->height() / 2);
    ninjaSprite->animation(S("Walk"));
}

void loop() {
    // Call update as often as possible
    app->update();
}