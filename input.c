//
// Created by Paul Weber on 11.12.22.
//

#include "input.h"
#include "gameplay.h"
#include "structure.h"

//Funktion um die Eingaben des ersten Spielers einzulesen
//Autor: Paul Weber
void player_1(tetromino *current_Tetromino, //Struktur des aktuellen Tetrominos
              tetromino *next_Tetromino, //Struktur des nächsten Tetrominos
              tetromino *hold_Tetromino,
              int *playfield, // Array mit den liegenden Blöcken
              int *hold_allow
){

    float x_dif = 0, y_dif = 0; // Variablen für die X und Y unterschiede

    //Einlesen der Tastatur: abhängig von der gedrückten Taste, wird der Tetromino um 1 verschoben (KeyDown liest kontinuierlich ein)
    if (IsKeyDown(KEY_RIGHT)){
        x_dif = 1;
        WaitTime(0.065); //Kurze Wartezeit, damit nicht zu viele inputs gelesen werden
    }

    if (IsKeyDown(KEY_LEFT)){
        x_dif = -1;
        WaitTime(0.065); //Kurze Wartezeit, damit nicht zu viele inputs gelesen werden
    }

    if (IsKeyDown(KEY_DOWN)){
        y_dif = 1;
        WaitTime(0.065); //Kurze Wartezeit, damit nicht zu viele inputs gelesen werden
    }

    if(IsKeyPressed(KEY_C)){
        if(*hold_allow == 1){
            hold_function(current_Tetromino, next_Tetromino, hold_Tetromino);
            *hold_allow = 0;
        }
    }

    //Bei X wird um 90° gedreht (KeyPressed liest einmal ein)
    if (IsKeyPressed(KEY_X)){
        rotation(current_Tetromino, playfield);
    }

    move_tetromino(current_Tetromino, x_dif, y_dif, playfield); //Die X bzw. Y Differenz an die bewegen Funktion geben
}
