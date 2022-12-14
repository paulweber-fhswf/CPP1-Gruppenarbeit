//
// Created by Paul Weber on 27.11.22.
//

#include <raylib.h>
#include <stdlib.h>
#include "output.h"
#include "input.h"
#include "gameplay.h"
#include "structure.h"


//Aufrufen der Spiellogiken
//Autor: Paul Weber
int main()
{
    //Konfiguration für das Spielfenster
    const int screenWidth = 800;
    const int screenHeight = 450;
    InitWindow(screenWidth, screenHeight, "Tetris");
    SetTargetFPS(60);

    //Array für aktuellen und nächsten Teromino erstellen und Array für die liegenden Blöcke erstellen

    tetromino current_Tetromino;
    tetromino next_Tetromino;

    int *playfield = (int*) malloc (10 * 40 * sizeof(int)); // *(playfield + x + y * 10)

    //Spielfeld "leeren"
    for (int x = 0; x < 10; ++x) {
        for (int y = 0; y < 40; ++y) {
                *(playfield+x+y*10) = -1;
        }
    }

    //Zwei Tetromino für den aktuellen und nächsten generieren
    generate_tetromino(&current_Tetromino);
    generate_tetromino(&next_Tetromino);

    int end = 0; //Variable für das beenden mit 0 initalisieren
    bool check = false;

    //Game loop solange laufen lassen, bis das Fenster geschlossen wird oder das Spiel zu Ende geht
    while (!WindowShouldClose())
    {
        // Fall: GAME OVER
        if (end == 1){
            draw_game_over();
            break;
        }

        player_1(&current_Tetromino, playfield); //Eingabe Spieler 1 lesen
        check = drop_pice_1(&current_Tetromino, playfield); //Tetromino 1 Block fallen lassen


        //Ausgabe beginnen---------------
        BeginDrawing();

        //Hintergrund
        ClearBackground(DARKGRAY);

        //Spielfeld, den aktuellen Tetomino und weitere Spielfeldparameter ausgeben
        draw_output(&current_Tetromino);
        show_next_tetromino(&next_Tetromino);

        draw_completed_lines();

        //Wenn der Tetromino mit einem Block oder den Boden kollidiert
        if(check == true){
            for (int i = 0; i < 4; ++i) {

                //Den aktuell fallenden Tetromino in das Array der liegenden Blöcke kopieren
                *(playfield + (int)(current_Tetromino.Tetromino+i)->x + (int)((current_Tetromino.Tetromino+i)->y+20) * 10) = current_Tetromino.type;

                //Funktion zum Reihe leeren, bzw. die Überprüfung dafür starten
                clear_line(&current_Tetromino, playfield);
            }

            current_Tetromino = next_Tetromino;

            generate_tetromino(&next_Tetromino);

            //Wenn ein Teromino über 20 Zeilen geht, wird das Spiel beendet
            for (int x = 0; x < 10; ++x) {
                if(*(playfield+x+19*10) >= 0){
                    end = 1;
                }
            }

        }

        draw_playfield(playfield); //Spielfeld zeichnen

        EndDrawing(); // Zeichnen beenden
    }

    //Variablen freigeben
    free(playfield);

    CloseWindow(); //Fenster schließen

    return 0;
}