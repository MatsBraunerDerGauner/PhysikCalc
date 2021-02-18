#ifndef UI_H
#define UI_H

// Headers from standard lib
#include<string.h>

// Header for KeyEvents
#include"keyEvent.h"
// Header for sturct of page
#include"page.h"

// things they are diffrent on unix and Win
#ifdef __unix__
// Curser for unix
#define curser "⇒"
// Enter enum for unix
#define ENTER '\n'
// Clear the screen for unix
#define CLEAR system("clear")
#else
// Curser for win
#define curser ">"
// Enter enum for win
#define ENTER 13
// Clear the screen for win
#define CLEAR system("cls")
#endif

// Keys for the movement in the menu
extern enum { down = 'n', up = 'r', enter = ENTER } key;

// width fo the ui
#define UI_WIDTH 15

// line for ui
#define UI_LINE \
    putchar('\r'); \
    for (int i = 0; i < UI_WIDTH; i++) \
        putchar('-'); \
    putchar('\n');

// End for ui menupoint
#define UI_END(x) \
    for (int i = 0; i < x; i++) \
        putchar(' '); \
    putchar('|'); \
    putchar('\n');


// Draw's the Menu when the Programm is Started
void drawMenu(void);

#endif
