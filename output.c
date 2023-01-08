//
// Created by Paul Weber on 11.12.22.
//

#include "output.h"

//Verschiebung und größe für die Blöcke und das Spielfeld
#define x_offset 300
#define y_offset 10
#define scale 20

//Funktion um den aktuellen Tetromino auszugeben
//Autor: Paul Weber

void draw_output(Vector2* Tetromino, //Vector Array mit den 4 Blöcken des Tetrominos
                 Vector2 *Rotation_Point, //Rotationspunkt des Tetrominos
                 int *type //Typ des Tetrominos
){
    //Aktuelen Teromino ausgeben
    for (int i = 0; i < 4; ++i) {
        switch (*type) {
            case 0:
                DrawRectangle((Tetromino+i)->x * scale  + x_offset  , (Tetromino+i)->y * scale + y_offset, scale, scale, BLUE);
                break;

            case 1:
                DrawRectangle((Tetromino+i)->x * scale  + x_offset  , (Tetromino+i)->y * scale + y_offset, scale, scale, DARKBLUE);
                break;

            case 2:
                DrawRectangle((Tetromino+i)->x * scale  + x_offset  , (Tetromino+i)->y * scale + y_offset, scale, scale, ORANGE);
                break;

            case 3:
                DrawRectangle((Tetromino+i)->x * scale  + x_offset  , (Tetromino+i)->y * scale + y_offset, scale, scale, YELLOW);
                break;

            case 4:
                DrawRectangle((Tetromino+i)->x * scale  + x_offset  , (Tetromino+i)->y * scale + y_offset, scale, scale, GREEN);
                break;

            case 5:
                DrawRectangle((Tetromino+i)->x * scale  + x_offset  , (Tetromino+i)->y * scale + y_offset, scale, scale, PURPLE);
                break;

            case 6:
                DrawRectangle((Tetromino+i)->x * scale  + x_offset  , (Tetromino+i)->y * scale + y_offset, scale, scale, RED);
                break;
        }
    }

    DrawText(TextFormat("x: %f, y: %f", Rotation_Point->x, Rotation_Point->y), 540, 310, 20, WHITE);

    DrawCircle((Rotation_Point->x+0.5)* scale   + x_offset  , (Rotation_Point->y+0.5) * scale + y_offset, 5,  WHITE);
}

//Funktion um den nächsten Tetromino anzuzeigen
//Autor: Paul Weber
void show_next_tetromino(Vector2* Tetromino, //Vector Array mit den 4 Blöcken des Tetrominos
                         int *type //Typ des Tetrominos
){
    DrawText("Next Piece:", 10, 10, 20, BLUE);

    for (int i = 0; i < 4; ++i) {
        switch (*type) {
            case 0:
                DrawRectangle((Tetromino+i)->x * scale , (Tetromino+i)->y * scale + 100, scale, scale, BLUE);
                break;

            case 1:
                DrawRectangle((Tetromino+i)->x * scale , (Tetromino+i)->y * scale + 100, scale, scale, DARKBLUE);
                break;

            case 2:
                DrawRectangle((Tetromino+i)->x * scale , (Tetromino+i)->y * scale + 100, scale, scale, ORANGE);
                break;

            case 3:
                DrawRectangle((Tetromino+i)->x * scale , (Tetromino+i)->y * scale + 100, scale, scale, YELLOW);
                break;

            case 4:
                DrawRectangle((Tetromino+i)->x * scale , (Tetromino+i)->y * scale + 100, scale, scale, GREEN);
                break;

            case 5:
                DrawRectangle((Tetromino+i)->x * scale , (Tetromino+i)->y * scale + 100, scale, scale, PURPLE);
                break;

            case 6:
                DrawRectangle((Tetromino+i)->x * scale , (Tetromino+i)->y * scale + 100, scale, scale, RED);
                break;
        }

    }
}

//Funktion um alle liegenden Blöcke auszugeben
//Autor: Paul Weber
void draw_playfield(int *playfield // Array mit den liegenden Blöcken
){
    //Spielfeld zeichnen
    DrawLine(x_offset, y_offset, x_offset, 20*scale+y_offset, RED);
    DrawLine(x_offset, 20*scale+y_offset, 10*scale+x_offset, 20*scale+y_offset, RED);
    DrawLine(10*scale+x_offset, 20*scale+y_offset, 10*scale+x_offset, y_offset, RED);

    //Alle Koordinaten des Arrays durchgehen
    for (int x = 0; x < 10; ++x) {
        for (int y = 0; y < 40; ++y) {
            switch (*(playfield+x+y*10)) {
                case 1:
                    DrawRectangle(x * scale +x_offset , (y-20) * scale +y_offset , scale, scale, BLUE);
                    break;

                case 2:
                    DrawRectangle(x * scale +x_offset , (y-20) * scale +y_offset , scale, scale, DARKBLUE);
                    break;

                case 3:
                    DrawRectangle(x * scale +x_offset , (y-20) * scale +y_offset , scale, scale, ORANGE);
                    break;

                case 4:
                    DrawRectangle(x * scale +x_offset , (y-20) * scale +y_offset , scale, scale, YELLOW);
                    break;

                case 5:
                    DrawRectangle(x * scale +x_offset , (y-20) * scale +y_offset , scale, scale, GREEN);
                    break;

                case 6:
                    DrawRectangle(x * scale +x_offset , (y-20) * scale +y_offset , scale, scale, PURPLE);
                    break;

                case 7:
                    DrawRectangle(x * scale +x_offset , (y-20) * scale +y_offset , scale, scale, RED);
                    break;
            }
        }
    }
}

//Funktion zum Darstellen eines GameOver Screens
//Autor: Florian Bruchhage
void draw_game_over(){
    BeginDrawing();
    DrawText("GAME OVER", 340, 10, 20, WHITE);
    EndDrawing();
    WaitTime(3.0);
}