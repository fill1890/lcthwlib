#include <dllist.h>
#include <dbg.h>

List* List_create() {
    return calloc(1, sizeof(List));
}

void List_destroy(List* list) {
    LIST_FOREACH(list, first, next, cur) {
        if(cur->prev) {
            free(cur->prev);
        }
    }

    free(list->last);
    free(list);
}

void List_clear(List* list) {
    LIST_FOREACH(list, first, next, cur) {
        free(cur->value);
    }
}

void List_clear_destroy(List* list) {
    List_clear(list);
    List_destroy(list);
}

void List_push(List* list, void* value) {
    ListNode* node = calloc(1, sizeof(ListNode));
    check_mem(node);

    node->value = value;

    if(list->last == NULL) {
        list->first = node;
        list->last = node;
    } else {
        list->last->next = node;
        node->prev = list->last;
        list->last = node;
    }

    list->count++;

error:
    return;
}

void* List_pop(List* list) {
    ListNode* node = list->last;
    return node != NULL ? List_remove(list, node) : NULL;
}

void List_unshift(List* list, void* value) {
    ListNode* node = calloc(1, sizeof(ListNode));
    check_mem(node);

    node->value = value;

    if(list->first == NULL) {
        list->first = node;
        list->last = node;
    } else {
        node->next = list->first;
        list->first->prev = node;
        list->first = node;
    }

    list->count++;

error:
    return;
}

void* List_shift(List* list) {
    ListNode* node = list->first;
    return node != NULL ? List_remove(list, node) : NULL;
}

void* List_remove(List* list, ListNode* node) {
    void* result = NULL;

    check(list->first && list->last, "List is empty.");
    check(node, "node can't be NULL");

    if(node == list->first && node == list->last) {
        list->first = NULL;
        list->last = NULL;
    } else if(node == list->first) {
        list->first = node->next;
        check(list->first != NULL, "Invalid list, somehow got a first that is NULL.");
        list->first->prev = NULL;
    } else if(node == list->last) {
        list->last = node->prev;
        check(list->last != NULL, "Invalid list, somehow got a next that is NULL.");
        list->last->next = NULL;
    } else {
        ListNode* after = node->next;
        ListNode* before = node->prev;
        after->prev = before;
        before->next = after;
    }

    list->count--;
    result = node->value;
    free(node);

error:
    return result;
}

// Assumes node1 comes before node2
// This may be corrected at some point
// TODO: Improve testing for this, a lot
void List_swap(List* list, ListNode* node1, ListNode* node2) {
    //check(node1->next == node2->prev, "Non-consecutive swapping not yet implemented.");

    ListNode* temp = node1->next;
    
    if(node1->prev) {
        node1->prev->next = node2;
    }
    if(node2->next) {
        node2->next->prev = node1;
    }
    
    node1->next = node2->next;
    node2->prev = temp;
    node2->next = node1;
    node1->prev = node2;

    // TODO: Clean this up? Or leave it?
    int switchFirst = 0;
    int switchLast = 0;
    if(list->first == node1) {
        switchFirst = 2;
    } else if(list->last == node1) {
        switchLast = 2;
    }
    if(list->first == node2) {
        switchLast = 1;
    } else if(list->last == node2) {
        switchLast = 1;
    }
    if(switchFirst == 2) list->first = node2;
    if(switchFirst == 1) list->first = node1;
    if(switchLast == 2) list->last = node2;
    if(switchLast == 1) list->last = node1;
    
//error:
    return;
}

void List_print(List* list) {
    printf("[");
    LIST_FOREACH(list, first, next, cur) {
        printf("%s, ", (char*)cur->value);
    }
    printf("]\n");
}
