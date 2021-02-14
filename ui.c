#include"Include/ui.h"

#ifdef __unix__
#define CLEAR system("clear")
#else
#define CLEAR system("cls")
#endif

enum { down = 'n', up = 'r', enter = ' ' } key;

void drawFormeln() {
    CLEAR;
    printf("Test");
    int key = getchar();
}

void drawMenu() {
    int curserPos = 0;

    while (1) {
        CLEAR;
        char *curser = "⇒";
        printf("\r------------\n\
                \r|   Menu   |\n\
                \r------------\n\
                \r|%s Formeln |\n\
                \r------------\n\
                \r|%s Exit    |\n\
                \r------------\n",
                (curserPos == 0) ?curser :" ",
                (curserPos == 1) ?curser :" ");
        char key;
        scanf("%c", &key);

        switch (key) {
            case down: curserPos++; break;
            case up: curserPos--; break;
            
            default:
                switch (curserPos) {
                    case 0: drawFormeln(); break;
                    //case 1: exit(0); break;
                }
                break;
        }
    }
}
