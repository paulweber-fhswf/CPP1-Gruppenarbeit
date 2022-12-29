//
// Created by Paul Weber on 27.11.22.
//

#include <raylib.h>
#include <stdlib.h>
#include "output.h"
#include "input.h"
#include "gameplay.h"
#include <time.h>

int main()
{
    srand(time(NULL));

    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Tetris");
    SetTargetFPS(60);

    Vector2 *current_Tetromino = (Vector2*) malloc (4* sizeof(Vector2));
    Vector2 *next_Tetromino = (Vector2*) malloc (4* sizeof(Vector2));


    generate_tetromino(current_Tetromino);

    generate_tetromino(current_Tetromino);
    generate_tetromino(next_Tetromino);

    // Main game loop
    while (!WindowShouldClose())
    {
        bool check = false;

        player_1(current_Tetromino);
        check = drop_pice_1(current_Tetromino);


        BeginDrawing();

        //Hintergrund
        ClearBackground(DARKGRAY);
        draw_output(current_Tetromino);
        show_next_tetromino(next_Tetromino);

        if(check == true){
            DrawText("Colision", 10, 50, 20, PURPLE);

            for (int i = 0; i < 4; ++i) {
                (current_Tetromino+i)->y = (next_Tetromino+i)->y;
                (current_Tetromino+i)->x = (next_Tetromino+i)->x;
            }


            generate_tetromino(next_Tetromino);




        }


        EndDrawing();
    }



    CloseWindow();

    return 0;
}






