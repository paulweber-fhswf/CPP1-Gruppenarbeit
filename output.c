//
// Created by Paul Weber on 11.12.22.
//

#include "output.h"

#define x_offset 300
#define y_offset 10
#define scale 20


void draw_output(Vector2* Tetromino){
    //Spielfeld
    DrawLine(x_offset, y_offset, x_offset, 20*scale+y_offset, RED);
    DrawLine(x_offset, 20*scale+y_offset, 10*scale+x_offset, 20*scale+y_offset, RED);
    DrawLine(10*scale+x_offset, 20*scale+y_offset, 10*scale+x_offset, y_offset, RED);

    //Tetromino
    for (int i = 0; i < 4; ++i) {
        DrawRectangle( (Tetromino+i)->x * scale  + x_offset  , (Tetromino+i)->y * scale + y_offset, scale, scale,  RED);
    }

}

void show_next_tetromino(Vector2* Tetromino){

    DrawText("Next Piece", 10, 10, 20, BLUE);

    for (int i = 0; i < 4; ++i) {
        DrawRectangle((Tetromino+i)->x * scale , (Tetromino+i)->y * scale + 100, scale, scale, BLUE);
    }
}

void draw_playfield(int *playfield){
    for (int x = 0; x < 10; ++x) {
        for (int y = 0; y < 40; ++y) {
            if(*(playfield+x+y*10) == 1){
                DrawRectangle(x * scale +x_offset , (y-20) * scale +y_offset , scale, scale, PURPLE);
            }
            if(*(playfield+x+y*10) == 2){
                DrawRectangle(x * scale +x_offset , (y-20) * scale +y_offset , scale, scale, GREEN);
            }
        }
    }
}