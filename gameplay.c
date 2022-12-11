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
        if((Tetromino+i)->y +y_dif >= 20*scale+y_offset || (Tetromino+i)->y +y_dif < y_offset){
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