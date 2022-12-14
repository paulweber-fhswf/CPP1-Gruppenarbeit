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

void draw_output(tetromino *current_Tetromino
){
    //Aktuelen Teromino ausgeben
    for (int i = 0; i < 4; ++i) {
        DrawRectangle((current_Tetromino->Tetromino+i)->x * scale  + x_offset  ,(current_Tetromino->Tetromino+i)->y * scale + y_offset, scale, scale,
                      get_color(current_Tetromino->type));
    }
}

//Funktion um den nächsten Tetromino anzuzeigen
//Autor: Paul Weber
void show_next_tetromino(tetromino *current_Tetromino
){
    DrawText("Next Piece:", 10, 10, 20, BLUE);

    for (int i = 0; i < 4; ++i) {
        DrawRectangle((current_Tetromino->Tetromino+i)->x * scale, (current_Tetromino->Tetromino+i)->y * scale + 100, scale, scale, get_color(current_Tetromino->type));
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
            if(*(playfield + x + y * 10) >= 0)
            DrawRectangle(x * scale +x_offset , (y-20) * scale +y_offset , scale, scale, get_color(*(playfield + x + y * 10)));
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

//Bestimmen der Farbe
//Rückgabe: Farbe es types Color
//Autor: Paul Weber
Color get_color (int type //Typennummer des Blockes
){

    Color return_color;

    switch (type) {
        case 0:
            return_color = BLUE;
            break;

        case 1:
            return_color = DARKBLUE;
            break;

        case 2:
            return_color = ORANGE;
            break;

        case 3:
            return_color = YELLOW;
            break;

        case 4:
            return_color = GREEN;
            break;

        case 5:
            return_color = PURPLE;
            break;

        case 6:
            return_color = RED;
            break;
    }

    return return_color;
}