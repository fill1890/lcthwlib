#include <darray_sorts.h>
#include <stdlib.h>

#ifdef __linux__
#include <bsd/stdlib.h>
#endif

int DArray_qsort(DArray* array, DArray_compare cmp) {
    qsort(array->contents, DArray_count(array), sizeof(void*), cmp);
    return 0;
}

int DArray_heapsort(DArray* array, DArray_compare cmp) {
    return heapsort(array->contents, DArray_count(array), sizeof(void*), cmp);
}

int DArray_mergesort(DArray* array, DArray_compare cmp) {
    return mergesort(array->contents, DArray_count(array), sizeof(void*), cmp);
}
