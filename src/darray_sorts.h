#ifndef _DArray_sorts_h
#define _DArray_sorts_h

#include <darray.h>

typedef int (*DArray_compare)(const void* a, const void* b);

int DArray_qsort(DArray* array, DArray_compare cmp);

int DArray_heapsort(DArray* array, DArray_compare cmp);

int DArray_mergesort(DArray* array, DArray_compare cmp);

#endif
