//
// Created by Paul Weber on 11.12.22.
//

#include "input.h"
#include "gameplay.h"

void player_1(Vector2* Tetromino, int *playfield){
    int x_dif = 0;
    int y_dif = 0;

    // Update
    //----------------------------------------------------------------------------------
    if (IsKeyDown(KEY_RIGHT)){
        x_dif = 1;
    }

    if (IsKeyDown(KEY_LEFT)){
        x_dif = -1;
    }

    if (IsKeyDown(KEY_UP)){
        y_dif = -1;
    }

    if (IsKeyDown(KEY_DOWN)){
        y_dif = 1;
    }

    move_tetromino(Tetromino, x_dif, y_dif, playfield);
}