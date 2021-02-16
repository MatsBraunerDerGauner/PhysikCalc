#ifndef UI_H
#define UI_H

// Headers from standard lib
#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>

// Header for KeyEvents
#include"keyEvent.h"

// Konstante to clear the terminal for Win and for unix
#ifdef __unix__
#define CLEAR system("clear")
#else
#define CLEAR system("cls")
#endif

// check dynamic store
#define check(x) \
    if (x == NULL) { \
        printf("dynamic store faild in line %d", __LINE__); \
        exit(EXIT_FAILURE); \
    }

// char for the Curser
#define curser "⇒"

// menupoints char buffer max
#define BUFFMAX 50

// struct for page
typedef struct page_t {
    int menuPointCount;
    char *title;
    char **menuPoints;
    struct page_t *pre;
    struct page_t *next;
} page_t;

extern page_t *pageList;

static page_t *createPage_t(int menuPointCount, ...);

// Keys for the movement in the menu
extern enum { down = 'n', up = 'r', enter = '\n' } key;

// Build's the Page about the page
static page_t *drawPage(page_t *page, _Bool isMainPage);

// Draw's the Menu when the Programm is Started
void drawMenu(void);

#endif
