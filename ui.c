#include"Include/ui.h"

void readRestOfContentPage(FILE *contentPage) {
    if (contentPage == NULL) {
        putchar('\n');
        return;
    }

    for (int i = 0; i < UI_WIDTH; i++) {
        putchar(' ');
    }

    int c;
    while ((c = getc(contentPage)) != EOF) {
        putc(c, stdout);
        if (c == '\n') {
            for (int i = 0; i < UI_WIDTH; i++) {
                putchar(' ');
            }
        }
    }
    putchar('\n');
}


void readLineOfContentPage(FILE *contentPage){
    if (contentPage == NULL) {
        putchar('\n');
        return;
    }
    int c;

    while ((c = getc(contentPage)) != '\n') {
        if (c == EOF)
            break;
        putc(c, stdout);
    }
    putchar('\n');
}

// draw's the page and return the next page where is navigate
page_t *drawPage(page_t *page, _Bool isMainPage) {
    // The position of the Curser « ⇒ »
    int curserPos = 0;
    int subPagesCount = page->subPagesCount;

    

    while (1) {
        CLEAR;

        char path[50] = "./ContentPages/";
        strcat(path, page->title);
        
        
        FILE *contentPage = fopen(path, "r");

        // title
        UI_LINE;
        readLineOfContentPage(contentPage);
        printf("\r| - %s -", 
                page->title);
        UI_END(UI_WIDTH - 7 - strlen(page->title));
        readLineOfContentPage(contentPage);

        // menu points
        for (int i = 0; i < subPagesCount; i++) {
            UI_LINE;
            readLineOfContentPage(contentPage);
            printf("\r|%s %s",
                    (curserPos == i) ?curser :" ",
                    page->subPages[i]->title);
            char *tempStr = page->subPages[i]->title;
            UI_END(UI_WIDTH - 4 - strlen(tempStr));
            readLineOfContentPage(contentPage);
        }

        // exit or back
        UI_LINE;
        readLineOfContentPage(contentPage);
        printf("\r|%s %s",
                (curserPos == subPagesCount) \
                ?curser :" ", (isMainPage) ?"EXIT" :"BACK");
        UI_END(UI_WIDTH - 8);
        readLineOfContentPage(contentPage);
        UI_LINE;
        readLineOfContentPage(contentPage);

        readRestOfContentPage(contentPage);
        printf("test");
        if (contentPage != NULL)
            fclose(contentPage);

        // Key abfrage
        int c;
        do {
            c = getch();
        } while (c != down && c != up && c != enter);

        // Key pressed processing
        if (c == down) {
            if (curserPos != subPagesCount) 
                curserPos++;
            continue; 
        }

        if (c == up) { 
            if (curserPos != 0) 
                curserPos--; 
            continue;
        }

        if (c == enter) {
            if (curserPos == subPagesCount) {
                if (isMainPage) {
                    exit(EXIT_FAILURE);
                } else { 
                    return page->superPage;
                }
            }
            return page->subPages[curserPos];
        }
    }
    return NULL; 
}

void drawMenu(void) {
    page_t *mainPage = createPage("Menu");
    page_t *formelnPage = createPage("Formeln");
    page_t *rechnenPage = createPage("Rechnen");

    addSubPages(mainPage, 2, formelnPage, rechnenPage);

    page_t *currenPage = mainPage;
    _Bool isMainPage;
    while (1) {
        if (currenPage->superPage == NULL)
            isMainPage = 1;
        else
            isMainPage = 0;
        
        currenPage = drawPage(currenPage, isMainPage);
    }
}
