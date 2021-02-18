#include"Include/ui.h"

// draw's the page and return the next page where is navigate
page_t *drawPage(page_t *page, _Bool isMainPage) {
    // The position of the Curser « ⇒ »
    int curserPos = 0;
    int subPagesCount = page->subPagesCount;


    while (1) {
        CLEAR;

        // title
        UI_LINE;
        printf("\r| - %s -", 
                page->title);
        UI_END(UI_WIDTH - 7 - strlen(page->title));

        // menu points
        for (int i = 0; i < subPagesCount; i++) {
            UI_LINE;
            printf("\r|%s %s",
                    (curserPos == i) ?curser :" ",
                    page->subPages[i]->title);
            char *tempStr = page->subPages[i]->title;
            UI_END(UI_WIDTH - 4 - strlen(tempStr));
        }

        // exit or back
        UI_LINE;
        printf("\r|%s %s",
                (curserPos == subPagesCount) \
                ?curser :" ", (isMainPage) ?"EXIT" :"BACK");
        UI_END(UI_WIDTH - 8);
        UI_LINE;

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
