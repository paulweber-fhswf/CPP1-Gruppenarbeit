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
void draw_output(Vector2* Tetromino //Vector Array mit den 4 Blöcken des Tetrominos
){
    //Aktuelen Teromino ausgeben
    for (int i = 0; i < 4; ++i) {
        DrawRectangle( (Tetromino+i)->x * scale  + x_offset  , (Tetromino+i)->y * scale + y_offset, scale, scale,  RED);
    }
}

//Funktion um den nächsten Tetromino anzuzeigen
//Autor: Paul Weber
void show_next_tetromino(Vector2* Tetromino //Vector Array mit den 4 Blöcken des Tetrominos
){
    DrawText("Next Piece", 10, 10, 20, BLUE);

    for (int i = 0; i < 4; ++i) {
        DrawRectangle((Tetromino+i)->x * scale , (Tetromino+i)->y * scale + 100, scale, scale, BLUE);
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

            //Hier kommt noch mehr, die verschiedenen Zahlen, können die Farben sein
            if(*(playfield+x+y*10) == 1){
                DrawRectangle(x * scale +x_offset , (y-20) * scale +y_offset , scale, scale, PURPLE);
            }
            if(*(playfield+x+y*10) == 2){
                DrawRectangle(x * scale +x_offset , (y-20) * scale +y_offset , scale, scale, GREEN);
            }
        }
    }
}