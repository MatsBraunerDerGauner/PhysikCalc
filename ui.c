#include"Include/ui.h"


page_t *pageList = NULL;

static page_t *createPage_t(int menuPointCount, ...) {
    va_list ptr_va_list;

    va_start(ptr_va_list, menuPointCount);

    // page list 
    if (pageList == NULL) {
        pageList = malloc(sizeof(page_t));
        check(pageList);

        pageList->menuPointCount = menuPointCount;

        pageList->title = va_arg(ptr_va_list, char *);
        
        pageList->menuPoints = calloc(menuPointCount, sizeof(char *));  
        check(pageList->menuPoints);
        
        for (int i = 0; i < menuPointCount; i++) {
            *(pageList->menuPoints + i) = calloc(BUFFMAX, sizeof(char));
            check(*(pageList->menuPoints + i));
            *(pageList->menuPoints + i) = va_arg(ptr_va_list, char *);
        }

        pageList->pre = NULL;
        pageList->next = NULL;

        va_end(ptr_va_list);

        return pageList;
    } else {
        page_t *ptr, *ptrPre;
        ptr = pageList;

        do {
            ptrPre = ptr;
            ptr = ptr->next;
        } while (ptr != NULL);


        ptr = malloc(sizeof(page_t));
        check(ptr);

        ptr->menuPointCount = menuPointCount;

        ptr->title = va_arg(ptr_va_list, char *);
        
        ptr->menuPoints = calloc(menuPointCount, sizeof(char *));  
        check(ptr->menuPoints);
        
        for (int i = 0; i < menuPointCount; i++) {
            *(ptr->menuPoints + i) = calloc(BUFFMAX, sizeof(char));
            check(*(ptr->menuPoints + i));
            *(ptr->menuPoints + i) = va_arg(ptr_va_list, char *);
        }

        ptrPre->next = ptr;

        ptr->pre = ptrPre;
        ptr->next = NULL;

        va_end(ptr_va_list);

        return ptr;
    }

    return 0;
}

static page_t *drawPage(page_t *page, _Bool isMainPage) {
    // The position of the Curser « ⇒ »
    int curserPos = 0;

    while (1) {
        CLEAR;

        // title
        printf("\r-------------\n\
                \r| - %s -       |\n", 
                page->title);

        // menu points
        for (int i = 0; i < page->menuPointCount; i++) {
            printf("\r------------\n\
                    \r|%s %s       \n",
                    (curserPos == i) ?curser :" ",
                    *(page->menuPoints + i));
        }

        // exit or back
        printf("\r-----------\n\
                \r|%s %s    \n\
                \r-----------\n",
                (curserPos == page->menuPointCount) \
                ?curser :" ", (isMainPage) ?"EXIT" :"BACK");

        // Key abfrage
        int c;
        do {
            c = getch();
        } while (c != down && c != up && c != enter);

        // Key pressed processing
        if (c == down) {
            if (curserPos != page->menuPointCount) 
                curserPos++;
            continue; 
        }

        if (c == up) { 
            if (curserPos != 0) 
                curserPos--; 
            continue;
        }

        if (c == enter) {
            if (curserPos == page->menuPointCount) {
                if (isMainPage) {
                    exit(EXIT_FAILURE);
                } else { 
                    page_t *ptr = pageList;
                    while (ptr != NULL) {
                        for (int i = 0; i < ptr->menuPointCount; i++) {
                            if (*(ptr->menuPoints + i) == page->title)
                                return ptr;
                        }
                        ptr = ptr->next;
                    }
                }
            }

            page_t *ptr = pageList;
            while (ptr != NULL) {
                if (*(page->menuPoints + curserPos) == ptr->title)
                    return ptr;
                ptr = ptr->next;
            }
        }
    }
        return NULL; 
}

void drawMenu(void) {
    createPage_t(2, "Menu", 
            "Formeln", "Rechnen");
    createPage_t(2, "Formeln",
            "ADD", "Delete");

    page_t *ptr = pageList;
    while (1) {
        ptr = drawPage(ptr, (ptr->title == pageList->title) ?1 :0);
    }
}
