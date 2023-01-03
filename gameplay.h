//
// Created by Paul Weber on 11.12.22.
//

#ifndef TETRIS_GAMEPLAY_H
#define TETRIS_GAMEPLAY_H

#include "include/raylib.h"

#include <stdlib.h>

void move_tetromino(Vector2* Tetromino, double x_dif, double y_dif, int scale, int x_offset, int y_offset);
void generate_tetromino(Vector2* Tetromino, int scale, int x_offset, int y_offset);

// + Behelfsfunktion swap()
void swap(int* l_operand, int* r_operand);
void rotation(Vector2 * Tetromino);



#endif //TETRIS_GAMEPLAY_H
