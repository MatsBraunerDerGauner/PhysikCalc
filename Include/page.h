#ifndef PAGE_H
#define PAGE_H

#include<stdlib.h>
#include<stdarg.h>

typedef struct page_t {
    char *title;
    int subPagesCount;
    struct page_t *superPage;
    struct page_t **subPages;
} page_t;

/* adds the sub Pages to their suuperPage
 * superPages are (page_t *) */
void addSubPages(page_t *superPage, int subPagesCount, ...);

// create page and return a pointer of the new page
page_t *createPage(char *title);

#endif
