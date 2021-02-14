#ifndef UI_H
#define UI_H

// Headers from standard lib
#include<stdio.h>
#include<stdlib.h>

// Header for KeyEvents
#include"keyEvent.h"

// Konstante to clear the terminal for Win and for unix
#ifdef __unix__
#define CLEAR system("clear")
#else
#define CLEAR system("cls")
#endif

// Keys for the movement in the menu
extern enum { down = 'n', up = 'r', enter = '\n' } key;

// Draw's the Rechnen menu point
static void drawRechnen(void);

// Draw's the Formeln menu point
static void drawFormeln(void);

// Draw's the Menu when the Programm is Started
void drawMenu(void);

#endif
