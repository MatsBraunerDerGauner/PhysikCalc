#include"Include/ui.h"

static void drawRechnen(void) {
    CLEAR;
    printf("RechnenPage");
    getch();
}

static void drawFormeln() {
    CLEAR;
    printf("FormelnPage");
    getch();
}

void drawMenu(void) {
    // The position of the Curser « ⇒ »
    int curserPos = 0;
    // Max fo menu points
    const int CURSER_POS_MAX = 3;

    while (1) {
        CLEAR;
        char *curser = "⇒";
        printf("\r------------\n\
                \r| - Menu - |\n\
                \r------------\n\
                \r|%s Rechnen |\n\
                \r-------------\n\
                \r|%s Formeln |\n\
                \r------------\n\
                \r|%s Exit    |\n\
                \r------------\n",
                (curserPos == 0) ?curser :" ",
                (curserPos == 1) ?curser :" ",
                (curserPos == 2) ?curser :" ");

        // Key abfrage
        int c;
        do {
            c = getch();
        } while (c != down && c != up && c != enter);
        
        // Key pressed processing
        if (c == down) {
            if (curserPos != CURSER_POS_MAX - 1) 
                curserPos++;
            continue; 
        }

        if (c == up) { 
            if (curserPos != 0) 
                curserPos--; 
            continue;
        }

        if (c == enter) {
            switch (curserPos) {
                case 0: drawRechnen(); break;
                case 1: drawFormeln(); break;
                case 2: exit(EXIT_FAILURE); break;
                default: break;
            }
        }
    }
}
