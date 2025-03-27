#include <stdint.h>
#include <stdlib.h>

#include "raylib.h"

static const uint32_t SCREEN_WIDTH = 1920;
static const uint32_t SCREEN_HEIGHT = 1080;
static const uint32_t TARGET_FPS = 60;

static const uint32_t TILE_BAR_WIDTH = SCREEN_WIDTH * 0.8;
static const uint32_t TILE_BAR_HEIGHT = SCREEN_HEIGHT * 0.2;

static const uint32_t MAP_WIDTH = 10;
static const uint32_t MAP_HEIGHT = 10;
static const uint32_t TILE_WIDTH = SCREEN_WIDTH / MAP_WIDTH;
static const uint32_t TILE_HEIGHT = SCREEN_HEIGHT / MAP_HEIGHT;

static const uint32_t TILE_COUNT = MAP_WIDTH * MAP_HEIGHT;

static inline int GetTileIndex(const int x, const int y);

int main(int argc, char* argv[])
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Polymap");
    SetTargetFPS(TARGET_FPS);
    Color* tileColors = (Color*)calloc(TILE_COUNT, sizeof(Color));

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        // Handle input
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            Vector2 mousePosition = GetMousePosition();
            int mouseTileX = (int)(mousePosition.x / TILE_WIDTH);
            int mouseTileY = (int)(mousePosition.y / TILE_HEIGHT);
            int index = GetTileIndex(mouseTileX, mouseTileY);
            if (index < TILE_COUNT) tileColors[index] = RAYWHITE;
        }

        // Draw tiles
        for (int row = 0; row < MAP_HEIGHT; row++)
        {
            for (int column = 0; column < MAP_WIDTH; column++)
            {
                int tileIndex = GetTileIndex(column, row);
                if (tileIndex > TILE_COUNT) continue;
                DrawRectangle(column * TILE_WIDTH,
                              row * TILE_HEIGHT,
                              TILE_WIDTH,
                              TILE_HEIGHT,
                              tileColors[tileIndex]);
            }
        }

        // Draw tile bar
        DrawRectangle(SCREEN_WIDTH / 2 - TILE_BAR_WIDTH / 2,
                      SCREEN_HEIGHT - TILE_BAR_HEIGHT / 2,
                      TILE_BAR_WIDTH,
                      TILE_BAR_HEIGHT,
                      DARKGRAY);

        EndDrawing();
    }

    free(tileColors);

    CloseWindow();

    return 0;
}

static inline int GetTileIndex(const int x, const int y)
{
    return x + (y * MAP_WIDTH);
}
