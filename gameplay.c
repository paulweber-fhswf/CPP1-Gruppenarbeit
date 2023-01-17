//
// Created by Paul Weber on 11.12.22.
//

#include "gameplay.h"
#include <raylib.h>
#include <stdlib.h>
#include "output.h"
#include "input.h"

// Initialisierende, globale Variablen:
int completed_lines = 0;

//Funktion um den Tetromino in die x bzw y Richtung zu verschieben
//Autor: Paul Weber
void move_tetromino(tetromino *current_Tetromino,
                    float x_dif, // X Verschiebung
                    float y_dif, // Y Verschiebung
                    int *playfield // Array mit den liegenden Blöcken
){
    int check = 0; // Check Variable mit 0 initialisieren

    //Überprüfe, ob der Tetromino an die neue Stelle passt, wenn nicht, wird check auf 1 gesetzt und der Schritt der Koordinatenanpassung wird übersprungen
    for (int i = 0; i < 4; ++i) {
        //Überprüfung, ob die Grenzen links und rechts eingehalten werden
        if((current_Tetromino->Tetromino+i)->x + x_dif >= 10 || (current_Tetromino->Tetromino+i)->x + x_dif < 0){
            check = 1;
        }

        //Überprüfung, ob die Bodengrenze eingehalten wird
        if((current_Tetromino->Tetromino+i)->y +y_dif >= 20 ){
            check = 1;
        }

        //Überprüfung, dass kein Block in einen anderen liegenden geschoben wird
        if( *(playfield + ( (int)((current_Tetromino->Tetromino+i)->x+x_dif) + (int)((current_Tetromino->Tetromino+i)->y+20+y_dif) * 10) ) >= 0){
            check = 1;
        }
    }


    //Falls alle Checks okay sind, werden die Koordinaten angepasst
    if(check == 0){
        for (int i = 0; i < 4; ++i) {
            (current_Tetromino->Tetromino+i)->x = (current_Tetromino->Tetromino+i)->x + x_dif;
            (current_Tetromino->Tetromino+i)->y = (current_Tetromino->Tetromino+i)->y + y_dif;
        }

        current_Tetromino->Rotation_Point.x = current_Tetromino->Rotation_Point.x + x_dif;
        current_Tetromino->Rotation_Point.y = current_Tetromino->Rotation_Point.y + y_dif;
    }
}


//Funktion um einen zufälligen Tetronimino an der richtigen Stelle zu platzieren
//Autor: Steffanie Wille, Paul Weber
void generate_tetromino(tetromino *current_Tetromino, //Struktur des aktuellen Tetrominos initialisieren
                        int pre_type
){
    //Es wird zufällig eine Zahl (0-6) generiert, diese ist der Typ, dann werden einfach für den Typen die entsprechenden Koordinaten
    //in das Array geschrieben

    if(pre_type < 0){
        current_Tetromino->type = GetRandomValue(0,6);
    }
    else{
        current_Tetromino->type = pre_type;
    }


    switch (current_Tetromino->type) {
        case 0:
            /*          Type I
             *
             *          #### #### #### ####
             *          #### #### #### ####
             *          #### #### #### ####
             *
             */


            (current_Tetromino->Tetromino+0)->x = 3;
            (current_Tetromino->Tetromino+0)->y = -1;

            (current_Tetromino->Tetromino+1)->x = 4;
            (current_Tetromino->Tetromino+1)->y = -1;

            (current_Tetromino->Tetromino+2)->x = 5;
            (current_Tetromino->Tetromino+2)->y = -1;

            (current_Tetromino->Tetromino+3)->x = 6;
            (current_Tetromino->Tetromino+3)->y = -1;

            current_Tetromino->Rotation_Point.x = (float)4.5;
            current_Tetromino->Rotation_Point.y = (float)-0.5;


            break;


        case 1:

            /*          Type J
             *
             *          ####
             *          ####
             *          ####
             *
             *          #### #### ####
             *          #### #### ####
             *          #### #### ####
             *
             */

            (current_Tetromino->Tetromino+0)->x = 3;
            (current_Tetromino->Tetromino+0)->y = -2;


            (current_Tetromino->Tetromino+1)->x = 3;
            (current_Tetromino->Tetromino+1)->y = -1;

            (current_Tetromino->Tetromino+2)->x = 4;
            (current_Tetromino->Tetromino+2)->y = -1;

            (current_Tetromino->Tetromino+3)->x = 5;
            (current_Tetromino->Tetromino+3)->y = -1;

            current_Tetromino->Rotation_Point.x = (float)4;
            current_Tetromino->Rotation_Point.y = (float)-1;

            break;

        case 2:

            /*          Type L
             *
             *                    ####
             *                    ####
             *                    ####
             *
             *          #### #### ####
             *          #### #### ####
             *          #### #### ####
             *
             */

            (current_Tetromino->Tetromino+3)->x = 5;
            (current_Tetromino->Tetromino+3)->y = -2;

            (current_Tetromino->Tetromino+0)->x = 3;
            (current_Tetromino->Tetromino+0)->y = -1;

            (current_Tetromino->Tetromino+1)->x = 4;
            (current_Tetromino->Tetromino+1)->y = -1;

            (current_Tetromino->Tetromino+2)->x = 5;
            (current_Tetromino->Tetromino+2)->y = -1;

            current_Tetromino->Rotation_Point.x = (float)4;
            current_Tetromino->Rotation_Point.y = (float)-1;

            break;

        case 3:

            /*          Type O
             *
             *        #### ####
             *        #### ####
             *        #### ####
             *
             *        #### ####
             *        #### ####
             *        #### ####
             *
             */

            (current_Tetromino->Tetromino+0)->x = 4;
            (current_Tetromino->Tetromino+0)->y = -2;

            (current_Tetromino->Tetromino+1)->x = 5;
            (current_Tetromino->Tetromino+1)->y = -2;

            (current_Tetromino->Tetromino+2)->x = 4;
            (current_Tetromino->Tetromino+2)->y = -1;

            (current_Tetromino->Tetromino+3)->x = 5;
            (current_Tetromino->Tetromino+3)->y = -1;

            current_Tetromino->Rotation_Point.x = (float)4.5;
            current_Tetromino->Rotation_Point.y = (float)-1.5;

            break;

        case 4:

            /*          Type S
             *
             *             #### ####
             *             #### ####
             *             #### ####
             *
             *        #### ####
             *        #### ####
             *        #### ####
             *
             */

            (current_Tetromino->Tetromino+0)->x = 3;
            (current_Tetromino->Tetromino+0)->y = -1;

            (current_Tetromino->Tetromino+1)->x = 4;
            (current_Tetromino->Tetromino+1)->y = -1;

            (current_Tetromino->Tetromino+2)->x = 4;
            (current_Tetromino->Tetromino+2)->y = -2;

            (current_Tetromino->Tetromino+3)->x = 5;
            (current_Tetromino->Tetromino+3)->y = -2;

            current_Tetromino->Rotation_Point.x = (float)4;
            current_Tetromino->Rotation_Point.y = (float)-1;

            break;

        case 5:

             /*          Type T
              *
              *             ####
              *             ####
              *             ####
              *
              *        #### #### ####
              *        #### #### ####
              *        #### #### ####
              *
              */

            (current_Tetromino->Tetromino+0)->x = 3;
            (current_Tetromino->Tetromino+0)->y = -1;

            (current_Tetromino->Tetromino+1)->x = 4;
            (current_Tetromino->Tetromino+1)->y = -1;

            (current_Tetromino->Tetromino+2)->x = 4;
            (current_Tetromino->Tetromino+2)->y = -2;

            (current_Tetromino->Tetromino+3)->x = 5;
            (current_Tetromino->Tetromino+3)->y = -1;

            current_Tetromino->Rotation_Point.x = (float)4;
            current_Tetromino->Rotation_Point.y = (float)-1;
            
            break;

        case 6:


            /*          Type Z
             *
             *         #### ####
             *         #### ####
             *         #### ####
             *
             *              #### ####
             *              #### ####
             *              #### ####
             *
             */

            (current_Tetromino->Tetromino+0)->x = 3;
            (current_Tetromino->Tetromino+0)->y = -2;

            (current_Tetromino->Tetromino+1)->x = 4;
            (current_Tetromino->Tetromino+1)->y = -2;

            (current_Tetromino->Tetromino+2)->x = 4;
            (current_Tetromino->Tetromino+2)->y = -1;

            (current_Tetromino->Tetromino+3)->x = 5;
            (current_Tetromino->Tetromino+3)->y = -1;

            current_Tetromino->Rotation_Point.x = (float)4.5;
            current_Tetromino->Rotation_Point.y = (float)-0.5;

            break;
    }
}


//Funktion um ein Tetromino einen Block fallen zu lassen
//Rückgabe: true bei Kollision, false bei nicht Kollision
//Autor: Paul Weber
bool drop_pice_1(tetromino *current_Tetromino, //Struktur des aktuellen Tetrominos
                 int *playfield // Array mit den liegenden Blöcken
){

    int check = 0; //Check Variable mit 0 initialisieren

    Vector2 *check_Tetromino = (Vector2*) malloc (4* sizeof(Vector2)); //Temporäres Vector Array erstellen

    //4 Blöcke des aktuellen Tetrominos in das temporäre Array kopieren, mit Koordinaten, die eins nach unten versetzt sind
    for (int i = 0; i < 4; ++i) {
        (check_Tetromino+i)->y = (current_Tetromino->Tetromino+i)->y + 1 ;
        (check_Tetromino+i)->x = (current_Tetromino->Tetromino+i)->x;
    }

    //Jeden Block überprüfen, ob dieser irgendwo aufliegt, wenn ja, Check auf 1 setzten
    for (int i = 0; i < 4; ++i) {

        //Überprüfen, ob der Block den Boden berührt
        if((check_Tetromino+i)->y >= 20){
            check = 1;
        }

        //Überprüfen, ob der Block einen liegenden Block berührt
        if(*(playfield + (int)(check_Tetromino+i)->x + (int)((check_Tetromino+i)->y+20) * 10) >= 0){
            check = 1;
        }
    }

    //Wenn kein Block etwas berührt, dann wird das temporäre Array zurück in das richtige kopiert
    if(check == 0){
        for (int i = 0; i < 4; ++i) {
            (current_Tetromino->Tetromino+i)->y = (check_Tetromino+i)->y;
        }

        current_Tetromino->Rotation_Point.y = current_Tetromino->Rotation_Point.y+1;
    }

    free(check_Tetromino); //Speicherbereich des temporären Arrays wieder freigeben


    //Wenn eine Kollision vorhanden ist, dann wird true zurückgegeben, wenn nicht false.
    if(check == 1){
        return true;
    }
    else{
        return false;
    }
}

//Funktion um eine vollständige Reihe aufzulösen (+inkrementieren des Zählers für vollständigen Linien)
//Rückgabe: Anzahl der beendeten Reihen
//Autor: Paul Weber, Florian Bruchhage
int clear_line(tetromino *current_Tetromino, //Struktur des aktuellen Tetrominos
               int *playfield // Array mit den liegenden Blöcken
){

    int clear; //Clear Variable initialisieren
    int bottom_line = -20;

    //Die Reihen der jeweils 4 platzierten Blöcke überprüfen
    for (int i = 0; i < 4; ++i) {
        clear = 0;

        //Durch die Reihe des platzierten Blockes gehen und zählen wie viele Blöcke in dieser Reihe sind
        for(int x = 0; x < 10; ++x) {
            if ( *(playfield +x+ ((int)(current_Tetromino->Tetromino+i)->y +20) *10) >= 0){
                clear++;
            }
        }

        //Wenn in der Reihe mindestens 10 Blöcke sind, ist diese Vollständig
        if (clear >= 10){

            //Alle Blöcke in dieser Reihe "leeren"
            for(int x = 0; x < 10; ++x) {
                *(playfield +x+ ((int)(current_Tetromino->Tetromino+i)->y +20) *10) = -1;
            }

            //Alle blöcke über dieser Reihe jeweils einen Block nach unten verschieben
            for (int j = (int)(current_Tetromino->Tetromino+i)->y+20; j > 19; --j) {
                for(int x = 0; x < 10; ++x) {
                    *(playfield + x + (j) * 10) = *(playfield + x + ((j-1) * 10));
                }
            }

            //Zähler für vollständige Linien inkrementieren
            completed_lines++;
        }
    }



    return completed_lines;
}



//Funktion zum Rotieren des aktuellen Tetrominos
//Autor: Florian Bruchhage, Paul Weber
void rotation(tetromino *current_Tetromino, //Struktur des aktuellen Tetrominos
              int *playfield // Array mit den liegenden Blöcken
){
    int check = 0;

    //1. Ein temporäres Array im HEAP für den gedrehten Tetromino anlegen:
    Vector2 temp[4];
    Vector2 temp_rp = current_Tetromino->Rotation_Point;

    temp_rp.x = -current_Tetromino->Rotation_Point.y;
    temp_rp.y = current_Tetromino->Rotation_Point.x;


    //Den temporären Tetromino um 90° drehen:
    for (int i = 0; i < 4; i++){
        temp[i].x = -(current_Tetromino->Tetromino+i)->y + (current_Tetromino->Rotation_Point.x - temp_rp.x);
        temp[i].y = (current_Tetromino->Tetromino+i)->x + (current_Tetromino->Rotation_Point.y - temp_rp.y);
    }

    for (int i = 0; i < 4; ++i) {
        //Überprüfung, ob die Grenzen links und rechts eingehalten werden
        if((temp+i)->x >= 10 || (temp+i)->x < 0){
            check = 1;
        }

        //Überprüfung, ob die Bodengrenze eingehalten wird
        if((temp+i)->y >= 20 ){
            check = 1;
        }

        if (*(playfield + ((int)(temp+i)->x + (int)((temp+i)->y+20)  * 10)) >= 0){
            check = 1;
        }
    }


    if(check == 0){
        //Den Inhalt des gedrehten, temporären Tetromino in den aktuellen Tetromino kopieren:
        for (int i = 0; i < 4; i++){
            (current_Tetromino->Tetromino+i)->x = (temp+i)->x;
            (current_Tetromino->Tetromino+i)->y = (temp+i)->y;
        }
    }
}


//Die grundliegende Spiellogik
//Rückgabe: 0 bei Spiel läuft noch, 1 für Beenden
//Autor: Paul Weber
int main_game_loop(tetromino *current_Tetromino, //Struktur des aktuellen Tetrominos
                   tetromino *next_Tetromino, //Struktur des nächsten Tetrominos
                   tetromino *hold_Tetromino,
                   int *playfield, //Array mit den liegenden Blöcken
                   int *completed_lines, //Anzahl der beendeten Reihen
                   double *old_time, //Zeit des letzten Fallens
                   int *hold_allow
){
    int end = 0; //Variable für das Beenden mit 0 initialisieren
    bool check = false; //Variable für das Aufliegen von Blöcken

    player_1(current_Tetromino, next_Tetromino, hold_Tetromino, playfield, hold_allow); //Eingabe Spieler 1 lesen

    //Tetromino nur fallen lassen, wenn genug Zeit vergangen ist
    if(GetTime() > 0.2+ *old_time){
        check = drop_pice_1(current_Tetromino, playfield); //Tetromino 1 Block fallen lassen
        *old_time = GetTime(); //old_time speichert die Zeit des letzten fallen lassens
    }

    //Wenn der Tetromino mit einem Block oder den Boden kollidiert
    if(check == true) {
        for (int i = 0; i < 4; ++i) {
            //Den aktuell fallenden Tetromino in das Array der liegenden Blöcke kopieren
            *(playfield + (int)(current_Tetromino->Tetromino+i)->x + (int)((current_Tetromino->Tetromino + i)->y + 20) * 10) = current_Tetromino->type;
        }

        //Funktion zum Reihe leeren, bzw. die Überprüfung dafür starten
        *completed_lines = clear_line(current_Tetromino, playfield);

        *current_Tetromino = *next_Tetromino; //Inhalt des nächsten in den aktuellen Tetromino übergeben
        generate_tetromino(next_Tetromino, -1); //Den nächsten Tetromino generieren

        //Wenn ein Tetromino über 20 Zeilen geht, wird das Spiel beendet
        for (int x = 0; x < 10; ++x) {
            if (*(playfield + x + 19 * 10) >= 0) {
                end = 1;
            }
        }

        *hold_allow = 1;
    }

    //Alle Ausgaben aufrufen
    ClearBackground(BLACK);
    draw_output(current_Tetromino);
    show_next_tetromino(next_Tetromino);
    draw_completed_lines(*completed_lines);
    draw_hold(hold_Tetromino);
    draw_playfield(playfield);

    return end; //Spielzustand zurück geben
}

bool hold_function(tetromino *current_Tetromino, //Struktur des aktuellen Tetrominos
          tetromino *next_Tetromino, //Struktur des nächsten Tetrominos
          tetromino *hold_Tetromino
){
    tetromino temp;

    if(hold_Tetromino->type == -1){
        *hold_Tetromino = *current_Tetromino;
        *current_Tetromino = *next_Tetromino;
        generate_tetromino(next_Tetromino, -1);
        generate_tetromino(hold_Tetromino, hold_Tetromino->type);
    }
    else{
        temp = *hold_Tetromino;
        generate_tetromino(hold_Tetromino, current_Tetromino->type);
        generate_tetromino(current_Tetromino, temp.type);
    }


    return true;
}


