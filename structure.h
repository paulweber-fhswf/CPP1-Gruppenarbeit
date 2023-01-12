//
// Created by Paul Weber on 08.01.23.
//

#ifndef TETRIS_STRUCTURE_H
#define TETRIS_STRUCTURE_H

//Struktur die alles für einen Tetromino beinhaltet
typedef struct{
    Vector2 Tetromino[4]; //4* Vektor2 um die 4 Blöcke des Tetrominos zu speichern
    Vector2 Rotation_Point; //Koordinaten des Rotation Points
    int type; //Typennummer des Tetrominos
}tetromino;


#endif //TETRIS_STRUCTURE_H

