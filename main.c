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

    Vector2 *current_Tetromino = (Vector2*) malloc (4* sizeof(Vector2));
    Vector2 *next_Tetromino = (Vector2*) malloc (4* sizeof(Vector2));


    generate_tetromino(next_Tetromino, scale, x_offset, y_offset);
    generate_tetromino(current_Tetromino, scale, x_offset, y_offset);

    // Main game loop
    while (!WindowShouldClose())
    {
        player_1(current_Tetromino, scale, x_offset, y_offset);


        BeginDrawing();
        //Hintergrund
        ClearBackground(DARKGRAY);
        draw_output(current_Tetromino, scale, x_offset, y_offset);
        show_next_tetromino(next_Tetromino, scale, x_offset, y_offset);
        EndDrawing();
    }



    CloseWindow();

    return 0;
}






