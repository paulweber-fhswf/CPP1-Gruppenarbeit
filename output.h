//
// Created by Paul Weber on 11.12.22.
//

#ifndef TETRIS_OUTPUT_H
#define TETRIS_OUTPUT_H

#include <raylib.h>

//Funktion um den aktuellen Tetromino auszugeben
//Autor: Paul Weber
void draw_output(Vector2* Tetromino //Vector Array mit den 4 Blöcken des Tetrominos
);

//Funktion um den nächsten Tetromino anzuzeigen
//Autor: Paul Weber
void show_next_tetromino(Vector2* Tetromino //Vector Array mit den 4 Blöcken des Tetrominos
);

//Funktion um alle liegenden Blöcke auszugeben
//Autor: Paul Weber
void draw_playfield(int *playfield // Array mit den liegenden Blöcken
);

//Funktion zum Darstellen eines GameOver Screens
//Autor: Florian Bruchhage
void draw_game_over();

#endif //TETRIS_OUTPUT_H
