#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include <raylib.h>

typedef struct Player {
    Vector2 pos;
    Vector2 size;

}Player;

typedef Rectangle Block;

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second


    Player player = {
        {0, 0},
        {50, 50},
    };
    Block block = { 0, 0, 50, 50 };

    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------

        // Movement
        if (IsKeyPressed(KEY_RIGHT)) player.pos.x += player.size.x;
        if (IsKeyPressed(KEY_LEFT)) player.pos.x  -= player.size.x;
        if (IsKeyPressed(KEY_UP)) player.pos.y    -= player.size.y;
        if (IsKeyPressed(KEY_DOWN)) player.pos.y  += player.size.y;

        // Mouse position
        char mouse_pos_str[20];
        Vector2 mouse_pos = GetMousePosition();
        sprintf(mouse_pos_str, "X: %d, Y: %d", (int)mouse_pos.x, (int)mouse_pos.y);

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            block.x = trunc(mouse_pos.x / 50) * 50;
            block.y = trunc(mouse_pos.y / 50) * 50;
        }
        printf("Cuadrante: X: %f  Y: %f\n", trunc(mouse_pos.x / 50), trunc(mouse_pos.y / 50));
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawRectangleV(player.pos, player.size, RED);
            DrawRectangleRec(block, BLUE);
            DrawText(mouse_pos_str, screenWidth - 160, screenHeight - 40, 20, BLACK);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

	return 0;
}