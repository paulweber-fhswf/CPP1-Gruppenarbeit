//
// Created by Paul Weber on 27.11.22.
//

#include <ncurses.h>
#include <stdlib.h>

void field_output(char *field);
void move_block(char *field, int x_dif, int y_dif);

int main()
{
    //3D Array Werte berechnen: *(field+ x + y*10 + s*10*40)
    char *field = (char*)malloc(10*40*2*sizeof(char));


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
            *(field + j + i*10 + 0*10*40) = '.';
        }
    }

    //Move Ebene mit . Initialisieren
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 10; ++j) {
            *(field + j + i*10 + 1*10*40) = '.';
        }
    }


    //Zum Testen: Einen Block in der move Ebene erstellen
    *(field + 0 + 0*10 + 1*10*40) = '#';
    *(field + 1 + 0*10 + 1*10*40) = '#';
    *(field + 0 + 1*10 + 1*10*40) = '#';
    *(field + 1 + 1*10 + 1*10*40) = '#';




    int pressed_key;
    int quit = 0;
    int x_dif, y_dif;

    while(!quit) {
        pressed_key = getch();

        x_dif = 0;
        y_dif = 0;

        switch (pressed_key) {
            case ERR:
                napms(10);
                break;

            case KEY_UP:
                y_dif = 1;
                break;

            case KEY_DOWN:
                y_dif = -1;
                break;

            case KEY_LEFT:
                x_dif = -1;
                break;

            case KEY_RIGHT:
                x_dif = 1;
                break;
            case 'q':
                quit = 1;
                break;
        }

        move_block(field, x_dif, y_dif);
        field_output(field);
        refresh();
    }



    return 0;
}

void field_output(char *field){
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

    // 0 1  22 23

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
            mvprintw(19-i, j + 3, "%c", *(field+ j/2 + (i*10) + 1*40*10));
        }
    }



}

void move_block(char *field, int x_dif, int y_dif){

    //Move Ebene durchgehen, gucken, wo nicht 0 Elemente stehen, diese dann mit dif Plätze bewegen
    //jeder Tetromino besteht aus 4 Blöcken, das position array speichert alle 4 xy Adresspaare

    int pos[4][2] = {0};
    int count = 0, check = 0;



    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 10; j++) {
            if('#' == *(field+ j + i*10 + 1*40*10)){
                pos[count][0] = j;
                pos[count][1] = i;
                count++;
            }
        }
    }


    //Move Array mit 0 auffüllen
    for (int i = 0; i < 4; ++i) {
        *(field + pos[i][0] + pos[i][1] *10 + 1*40*10) = '.';
    }

    //Überprüfe, ob der Tetromino an die neue Stelle passt
    for (int i = 0; i < 4; ++i) {
        if(pos[i][0]+x_dif > 9 || pos[i][0]+x_dif < 0){
            check = 1;
        }
        if(pos[i][1]+y_dif > 19 || pos[i][1]+y_dif < 0){
            check = 1;
        }
    }

    //Wenn es nicht passt das x und y offset auf 0 setzten
    if (check == 1){
        x_dif = 0;
        y_dif = 0;
    }

    //Tetromino wieder in das Move Feld packen
    for (int i = 0; i < 4; ++i) {
        *(field + pos[i][0]+x_dif + (pos[i][1]+y_dif) *10 + 1*40*10) = '#';
    }

}
