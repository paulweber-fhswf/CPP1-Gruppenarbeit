gcc main.c -o game.exe -O2 -Wall -std=c17 -Wno-missing-braces -I include/ -L lib/  -lraylib -lopengl32 -lgdi32 -lwinmm
pause