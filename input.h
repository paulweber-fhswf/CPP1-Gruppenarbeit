//
// Created by Paul Weber on 11.12.22.
//

#ifndef TETRIS_INPUT_H
#define TETRIS_INPUT_H

#include <raylib.h>
#include "structure.h"

//Funktion um die Eingaben des ersten Spielers einzulesen
//Autor: Paul Weber
void player_1(tetromino *current_Tetromino, //Struktur des aktuellen Tetrominos
              tetromino *next_Tetromino, //Struktur des nächsten Tetrominos
              tetromino *hold_Tetromino,
              int *playfield, // Array mit den liegenden Blöcken
              int *hold_allow
);


#endif //TETRIS_INPUT_H
