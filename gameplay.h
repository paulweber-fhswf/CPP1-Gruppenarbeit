//
// Created by Paul Weber on 11.12.22.
//

#ifndef TETRIS_GAMEPLAY_H
#define TETRIS_GAMEPLAY_H

#include <raylib.h>

#include <stdlib.h>

//Funktion um den Tetromino in die x bzw y Richtung zu verschieben
//Autor: Paul Weber
void move_tetromino(Vector2* Tetromino, //Vector Array mit den 4 Blöcken des Tetrominos
                    double x_dif, // X Verschiebung
                    double y_dif, // Y Verschiebung
                    int *playfield // Array mit den liegenden Blöcken
);

//Funktion um einen Zufälligen Tetronimino an der richtigen Stelle zu platzieren
//Autor: Steffanie Wille, Paul Weber
void generate_tetromino(Vector2* Tetromino //Vector Array mit den 4 Blöcken des Tetrominos
);

//Funktion um ein Tetromino einen Block fallen zu lassen
//Rückgabe: true bei Kollision, false bei nicht Kollision
//Autor: Paul Weber
bool drop_pice_1(Vector2 *current_Tetromino, //Vector Array mit den 4 Blöcken des Tetrominos
                 int *playfield // Array mit den liegenden Blöcken
);

//Funktion um eine vollständige Reihe aufzulösen (+inkrementieren des Zählers für vollständigen Linien)
//Rückgabe: ------- Kommt noch
//Autor: Paul Weber, Florian Bruchhage
int clear_line(Vector2 *current_Tetromino, //Vector Array mit den 4 Blöcken des Tetrominos
               int *playfield // Array mit den liegenden Blöcken
);

//Funktion zum Darstellen des Zählers für vollständige Linen
//Autor: Florian Bruchhage
void draw_completed_lines();


#endif //TETRIS_GAMEPLAY_H
