//
// Created by Paul Weber on 11.12.22.
//

#ifndef TETRIS_GAMEPLAY_H
#define TETRIS_GAMEPLAY_H

#include <raylib.h>

#include <stdlib.h>

void move_tetromino(Vector2* Tetromino, double x_dif, double y_dif, int *playfield);
void generate_tetromino(Vector2* Tetromino);
bool drop_pice_1(Vector2 *current_Tetromino, int *playfield);
int clear_line(Vector2 *current_Tetromino, int *playfield);


#endif //TETRIS_GAMEPLAY_H
