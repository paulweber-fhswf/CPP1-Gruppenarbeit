//
// Created by Paul Weber on 27.11.22.
//

#include <raylib.h>
#include <stdlib.h>
#include "output.h"
#include "input.h"
#include "gameplay.h"
#include <time.h>


#define x_offset 300
#define y_offset 10
#define scale 20


int main()
{
    srand(time(NULL));

    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Tetris");
    SetTargetFPS(60);

    Vector2 *Tetromino = (Vector2*) malloc (4* sizeof(Vector2));


    generate_tetromino(Tetromino, scale, x_offset, y_offset);

    // Main game loop
    while (!WindowShouldClose())
    {
        player_1(Tetromino, scale, x_offset, y_offset);
        draw_output(Tetromino, scale, x_offset, y_offset);
    }


    CloseWindow();

    return 0;
}






