#include <dbg.h>
#include <list_sorts.h>

int List_bubble_sort(List* list, List_compare cmp) {

    if(list->count < 2) {
        return 0;
    }

    //int count = List_count(list);
    int hasSwapped = FALSE;
    //int i = 0;
    //int diff;

    //ListNode* current;
    //ListNode* next;

    // while hasSwapped == TRUE
    // But at least one pass required
    do {
        hasSwapped = FALSE;
        
        LIST_FOREACH(list, first, next, cur) {
            if(cur->next) {
                if(cmp(cur->value, cur->next->value) > 0) {
                    List_swap(list, cur, cur->next);
                    hasSwapped = TRUE;
                }
            }
        }
        
        /*
        current = list->first;
        next = current->next;
        for(i = 0; i < count - 1; i++) {
            diff = cmp((char*)current->value, (char*)next->value);
            if(diff > 0) {
                // Swap elements
                List_swap(list, current, next);
                hasSwapped = TRUE;
            }
            // Otherwise leave alone
            
            current = next;
            next = next->next;
        }
        */
    } while(hasSwapped == TRUE);
    
    return 0;
}

List* merge(List* left, List* right, List_compare cmp) {
    List* res = List_create();

    while(left->count > 0 && right->count > 0) {
        if(cmp(List_first(left), List_first(right)) < 0) {
            List_push(res, List_shift(left));
        } else {
            List_push(res, List_shift(right));
        }
    }

    while(left->count > 0) {
        List_push(res, List_shift(left));
    }
    while(right->count > 0) {
        List_push(res, List_shift(right));
    }
    return res;
}

List* List_merge_sort(List* list, List_compare cmp) {
    if(list->count <= 1) {
        return list;
    }

    List* right = List_create();
    List* left = List_create();
    int i = 0;

    LIST_FOREACH(list, first, next, cur) {
        if(i % 2 == 0) {
            List_push(left, cur);
        } else {
            List_push(right, cur);
        }
        i += 1;
    }
    
    left = List_merge_sort(left, cmp);
    right = List_merge_sort(right, cmp);

    return merge(left, right, cmp);
}
