//
// Created by Paul Weber on 11.12.22.
//

#include "gameplay.h"
#include "raylib.h"
#include <stdlib.h>


void move_tetromino(Vector2* Tetromino, double x_dif, double y_dif){
    int check = 0;

    //Überprüfe, ob der Tetromino an die neue Stelle passt, wenn nicht, wird check auf 1 gesetzt und der Schritt der Koordinatenanpassung wird übersprungen
    for (int i = 0; i < 4; ++i) {
        if((Tetromino+i)->x + x_dif >= 10 || (Tetromino+i)->x + x_dif < 0){
            check = 1;
        }
        if((Tetromino+i)->y +y_dif >= 20 ){
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

void generate_tetromino(Vector2* Tetromino){

    int Type;

    Type = rand()%7;

    switch (Type) {
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

bool drop_pice_1(Vector2 *current_Tetromino){

    int check = 0;

    Vector2 *check_Tetromino = (Vector2*) malloc (4* sizeof(Vector2));

    for (int i = 0; i < 4; ++i) {
        (check_Tetromino+i)->y = (current_Tetromino+i)->y + 1 ;
        (check_Tetromino+i)->x = (current_Tetromino+i)->x;
    }

    for (int i = 0; i < 4; ++i) {
        if((check_Tetromino+i)->y >= 20){
            check = 1;
        }
    }




    if(check == 0){
        for (int i = 0; i < 4; ++i) {
            (current_Tetromino+i)->y = (check_Tetromino+i)->y;
            (current_Tetromino+i)->x = (check_Tetromino+i)->x;
        }
    }

    //WaitTime(0.5);

    if(check == 1){
        return true;
    }
    else{
        return false;
    }
}