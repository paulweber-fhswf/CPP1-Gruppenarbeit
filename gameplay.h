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
void move_tetromino(tetromino *current_Tetromino, //Struktur des aktuellen Tetrominos
                    float x_dif, // X Verschiebung
                    float y_dif, // Y Verschiebung
                    int *playfield // Array mit den liegenden Blöcken
);

//Funktion um einen zufälligen Tetronimino an der richtigen Stelle zu platzieren
//Autor: Steffanie Wille, Paul Weber
void generate_tetromino(tetromino *current_Tetromino, //Struktur des aktuellen Tetrominos initialisieren
                        int pre_type //-1 für einen zufälligen Typ, 0-6 um einen bestimmten Typen neu zu erstellen
);

//Funktion um ein Tetromino einen Block fallen zu lassen
//Rückgabe: true bei Kollision, false bei nicht Kollision
//Autor: Paul Weber
bool drop_pice_1(tetromino *current_Tetromino, //Struktur des aktuellen Tetrominos
                 int *playfield // Array mit den liegenden Blöcken
);

//Funktion um eine vollständige Reihe aufzulösen (+inkrementieren des Zählers für vollständigen Linien)
//Rückgabe: Anzahl der beendeten Reihen
//Autor: Paul Weber, Florian Bruchhage
int clear_line(tetromino *current_Tetromino, //Struktur des aktuellen Tetrominos
               int *playfield // Array mit den liegenden Blöcken
);

//Funktion zum Rotieren des aktuellen Tetrominos
//Autor: Florian Bruchhage, Paul Weber
void rotation(tetromino *current_Tetromino, //Struktur des aktuellen Tetrominos
              int *playfield // Array mit den liegenden Blöcken
);

//Die grundliegende Spiellogik
//Rückgabe: 0 bei Spiel läuft noch, 1 für Beenden
//Autor: Paul Weber
int main_game_loop(tetromino *current_Tetromino, //Struktur des aktuellen Tetrominos
                   tetromino *next_Tetromino, //Struktur des nächsten Tetrominos
                   tetromino *hold_Tetromino, //Struktur des hold Tetrominos
                   int *playfield, //Array mit den liegenden Blöcken
                   int *completed_lines, //Anzahl der beendeten Reihen
                   double *old_time, //Zeit des letzten Fallens
                   int *hold_allow, //Check ob der aktuelle Tetromino mit Hold getauscht werden darf
                   int *pause //Pause Zustand
);

//Ablage für einen Tetromino, tauscht mit dem aktuellen Tetromino
//Autor: Paul Weber
void hold_function(tetromino *current_Tetromino, //Struktur des aktuellen Tetrominos
          tetromino *next_Tetromino, //Struktur des nächsten Tetrominos
          tetromino *hold_Tetromino //Struktur des hold Tetrominos
);

#endif //TETRIS_GAMEPLAY_H
