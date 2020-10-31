#ifndef PLAYER
#define PLAYER

#include "levels.h"
#include <raylib.h>

typedef struct Player {
    Rectangle rec;
    Vector2 last_pos;
    Color color;
    // TODO: player states

}Player;

//TODO: mover funciones y structs a .h y .c files


void player_collision(Player* player, LevelData* level_data);
void move_player(Player* player);

#endif