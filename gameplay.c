//
// Created by Paul Weber on 11.12.22.
//

#include "gameplay.h"
#include "raymath.h"
#include <raylib.h>
#include <stdlib.h>

// Initialisierende, globale Variablen:
int completed_lines = 0;

//Funktion um den Tetromino in die x bzw y Richtung zu verschieben
//Autor: Paul Weber
void move_tetromino(Vector2* Tetromino, //Vector Array mit den 4 Blöcken des Tetrominos
                    Vector2 *Rotation_Point, //Rotationspunkt des Tetrominos
                    double x_dif, // X Verschiebung
                    double y_dif, // Y Verschiebung
                    int *playfield // Array mit den liegenden Blöcken
                    ){

    int check = 0; // Check Variable mit 0 initialisieren

    //Überprüfe, ob der Tetromino an die neue Stelle passt, wenn nicht, wird check auf 1 gesetzt und der Schritt der Koordinatenanpassung wird übersprungen
    for (int i = 0; i < 4; ++i) {
        //Überprüfung, ob die Grenzen links und rechts eingehalten werden
        if((Tetromino+i)->x + x_dif >= 10 || (Tetromino+i)->x + x_dif < 0){
            check = 1;
        }

        //Überprüfung, ob die Bodengrenze eingehalten wird
        if((Tetromino+i)->y +y_dif >= 20 ){
            check = 1;
        }

        //Überprüfung, dass kein Block in einen anderen liegenden geschoben wird
        if(*(playfield + (int)((Tetromino+i)->x + x_dif) + (int)(((Tetromino+i)->y + 20 +y_dif) * 10))){
            check = 1;
        }
    }

    //Falls alle Checks okay sind, werden die Koordinaten angepasst
    if(check == 0){
        for (int i = 0; i < 4; ++i) {
            (Tetromino+i)->x = (Tetromino+i)->x + x_dif;
            (Tetromino+i)->y = (Tetromino+i)->y + y_dif;
        }

        Rotation_Point->x = Rotation_Point->x + x_dif;
        Rotation_Point->y = Rotation_Point->y + y_dif;
    }

    // Gibt an, wie schnell der Tetromino fällt (mögliche Erweiterung: Schwierigkeitsgrad)
    WaitTime(0.1);
}


//Funktion um einen Zufälligen Tetronimino an der richtigen Stelle zu platzieren
//Autor: Steffanie Wille, Paul Weber
void generate_tetromino(Vector2* Tetromino, //Vector Array mit den 4 Blöcken des Tetrominos
                        Vector2 *Rotation_Point, //Rotationspunkt des Tetrominos
                        int *type //Typ des Tetrominos
){
    //Es wird zufällig eine Zahl (0-6) generiert, diese ist der Typ, dann werden einfach für den Typen die entsprechenden Koordinaten
    //in das Array geschrieben


    *type = GetRandomValue(0,6);

    switch (*type) {
        case 0:
            /*          Type I
             *
             *          #### #### #### ####
             *          #### #### #### ####
             *          #### #### #### ####
             *
             */


            (Tetromino+0)->x = 3;
            (Tetromino+0)->y = -1;

            (Tetromino+1)->x = 4;
            (Tetromino+1)->y = -1;

            (Tetromino+2)->x = 5;
            (Tetromino+2)->y = -1;

            (Tetromino+3)->x = 6;
            (Tetromino+3)->y = -1;

            Rotation_Point->x = 4.5;
            Rotation_Point->y = -0.5;

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

            (Tetromino+0)->x = 3;
            (Tetromino+0)->y = -2;

            (Tetromino+1)->x = 3;
            (Tetromino+1)->y = -1;

            (Tetromino+2)->x = 4;
            (Tetromino+2)->y = -1;

            (Tetromino+3)->x = 5;
            (Tetromino+3)->y = -1;
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

            (Tetromino+0)->x = 3;
            (Tetromino+0)->y = -1;

            (Tetromino+1)->x = 4;
            (Tetromino+1)->y = -1;

            (Tetromino+2)->x = 5;
            (Tetromino+2)->y = -1;

            (Tetromino+3)->x = 5;
            (Tetromino+3)->y = -2;
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

            (Tetromino+0)->x = 4;
            (Tetromino+0)->y = -2;

            (Tetromino+1)->x = 5;
            (Tetromino+1)->y = -2;

            (Tetromino+2)->x = 4;
            (Tetromino+2)->y = -1;

            (Tetromino+3)->x = 5;
            (Tetromino+3)->y = -1;
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

            (Tetromino+0)->x = 3;
            (Tetromino+0)->y = -1;

            (Tetromino+1)->x = 4;
            (Tetromino+1)->y = -1;

            (Tetromino+2)->x = 4;
            (Tetromino+2)->y = -2;

            (Tetromino+3)->x = 5;
            (Tetromino+3)->y = -2;
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

            (Tetromino+0)->x = 3;
            (Tetromino+0)->y = -1;

            (Tetromino+1)->x = 4;
            (Tetromino+1)->y = -1;

            (Tetromino+2)->x = 4;
            (Tetromino+2)->y = -2;

            (Tetromino+3)->x = 5;
            (Tetromino+3)->y = -1;
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

            (Tetromino+0)->x = 3;
            (Tetromino+0)->y = -2;

            (Tetromino+1)->x = 4;
            (Tetromino+1)->y = -2;

            (Tetromino+2)->x = 4;
            (Tetromino+2)->y = -1;

            (Tetromino+3)->x = 5;
            (Tetromino+3)->y = -1;
            break;
    }
}


//Funktion um ein Tetromino einen Block fallen zu lassen
//Rückgabe: true bei Kollision, false bei nicht Kollision
//Autor: Paul Weber
bool drop_pice_1(Vector2 *current_Tetromino, //Vector Array mit den 4 Blöcken des Tetrominos
                 Vector2 *Rotation_Point, //Rotationspunkt des Tetrominos
                 int *playfield // Array mit den liegenden Blöcken
                 ){

    int check = 0; //Check Variable mit 0 initialisieren

    Vector2 *check_Tetromino = (Vector2*) malloc (4* sizeof(Vector2)); //Temporäres Vector Array erstellen

    //4 Blöcke des aktuellen Tetrominos in das Temporäre Array kopieren, mit Koordinaten, die eins nach unten versetzt sind
    for (int i = 0; i < 4; ++i) {
        (check_Tetromino+i)->y = (current_Tetromino+i)->y + 1 ;
        (check_Tetromino+i)->x = (current_Tetromino+i)->x;
    }

    //Jeden Block überprüfen, ob dieser irgendwo aufliegt, wenn ja, Check auf 1 setzten
    for (int i = 0; i < 4; ++i) {

        //Überprüfen, ob der Block den Boden berührt
        if((check_Tetromino+i)->y >= 20){
            check = 1;
        }

        //Überprüfen, ob der Block einen liegenden Block berührt
        if(*(playfield + (int)(check_Tetromino+i)->x + (int)((check_Tetromino+i)->y+20) * 10) > 0){
            check = 1;
        }
    }

    //Wenn kein Block etwas berührt, dann wird das temporäre Array zurück in das richtige kopiert
    if(check == 0){
        for (int i = 0; i < 4; ++i) {
            (current_Tetromino+i)->y = (check_Tetromino+i)->y;
        }

        Rotation_Point->y = Rotation_Point->y+1;
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
//Rückgabe: ------- Kommt noch
//Autor: Paul Weber, Florian Bruchhage
int clear_line(Vector2 *current_Tetromino, //Vector Array mit den 4 Blöcken des Tetrominos
               int *playfield // Array mit den liegenden Blöcken
               ){

    int clear; //Clear Variable initialisieren

    //Die Reihen der jeweils 4 platzierten Blöcke überprüfen
    for (int i = 0; i < 4; ++i) {

        clear = 0;

        //Durch die Reihe des platzierten Blockes gehen und zählen wie viele Blöcke in dieser Reihe sind
        for(int x = 0; x < 10; ++x) {
            if ( *(playfield +x+ ((int)(current_Tetromino+i)->y +20) *10) == 1){
                clear++;
            }
        }

        //Wenn in der Reihe mindestens 10 Blöcke sind, ist diese Vollständig
        if (clear >= 10){

            //Alle Blöcke in dieser Reihe "leeren"
            for(int x = 0; x < 10; ++x) {
                *(playfield +x+ ((int)(current_Tetromino+i)->y +20) *10) = 0;
            }

            //Alle blöcke über dieser Reihe jeweils einen Block nach unten verschieben
            for (int j = (int)(current_Tetromino+i)->y+20; j > 0; --j) {
                for(int x = 0; x < 10; ++x) {
                   *(playfield +x+ (j) *10) = *(playfield +x+ (j-1) *10);
                }
            }
            //Zähler für vollständige Linien inkrementieren
            completed_lines++;
        }

    }

    return 0;
}

//Funktion zum Darstellen des Zählers für vollständige Linen
//Autor: Florian Bruchhage
void draw_completed_lines(){
    DrawText(TextFormat("FERTIGE LINIEN:\n       %4i", completed_lines), 580, 10, 20, GREEN);
}


//Funktion zum Rotieren des aktuellen Tetrominos
//Autor: Florian Bruchhage
void rotation(Vector2 *Tetromino,
              Vector2 *Rotation_Point //Rotationspunkt des Tetrominos
                )
{
    //1. Ein temporäres Array im HEAP für den gedrehten Tetromino anlegen:
    Vector2 *temp = (Vector2 *)malloc(4 * sizeof(Vector2));
    Vector2 temp_rp = *Rotation_Point;

    //Den temporären Tetromino um 90° drehen:
    for (int i = 0; i < 4; i++){
        temp[i].x = -Tetromino[i].y;
        temp[i].y = Tetromino[i].x;
    }
        Rotation_Point->x = -temp_rp.y;
        Rotation_Point->y = temp_rp.x;


    //Den Inhalt des gedrehten, temporären Tetromino in den aktuellen Tetromino kopieren:
    for (int i = 0; i < 4; i++){

       (Tetromino+i)->x = (temp+i)->x + (temp_rp.x - Rotation_Point->x);
       (Tetromino+i)->y = (temp+i)->y + (temp_rp.y - Rotation_Point->y);
    }

    //Das temporäre Array wieder freigeben.
    free(temp);
}

