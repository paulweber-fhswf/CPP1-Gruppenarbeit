//
// Created by Paul Weber on 27.11.22.
//

#include <raylib.h>
#include <stdlib.h>
#include "output.h"
#include "input.h"

#define x_offset 300
#define y_offset 10
#define scale 20

void move_tetromino(Vector2* Tetromino, double x_dif, double y_dif);


int main()
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Tetris");
    SetTargetFPS(60);

    Vector2 *Tetromino = (Vector2*) malloc (4* sizeof(Vector2));


    //Zum Testen: Einen Block in der move Ebene erstellen
    (Tetromino+0)->x = 0*scale+x_offset;
    (Tetromino+0)->y = 0*scale+y_offset;

    (Tetromino+1)->x = 1*scale+x_offset;
    (Tetromino+1)->y = 0*scale+y_offset;

    (Tetromino+2)->x = 0*scale+x_offset;
    (Tetromino+2)->y = 1*scale+y_offset;

    (Tetromino+3)->x = 1*scale+x_offset;
    (Tetromino+3)->y = 1*scale+y_offset;

    // Main game loop
    while (!WindowShouldClose())
    {
        player_1(Tetromino, scale, x_offset, y_offset);
        draw_output(Tetromino, scale, x_offset, y_offset);
    }


    CloseWindow();

    return 0;
}






