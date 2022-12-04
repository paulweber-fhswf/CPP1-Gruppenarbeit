//
// Created by Paul Weber on 27.11.22.
//

#include <ncurses.h>
#include <stdlib.h>

void field_output(char *field, int *move_field);
void move_block(int *move_field, int x_dif, int y_dif);
int keypress(int *x_dif, int *y_dif);

int main()
{
    //field Werte berechnen: *(field+ x + y*10)
    //move_field Werte berechnen *(move_field + Block + X_Y * 4) Gibt Koordinaten für einen Block, wenn X_Y = 0 -> x Adresse, X_Y = 1 -> y Adresse

    char *field = (char*)malloc(10*40*sizeof(char));
    int *move_field = (int*)malloc(4*2* sizeof(int));


    //ncurses config
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    curs_set(0);

    erase();

    //Spielfeld mit . Initialisieren
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 10; ++j) {
            *(field + j + i*10) = '.';
        }
    }

    //Move Ebene mit . Initialisieren
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 10; ++j) {
            *(field + j + i*10) = '.';
        }
    }


    //Zum Testen: Einen Block in der move Ebene erstellen
    *(move_field + 0 + 0*4) = 0;
    *(move_field + 0 + 1*4) = 0;

    *(move_field + 1 + 0*4) = 0;
    *(move_field + 1 + 1*4) = 1;


    *(move_field + 2 + 0*4) = 1;
    *(move_field + 2 + 1*4) = 0;


    *(move_field + 3 + 0*4) = 1;
    *(move_field + 3 + 1*4) = 1;


    int quit = 0;
    int x_dif, y_dif;

    while(!quit) {

        quit = keypress(&x_dif, &y_dif);

        erase();

        move_block(move_field, x_dif, y_dif);
        field_output(field, move_field);
        refresh();
    }



    return 0;
}

void field_output(char *field, int *move_field){
    /*
        Aussehen des Spielfeldes. Basierend auf dem Aussehen der Electronika 60 Version von Tetris,
        aber angepasst an die aktuellen Regeln

        Alle Punkte, sind das eigentliche Spielfeld, das in *field gespeichert ist

       <! . . . . . . . . . . !>
       <! . . . . . . . . . . !>
       <! . . . . . . . . . . !>
       <! . . . . . . . . . . !>
       <! . . . . . . . . . . !>
       <! . . . . . . . . . . !>
       <! . . . . . . . . . . !>
       <! . . . . . . . . . . !>
       <! . . . . . . . . . . !>
       <! . . . . . . . . . . !>
       <! . . . . . . . . . . !>
       <! . . . . . . . . . . !>
       <! . . . . . . . . . . !>
       <! . . . . . . . . . . !>
       <! . . . . . . . . . . !>
       <! . . . . . . . . . . !>
       <! . . . . . . . . . . !>
       <! . . . . . . . . . . !>
       <! . . . . . . . . . . !>
       <! . . . . . . . . . . !>
       <!=====================!>
         /\/\/\/\/\/\/\/\/\/\/\
    */

    //Erst einmal alles außer das eigentliche Spielfeld ausgeben

    for (int i = 0; i < 20; ++i) {
        mvprintw(i, 0, "<");
        mvprintw(i, 1, "!");
        mvprintw(i, 23, "!");
        mvprintw(i, 24, ">");
    }

    mvprintw(20, 0, "<!=====================!>");
    mvprintw(21, 2, "/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\");

    //Spielfeld ausgeben
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; j += 2) {
            mvprintw(19-i, j + 3, "%c", *(field+ j/2 + i*10));
        }
    }

    //Den bewegenden Block ausgeben
    for (int i = 0; i < 4; ++i) {
        mvprintw(19- *(move_field + i + 1*4) , 2* *(move_field + i + 0*4)  +3, "#");
    }
}

void move_block(int *move_field, int x_dif, int y_dif){
    int check = 0;

    //Überprüfe, ob der Tetromino an die neue Stelle passt, wenn nicht, wird check auf 1 gesetzt und der Schritt der Koordinatenanpassung wird übersprungen
    for (int i = 0; i < 4; ++i) {
        if(*(move_field + i + 0*4) + x_dif > 9 || *(move_field + i + 0*4)+ x_dif < 0){
            check = 1;
        }
        if(*(move_field + i + 1*4)+y_dif > 19 || *(move_field + i + 1*4)+y_dif < 0){
            check = 1;
        }
    }

    if(check == 0){
        //Tetromino wieder in das Move Feld packen
        for (int i = 0; i < 4; ++i) {
            *(move_field + i + 0*4) = *(move_field + i + 0*4) + x_dif;
            *(move_field + i + 1*4) = *(move_field + i + 1*4) + y_dif;
        }
    }
}

int keypress(int *x_dif, int *y_dif){
    int pressed_key, quit =0;

    pressed_key = getch();

    *x_dif = 0;
    *y_dif = 0;

    switch (pressed_key) {
        case ERR:
            napms(10);
            break;

        case KEY_UP:
            *y_dif = 1;
            break;

        case KEY_DOWN:
            *y_dif = -1;
            break;

        case KEY_LEFT:
            *x_dif = -1;
            break;

        case KEY_RIGHT:
            *x_dif = 1;
            break;
        case 'q':
            quit = 1;
            break;
    }

    return quit;
};