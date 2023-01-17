//
// Created by Paul Weber on 11.12.22.
//

#ifndef TETRIS_OUTPUT_H
#define TETRIS_OUTPUT_H

#include <raylib.h>
#include "structure.h"

//Funktion um den aktuellen Tetromino auszugeben
//Autor: Paul Weber

void draw_output(tetromino *current_Tetromino //Struktur des aktuellen Tetrominos
);

//Funktion um den nächsten Tetromino anzuzeigen
//Autor: Paul Weber
void show_next_tetromino(tetromino *current_Tetromino //Struktur des aktuellen Tetrominos
);

//Funktion um alle liegenden Blöcke auszugeben
//Autor: Paul Weber
void draw_playfield(int *playfield // Array mit den liegenden Blöcken
);

//Bestimmen der Farbe
//Rückgabe: Farbe es types Color
//Autor: Paul Weber
Color get_color (int type //Typennummer des Blockes
);

//Funktion zum Darstellen des Zählers für vollständige Linen
//Autor: Florian Bruchhage, Paul Weber
void draw_completed_lines(int completed_lines);

//Funktion zum Darstellen eines GameOver Screens
//Autor: Florian Bruchhage, Paul Weber
void game_over(int completed_lines);

//Funktion um das Fenster zu initialisieren
//Autor: Paul Weber
void draw_init();

void draw_main_menu();

void draw_hold(tetromino *hold_Tetromino);

#endif //TETRIS_OUTPUT_H
