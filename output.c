//
// Created by Paul Weber on 11.12.22.
//

#include "output.h"


void draw_output(Vector2* Tetromino, int scale, int x_offset, int y_offset){
    BeginDrawing();

    //Hintergrund
    ClearBackground(DARKGRAY);

    //Spielfeld
    DrawLine(x_offset, y_offset, x_offset, 20*scale+y_offset, RED);
    DrawLine(x_offset, 20*scale+y_offset, 10*scale+x_offset, 20*scale+y_offset, RED);
    DrawLine(10*scale+x_offset, 20*scale+y_offset, 10*scale+x_offset, y_offset, RED);

    //Tetromino
    for (int i = 0; i < 4; ++i) {
        DrawRectangle((Tetromino+i)->x, (Tetromino+i)->y, scale, scale, RED);
    }

    EndDrawing();
}