#include "raylib.h"
#include <stdint.h>

static const uint32_t screenWidth = 800;
static const uint32_t screenHeight = 500;
static const uint32_t targetFPS = 60;

int main(int argc, char *argv[])
{
    InitWindow(screenWidth, screenHeight, "Polymap");
    SetTargetFPS(targetFPS);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        BeginMode2D();
    }

    return 0;
}
