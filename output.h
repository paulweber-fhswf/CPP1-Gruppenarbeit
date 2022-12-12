//
// Created by Paul Weber on 11.12.22.
//

#ifndef TETRIS_OUTPUT_H
#define TETRIS_OUTPUT_H

#include <raylib.h>

void draw_output(Vector2* Tetromino, int scale, int x_offset, int y_offset);
void show_next_tetromino(Vector2* Tetromino, int scale, int x_offset, int y_offset);

#endif //TETRIS_OUTPUT_H
