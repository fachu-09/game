#include "levels.h"
#include <raylib.h>
#include <stdio.h>

LevelData* load_level(const char *fileName) {

    // crear un nivel en codigo. Se implementaramente proximamente
    // a partir de archivos
    LevelData* level_data = (LevelData *) RL_MALLOC(sizeof(LevelData));
    level_data->blocks_number = 4;

    level_data->blocks = (Block *) RL_MALLOC(level_data->blocks_number * sizeof(Block));

    level_data->init_pos.x = 0;
    level_data->init_pos.y = 0;

    for (int i = 0; i < level_data->blocks_number; i++) {

        level_data->blocks[i].rec.height = 50;
        level_data->blocks[i].rec.width  = 50;
        level_data->blocks[i].rec.y      = 0;
        level_data->blocks[i].rec.x      = i * 100;
        level_data->blocks[i].color = BLACK;

        switch (i) {
        case 0:level_data->blocks[i].type = wall; break;
        case 1:level_data->blocks[i].type = enemy; break;
        case 2:level_data->blocks[i].type = movable; break;
        case 3:level_data->blocks[i].type = wall; break;
        }
        
    }

    return level_data;
}
void exit_level(LevelData* level_data) {

    /* saca de RAM todos los componentes y variables del nivel actual */
    RL_FREE(level_data->blocks);
    RL_FREE(level_data);

}
void draw_level(LevelData* level_data) {

    for (int i = 0; i < level_data->blocks_number; i++) {

        DrawRectangleRec(level_data->blocks[i].rec, level_data->blocks[i].color);
    }

}