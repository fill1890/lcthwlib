#ifndef _Queue_h
#define _Queue_h

#include <dllist.h>

typedef List Queue;

#define Queue_create(A) List_create(A)

#define Queue_destroy(A) List_destroy(A)

#define Queue_send(A, V) List_unshift(A, V)

#define Queue_peek(A) List_first(A)

#define Queue_recv(A) List_pop(A)

#define Queue_count(A) List_count(A)

#define QUEUE_FOREACH(L, V) LIST_FOREACH(L, first, next, V)

#endif
