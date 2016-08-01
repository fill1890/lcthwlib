#ifndef _Stack_h
#define _Stack_h

#include <dllist.h>

typedef List Stack;

#define Stack_create(A) List_create(A)

#define Stack_destroy(A) List_destroy(A)

#define Stack_push(A, V) List_push(A, V)

#define Stack_peek(A) List_last(A)

#define Stack_count(A) List_count(A)

#define Stack_pop(A) List_pop(A)

#define STACK_FOREACH(L, V) LIST_FOREACH(L, first, next, V)

#endif
