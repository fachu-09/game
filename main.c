#include <raylib.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "game.h"
#include "levels.h"
#include "player.h"

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth  = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);


    LevelData *level = load_level("a");

    Player player = {
        {level->init_pos.x, level->init_pos.y, 50, 50},
        level->init_pos,
        RED
    };

    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------

        // Movement
        move_player(&player);
        player_collision(&player, level);

        // Mouse position
        char mouse_pos_str[20];
        Vector2 mouse_pos = GetMousePosition();
        sprintf(mouse_pos_str, "X: %d, Y: %d", (int)mouse_pos.x, (int)mouse_pos.y);

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            draw_level(level);

            DrawRectangleRec(player.rec, player.color);
            DrawText(mouse_pos_str, screenWidth - 160, screenHeight - 40, 20, BLACK);
            DrawFPS(0, 0);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    exit_level(level);
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

	return 0;
}