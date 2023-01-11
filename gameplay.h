//
// Created by Paul Weber on 11.12.22.
//

#ifndef TETRIS_GAMEPLAY_H
#define TETRIS_GAMEPLAY_H

#include <raylib.h>
#include <stdlib.h>
#include "structure.h"

//Funktion um den Tetromino in die x bzw y Richtung zu verschieben
//Autor: Paul Weber
void move_tetromino(tetromino *current_Tetromino,
                    float x_dif, // X Verschiebung
                    float y_dif, // Y Verschiebung
                    int *playfield // Array mit den liegenden Blöcken
);

//Funktion um einen Zufälligen Tetronimino an der richtigen Stelle zu platzieren
//Autor: Steffanie Wille, Paul Weber

void generate_tetromino(tetromino *current_Tetromino
);

//Funktion um ein Tetromino einen Block fallen zu lassen
//Rückgabe: true bei Kollision, false bei nicht Kollision
//Autor: Paul Weber
bool drop_pice_1(tetromino *current_Tetromino,
                 int *playfield // Array mit den liegenden Blöcken
);

//Funktion um eine vollständige Reihe aufzulösen (+inkrementieren des Zählers für vollständigen Linien)
//Rückgabe: ------- Kommt noch
//Autor: Paul Weber, Florian Bruchhage
int clear_line(tetromino *current_Tetromino,
               int *playfield // Array mit den liegenden Blöcken
);



void rotation(tetromino *current_Tetromino,
              int *playfield // Array mit den liegenden Blöcken
              );

#endif //TETRIS_GAMEPLAY_H
