//
// Created by Paul Weber on 27.11.22.
//

#include <raylib.h>
#include <stdlib.h>
#include "output.h"
#include "input.h"
#include "gameplay.h"
#include "structure.h"

int main_game_loop(tetromino *current_Tetromino,
                   tetromino *next_Tetromino,
                   int *playfield, // Array mit den liegenden Blöcken
                   int *completed_lines,
                   double *old_time
);


//Aufrufen der Spiellogiken
//Autor: Paul Weber
int main()
{
    draw_init();

    //Array für aktuellen und nächsten Teromino erstellen und Array für die liegenden Blöcke erstellen

    tetromino current_Tetromino;
    tetromino next_Tetromino;

    double old_time = GetTime();
    int *playfield = (int*) malloc (10 * 40 * sizeof(int)); // *(playfield + x + y * 10)
    int completed_lines = 0;
    int end = 0;


    //Spielfeld "leeren"
    for (int x = 0; x < 10; ++x) {
        for (int y = 0; y < 40; ++y) {
                *(playfield+x+y*10) = -1;
        }
    }

    //Zwei Tetromino für den aktuellen und nächsten generieren
    generate_tetromino(&current_Tetromino);
    generate_tetromino(&next_Tetromino);

    //Game loop solange laufen lassen, bis das Fenster geschlossen wird oder das Spiel zu Ende geht
    while (!WindowShouldClose() && end==0)
    {
        //Ausgabe beginnen---------------
        BeginDrawing();

        end = main_game_loop(&current_Tetromino, &next_Tetromino, playfield, &completed_lines, &old_time);

        EndDrawing(); // Zeichnen beenden
    }

    while(!WindowShouldClose()){
        BeginDrawing();
        game_over(completed_lines);
        EndDrawing();
    }


    //Variablen freigeben
    free(playfield);

    CloseWindow(); //Fenster schließen

    return 0;
}


int main_game_loop(tetromino *current_Tetromino,
                   tetromino *next_Tetromino,
                   int *playfield, // Array mit den liegenden Blöcken
                   int *completed_lines,
                   double *old_time
){
    int end = 0; //Variable für das beenden mit 0 initalisieren
    bool check = false;


    player_1(current_Tetromino, playfield); //Eingabe Spieler 1 lesen

    if(GetTime() > *old_time+0.2){
        check = drop_pice_1(current_Tetromino, playfield); //Tetromino 1 Block fallen lassen
        *old_time = GetTime();
    }


    //Wenn der Tetromino mit einem Block oder den Boden kollidiert
    if(check == true) {
        for (int i = 0; i < 4; ++i) {

            //Den aktuell fallenden Tetromino in das Array der liegenden Blöcke kopieren
            *(playfield + (int) (current_Tetromino->Tetromino + i)->x + (int) ((current_Tetromino->Tetromino + i)->y + 20) * 10) = current_Tetromino->type;

            //Funktion zum Reihe leeren, bzw. die Überprüfung dafür starten
                *completed_lines = clear_line(current_Tetromino, playfield);
            }

            *current_Tetromino = *next_Tetromino;

            generate_tetromino(next_Tetromino);

            //Wenn ein Teromino über 20 Zeilen geht, wird das Spiel beendet
            for (int x = 0; x < 10; ++x) {
                if (*(playfield + x + 19 * 10) >= 0) {
                    end = 1;
                }
            }
        }


    //Hintergrund
    ClearBackground(DARKGRAY);

    //Spielfeld, den aktuellen Tetomino und weitere Spielfeldparameter ausgeben
    draw_output(current_Tetromino);
    show_next_tetromino(next_Tetromino);
    draw_completed_lines(*completed_lines);
    draw_playfield(playfield); //Spielfeld zeichnen


    return end;
}
