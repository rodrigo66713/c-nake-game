#include <stdio.h>
#include <conio.h>

#include "playable-area.h"

#define WALL_SIZE_LENGTH 31
#define WALL_SIZE_WIDTH 16

/*
This function set the playable area where C-Nake will move, such as ground and walls.
*/
void setPlayableArea() {
    char playable_area[WALL_SIZE_LENGTH][WALL_SIZE_WIDTH];
    
    for (int width = 0; width < WALL_SIZE_WIDTH; width++) {
        for (int length = 0; length < WALL_SIZE_LENGTH; length++) {
            if ((length == 0 || length == WALL_SIZE_LENGTH - 1) || (width == 0 || width == WALL_SIZE_WIDTH - 1)) {
                playable_area[length][width] = '#';
            } else {
                playable_area[length][width] = ' ';
            }
        }
    }

    drawPlayableArea(playable_area); 
}

/*
This function draws the playable area and the frames of the game. 
*/
void drawPlayableArea(char playable_area[WALL_SIZE_LENGTH][WALL_SIZE_WIDTH]) {
    for (int width = 0; width < WALL_SIZE_WIDTH; width++) {
        for (int length = 0; length < WALL_SIZE_LENGTH; length++) {
            printf("%c", playable_area[length][width]);
        }
        printf("\n");
    }
}
