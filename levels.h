#ifndef LEVELS
#define LEVELS

#include <raylib.h>
#include <string.h>

typedef enum BlockType {
    wall    = 0,
    enemy   = 1,
    movable = 2
}BlockType;

typedef struct Block {
    Rectangle rec;
    BlockType type ;
    Color color;

}Block;

typedef struct LevelData {
    Block *blocks;
    Vector2 init_pos;
    int blocks_number;
    char name[16];

}LevelData;

LevelData* load_level(const char *fileName);
void exit_level(LevelData* level_data);
void draw_level(LevelData* level_data);
void reset_level(LevelData* level_data);

#endif