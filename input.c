//
// Created by Paul Weber on 11.12.22.
//

#include "input.h"
#include "gameplay.h"

//Funktion um die Eingaben des ersten Spielers einzulesen
//Autor: Paul Weber
void player_1(Vector2* Tetromino, //Vector Array mit den 4 Blöcken des Tetrominos
              int *playfield // Array mit den liegenden Blöcken
              ){

    int x_dif = 0, y_dif = 0; // Variablen für die X und Y unterschiede

    //Einlesen der Tastatur: abhängig von der gedrückten Taste, wird der Tetromino um 1 verschoben

    if (IsKeyDown(KEY_RIGHT)){
        x_dif = 1;
    }

    if (IsKeyDown(KEY_LEFT)){
        x_dif = -1;
    }

    if (IsKeyDown(KEY_UP)){
        y_dif = -1;
    }

    if (IsKeyDown(KEY_DOWN)){
        y_dif = 1;
    }

    if (IsKeyDown(KEY_X)){
        rotation(Tetromino);
    }

    move_tetromino(Tetromino, x_dif, y_dif, playfield); //Die X bzw. Y Differenz an die bewegen Funktion geben
}