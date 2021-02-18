#include"Include/page.h"
#include<stdio.h>

void addSubPages(page_t *superPage, int subPagesCount, ...) {
    va_list ptr;

    va_start(ptr, subPagesCount);

    superPage->subPages = calloc(subPagesCount, sizeof(page_t *));

    superPage->subPagesCount = subPagesCount;

    for (int i = 0; i < subPagesCount; i++) {
        superPage->subPages[i] = va_arg(ptr, page_t *);
        superPage->subPages[i]->superPage = superPage;
    }

    va_end(ptr);
}

page_t *createPage(char *title) {
    page_t *newPage = malloc(sizeof(page_t));

    newPage->title = title;
    newPage->subPagesCount = 0;
    newPage->superPage = NULL;
    newPage->subPages = NULL;

    return newPage;
}
