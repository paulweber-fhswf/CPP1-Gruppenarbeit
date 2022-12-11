//
// Created by Paul Weber on 27.11.22.
//

#include <raylib.h>
#include <stdlib.h>

#define x_offset 300
#define y_offset 10
#define scale 20

void move_tetromino(Vector2* Tetromino, double x_dif, double y_dif);
void player_1(Vector2* Tetromino);
void draw_output(Vector2* Tetromino);


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
        player_1(Tetromino);
        draw_output(Tetromino);
    }


    CloseWindow();

    return 0;
}


void move_tetromino(Vector2* Tetromino, double x_dif, double y_dif){
    int check = 0;

    //Überprüfe, ob der Tetromino an die neue Stelle passt, wenn nicht, wird check auf 1 gesetzt und der Schritt der Koordinatenanpassung wird übersprungen
    for (int i = 0; i < 4; ++i) {
        if((Tetromino+i)->x + x_dif >= 10*scale+x_offset || (Tetromino+i)->x + x_dif < x_offset){
            check = 1;
        }
        if((Tetromino+i)->y +y_dif >= 20*scale+y_offset || (Tetromino+i)->y +y_dif < y_offset){
            check = 1;
        }
    }

    if(check == 0){
        //Tetromino wieder in das Move Feld packen
        for (int i = 0; i < 4; ++i) {
            (Tetromino+i)->x = (Tetromino+i)->x + x_dif;
            (Tetromino+i)->y = (Tetromino+i)->y + y_dif;
        }
    }

    WaitTime(0.05);
}

void player_1(Vector2* Tetromino){
    int x_dif = 0;
    int y_dif = 0;

    // Update
    //----------------------------------------------------------------------------------
    if (IsKeyDown(KEY_RIGHT)){
        x_dif = 1*scale;
    }

    if (IsKeyDown(KEY_LEFT)){
        x_dif = -1*scale;
    }

    if (IsKeyDown(KEY_UP)){
        y_dif = -1*scale;
    }

    if (IsKeyDown(KEY_DOWN)){
        y_dif = 1*scale;
    }

    move_tetromino(Tetromino, x_dif, y_dif);
}

void draw_output(Vector2* Tetromino){
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