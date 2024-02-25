#include <CraftMicro.h>
#include "tft_espi_display.h"
#include "ninja.h"

using namespace craft;

App* app;
PlySprite* ninjaSprite;

void setup() {
    Serial.begin(9600);

    // Create a new application
    app = new App(new TFTDisplay(3, 1, 4));

    // Set background color
    app->stage->backgroundColor(Color8888::SaddleBrown);

    // Add animated ply sprite to center of the stage
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
