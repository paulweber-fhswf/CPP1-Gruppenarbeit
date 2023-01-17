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
    tetromino hold_Tetromino;
    double old_time = GetTime(); //old_time mit der aktuellen Zeit initialisieren
    int *playfield = (int*) malloc (10 * 40 * sizeof(int)); // *(playfield + x + y * 10)
    int completed_lines = 0; //Zähler für die Zeilen die vervollständigt wurden
    int end; //Flag für das beenden
    int exit = 0;
    int next = 0;
    int hold_allow = 1;

    while(exit == 0){

        while(next == 0 && exit == 0){
            BeginDrawing(); //Ausgabe beginnen---------------
            draw_main_menu();
            EndDrawing(); //Ausgabe beenden------------------

            //Beenden oder zum nächsten Fenster gehen
            if(WindowShouldClose()){
                exit = 1;
            }
            if (IsKeyPressed(KEY_ENTER)){
                next = 1;
            }
        }

        //Alles für das nächste Spiel zurücksetzten
        next = 0;
        end = 0;

        //Spielfeld "leeren"
        for (int x = 0; x < 10; ++x) {
            for (int y = 0; y < 40; ++y) {
                *(playfield+x+y*10) = -1;
            }
        }

        //aktuellen und nächsten Tetromino generieren
        generate_tetromino(&current_Tetromino, -1);
        generate_tetromino(&next_Tetromino, -1);

        hold_Tetromino.type = -1;

        while(exit == 0 && end == 0){
            BeginDrawing(); //Ausgabe beginnen---------------
            end = main_game_loop(&current_Tetromino, &next_Tetromino, &hold_Tetromino, playfield, &completed_lines, &old_time, &hold_allow);
            EndDrawing(); //Ausgabe beenden------------------

            //Beenden
            if(WindowShouldClose()){
                exit = 1;
            }
        }

        while(exit == 0 && next == 0){
            BeginDrawing(); //Ausgabe beginnen---------------
            game_over(completed_lines);
            EndDrawing(); //Ausgabe beenden------------------

            //Beenden oder zum nächsten Fenster gehen
            if(WindowShouldClose()){
                exit = 1;
            }
            if (IsKeyPressed(KEY_ENTER)){
                next = 1;
            }
        }

        next = 0;
    }

    //Speicherbereiche freigeben
    free(playfield);

    //Fenster schließen und Programm beenden
    CloseWindow();
    return 0;
}