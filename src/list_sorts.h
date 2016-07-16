#ifndef _list_sorts_h
#define _list_sorts_h

#include <list.h>

typedef int (*List_compare)(const char* a, const char* b);

int List_bubble_sort(List* words, List_compare cmp);
int List_merge_sort(List* words, List_compare cmp);

#endif

#ifndef TRUE
#define TRUE 1
#define FALSE 0
#endif
