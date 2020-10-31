#include "player.h"
#include "levels.h"
#include <raylib.h>
#include <stdio.h>


void move_player(Player* player) {

    player->last_pos.x = player->rec.x;
    player->last_pos.y = player->rec.y;

    if (IsKeyPressed(KEY_RIGHT)) player->rec.x += player->rec.width;
    if (IsKeyPressed(KEY_LEFT)) player->rec.x  -= player->rec.width;
    if (IsKeyPressed(KEY_UP)) player->rec.y    -= player->rec.height;
    if (IsKeyPressed(KEY_DOWN)) player->rec.y  += player->rec.height;

}

void player_collision(Player* player, LevelData* level_data) {

    for (int i = 0; i < level_data->blocks_number; i++) {

        if (CheckCollisionRecs(player->rec, level_data->blocks[i].rec)) {

            if (level_data->blocks[i].type == wall) {
                player->rec.x = player->last_pos.x;
                player->rec.y = player->last_pos.y;
                return;
            }

            if (level_data->blocks[i].type == enemy) {

                //reset_level(level_data);
                printf("algo\n");
                return;
            }

            if (level_data->blocks[i].type == movable) {
                printf("move X: %d move Y: %d\n", (int)player->last_pos.x - (int)player->rec.x,  (int)player->last_pos.y - (int)player->rec.y);
                level_data->blocks[i].rec.x += player->rec.x - player->last_pos.x;
                level_data->blocks[i].rec.y += player->rec.y - player->last_pos.y;
                return;
            }
        }
    }


}