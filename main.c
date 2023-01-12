//
// Created by Paul Weber on 27.11.22.
//

#include <raylib.h>
#include <stdlib.h>
#include "output.h"
#include "gameplay.h"
#include "structure.h"

//Aufrufen der Spiellogiken
//Autor: Paul Weber
int main()
{
    draw_init();

    tetromino current_Tetromino; //Struktur des aktuellen Tetrominos initialisieren
    tetromino next_Tetromino; //Struktur des aktuellen Tetrominos initialisieren
    double old_time = GetTime(); //old_time mit der aktuellen Zeit initialisieren
    int *playfield = (int*) malloc (10 * 40 * sizeof(int)); // *(playfield + x + y * 10)
    int completed_lines = 0; //Zähler für die Zeilen die vervollständigt wurden
    int end = 0; //Flag für das beenden

    //Spielfeld "leeren"
    for (int x = 0; x < 10; ++x) {
        for (int y = 0; y < 40; ++y) {
                *(playfield+x+y*10) = -1;
        }
    }

    //aktuellen und nächsten Tetromino generieren
    generate_tetromino(&current_Tetromino);
    generate_tetromino(&next_Tetromino);

    //Game loop solange laufen lassen, bis das Fenster geschlossen wird oder das Spiel zu Ende geht
    while (!WindowShouldClose() && end==0)
    {
        BeginDrawing(); //Ausgabe beginnen---------------
        end = main_game_loop(&current_Tetromino, &next_Tetromino, playfield, &completed_lines, &old_time);
        EndDrawing(); //Ausgabe beenden------------------
    }

    //Game Over screen anzeigen bis ESC gedrückt wird
    while(!WindowShouldClose()){
        BeginDrawing(); //Ausgabe beginnen---------------
        game_over(completed_lines);
        EndDrawing(); //Ausgabe beenden------------------
    }

    //Speicherbereiche freigeben
    free(playfield);

    //Fenster schließen und Programm beenden
    CloseWindow();
    return 0;
}