//
// Created by Paul Weber on 11.12.22.
//

#include "gameplay.h"


void move_tetromino(Vector2* Tetromino, double x_dif, double y_dif, int scale, int x_offset, int y_offset){
    int check = 0;

    //Überprüfe, ob der Tetromino an die neue Stelle passt, wenn nicht, wird check auf 1 gesetzt und der Schritt der Koordinatenanpassung wird übersprungen
    for (int i = 0; i < 4; ++i) {
        if((Tetromino+i)->x + x_dif >= 10*scale+x_offset || (Tetromino+i)->x + x_dif < x_offset){
            check = 1;
        }
        if((Tetromino+i)->y +y_dif >= 20*scale+y_offset ){
            check = 1;
        }
    }

    if(check == 0){
        //Tetromino wieder in das Move Feld packen
        for (int i = 0; i < 4; ++i) {
            (Tetromino+i)->x = (Tetromino+i)->x + x_dif;
            (Tetromino+i)->y = (Tetromino+i)->y + y_dif;
        }
    }

    WaitTime(0.05);
}

void generate_tetromino(Vector2* Tetromino, int scale, int x_offset, int y_offset){

    int Type;

    Type = 0;//rand()%7;

    switch (Type) {
        case 0:
            /*          Type I
             *
             *          #### #### #### ####
             *          #### #### #### ####
             *          #### #### #### ####
             *
             */


            (Tetromino+0)->x = 3*scale+x_offset;
            (Tetromino+0)->y = -1*scale+y_offset;

            (Tetromino+1)->x = 4*scale+x_offset;
            (Tetromino+1)->y = -1*scale+y_offset;

            (Tetromino+2)->x = 5*scale+x_offset;
            (Tetromino+2)->y = -1*scale+y_offset;

            (Tetromino+3)->x = 6*scale+x_offset;
            (Tetromino+3)->y = -1*scale+y_offset;
            break;


        case 1:
            (Tetromino+0)->x = 0*scale+x_offset;
            (Tetromino+0)->y = 0*scale+y_offset;

            (Tetromino+1)->x = 1*scale+x_offset;
            (Tetromino+1)->y = 0*scale+y_offset;

            (Tetromino+2)->x = 0*scale+x_offset;
            (Tetromino+2)->y = 1*scale+y_offset;

            (Tetromino+3)->x = 1*scale+x_offset;
            (Tetromino+3)->y = 1*scale+y_offset;
            break;

        case 2:
            (Tetromino+0)->x = 0*scale+x_offset;
            (Tetromino+0)->y = 0*scale+y_offset;

            (Tetromino+1)->x = 1*scale+x_offset;
            (Tetromino+1)->y = 0*scale+y_offset;

            (Tetromino+2)->x = 0*scale+x_offset;
            (Tetromino+2)->y = 1*scale+y_offset;

            (Tetromino+3)->x = 1*scale+x_offset;
            (Tetromino+3)->y = 1*scale+y_offset;
            break;

        case 3:
            (Tetromino+0)->x = 0*scale+x_offset;
            (Tetromino+0)->y = 0*scale+y_offset;

            (Tetromino+1)->x = 1*scale+x_offset;
            (Tetromino+1)->y = 0*scale+y_offset;

            (Tetromino+2)->x = 0*scale+x_offset;
            (Tetromino+2)->y = 1*scale+y_offset;

            (Tetromino+3)->x = 1*scale+x_offset;
            (Tetromino+3)->y = 1*scale+y_offset;
            break;

        case 4:
            (Tetromino+0)->x = 0*scale+x_offset;
            (Tetromino+0)->y = 0*scale+y_offset;

            (Tetromino+1)->x = 1*scale+x_offset;
            (Tetromino+1)->y = 0*scale+y_offset;

            (Tetromino+2)->x = 0*scale+x_offset;
            (Tetromino+2)->y = 1*scale+y_offset;

            (Tetromino+3)->x = 1*scale+x_offset;
            (Tetromino+3)->y = 1*scale+y_offset;
            break;

        case 5:
            (Tetromino+0)->x = 0*scale+x_offset;
            (Tetromino+0)->y = 0*scale+y_offset;

            (Tetromino+1)->x = 1*scale+x_offset;
            (Tetromino+1)->y = 0*scale+y_offset;

            (Tetromino+2)->x = 0*scale+x_offset;
            (Tetromino+2)->y = 1*scale+y_offset;

            (Tetromino+3)->x = 1*scale+x_offset;
            (Tetromino+3)->y = 1*scale+y_offset;
            break;

        case 6:
            (Tetromino+0)->x = 0*scale+x_offset;
            (Tetromino+0)->y = 0*scale+y_offset;

            (Tetromino+1)->x = 1*scale+x_offset;
            (Tetromino+1)->y = 0*scale+y_offset;

            (Tetromino+2)->x = 0*scale+x_offset;
            (Tetromino+2)->y = 1*scale+y_offset;

            (Tetromino+3)->x = 1*scale+x_offset;
            (Tetromino+3)->y = 1*scale+y_offset;
            break;
    }
}


// Hilfsfunktion für das transponieren:
void swap(int* l_operand, int* r_operand){
    int puffer = *l_operand;
    *l_operand = *r_operand;
    *r_operand = puffer;
}

void rotation(Vector2 * Tetromino){
    /*
     * Grundsätzliches Vorgehen für eine Drehung des Tetrominos um 90° nach rechts:
     * Schritt 1: Die Blöcke als ganzes (Matrix) transponieren
     * Schritt 2: Die Matrix der Blöcke invertieren
     */

    int matrix[4][4];
    /*
     * Matrixzusammenstellung:
     * matrix[i]    <- entspeicht der x-Koordinate eines Blocks aus dem Tetromino
     * matrix[j]    <- entspricht der y-Koordinate eines Blocks aus dem Tetromino
    */

   // Den aktuellen Tetromino in ein 2D-Array kopieren (einfacheres handling)
    for(int i = 0; i < 4; i++){
        matrix[i][0] = (Tetromino+i)->x;
        matrix[0][i] = (Tetromino+i)->y;
    }

    // Schritt 1: Die 'matrix' transponieren:
    for(int i = 0; i < 4; i++){
        for (int j = i+1; j < 4; j++){
            swap(&(matrix[i][j]), &(matrix[j][i]));
        }
    }

    // Schritt 2: Die 'matrix' invertieren:
    // matrix[0][0] = matrix[4][4] usw. ...
    for (int i = 0; i < 4; i++){
        for (int j = 4; j >= 0 ; j--){
            matrix[i][i] = matrix[j][j];
        }
    }

    // Als letzten Schritt: Die Daten aus dem 'matrix'-Array wieder in den Tetromino schreiben:
    for(int i = 0; i < 4; i++){
        (Tetromino+i)->x = matrix[i][0];
        (Tetromino+i)->y = matrix[0][i];
    }
}