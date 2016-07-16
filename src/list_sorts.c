#include <dbg.h>
#include <list_sorts.h>

int List_bubble_sort(List* words, List_compare cmp) {
    
    int count = List_count(words);
    int hasSwapped = FALSE;
    int i = 0;
    int diff;

    ListNode* current = words->first;
    ListNode* next = current->next;

    // while hasSwapped == TRUE
    // But at least one pass required
    do {
        hasSwapped = FALSE;
        for(i = 0; i < count; i++) {
            diff = cmp((char*)current->value, (char*)next->value);
            if(diff > 0) {
                // Swap elements
                List_swap(current, next);
                hasSwapped = TRUE;
            }
            // Otherwise leave alone
            
            current = next;
            next = next->next;
        }
    } while(hasSwapped == TRUE);
    
    return 0;
}

int List_merge_sort(List* words, List_compare cmp) {
    return 1;
}
