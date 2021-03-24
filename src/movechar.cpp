/* movechar.cpp
   Mueve un caracter por la pantalla desde el teclado.
   Plataforma Windows */

#include <conio.h>
#include <stdio.h>
#include "keys.h"

#define WIDTH_SCREEN 80
#define HEIGHT_SCREEN 25
#define CHARACTER 66

int main (void) {
    char key;
    int col = WIDTH_SCREEN / 2;
    int row = HEIGHT_SCREEN /2;
    int coldel = col;
    int rowdel = row;

    clrscr ();
    do {

        gotoxy (col, row);
        printf ("%c", CHARACTER);

	key = getch ();

	switch (key) {
	    case UP_KEY: if (--row < 0) row = HEIGHT_SCREEN - 1;
	    break;
	    case DOWN_KEY: if (++row == HEIGHT_SCREEN - 1) row = 0;
	    break;
	    case LEFT_KEY: if (--col < 0) col = WIDTH_SCREEN - 1;
	    break;
	    case RIGHT_KEY: if (++col == WIDTH_SCREEN - 1) col = 0;
	    break;
	}

	gotoxy (coldel, rowdel);
	printf (" ");
	coldel = col;
	rowdel = row;


    } while (key != ESC_KEY);

    return 0;
}
