//
// Created by Paul Weber on 11.12.22.
//

#include "input.h"
#include "gameplay.h"
#include "structure.h"

#define move_wait_time 0.1

//Funktion um die Eingaben des ersten Spielers einzulesen
//Autor: Paul Weber
void player_1(tetromino *current_Tetromino, //Struktur des aktuellen Tetrominos
              tetromino *next_Tetromino, //Struktur des nächsten Tetrominos
              tetromino *hold_Tetromino, //Struktur des hold Tetrominos
              int *playfield, // Array mit den liegenden Blöcken
              int *hold_allow, //Check ob der aktuelle Tetromino mit Hold getauscht werden darf
              int *pause //Pause Zustand
){

    float x_dif = 0, y_dif = 0; // Variablen für die X und Y unterschiede

    //Einlesen der Tastatur: abhängig von der gedrückten Taste, wird der Tetromino um 1 verschoben (KeyDown liest kontinuierlich ein)
    if (IsKeyDown(KEY_RIGHT)){
        x_dif = 1;
        WaitTime(move_wait_time); //Kurze Wartezeit, damit nicht zu viele inputs gelesen werden
    }

    if (IsKeyDown(KEY_LEFT)){
        x_dif = -1;
        WaitTime(move_wait_time); //Kurze Wartezeit, damit nicht zu viele inputs gelesen werden
    }

    if (IsKeyDown(KEY_DOWN)){
        y_dif = 1;
        WaitTime(move_wait_time); //Kurze Wartezeit, damit nicht zu viele inputs gelesen werden
    }

    //Hold Funktion
    if(IsKeyPressed(KEY_C)){
        //Bevor Hold angewendet wird, wird geguckt, ob in diesem Spielzug bereits Hold genutzt wurde
        if(*hold_allow == 1){
            hold_function(current_Tetromino, next_Tetromino, hold_Tetromino);
            *hold_allow = 0; //Hold für den restlichen Spielzug verbieten
        }
    }

    //Bei X wird um 90° gedreht (KeyPressed liest einmal ein)
    if (IsKeyPressed(KEY_X)){
        rotation(current_Tetromino, playfield);
    }

    if(IsKeyPressed(KEY_P)){
        *pause = 1;
    }

    move_tetromino(current_Tetromino, x_dif, y_dif, playfield); //Die X bzw. Y Differenz an die bewegen Funktion geben
}
