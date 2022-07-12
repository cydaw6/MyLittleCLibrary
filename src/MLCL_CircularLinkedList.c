/*
 *   This file is part of the MLCL Library.
 *   Antoine Bastos 2022
 *
 *   This Library is free software under the terms of
 *   the MIT license.
 */

#include "../include/MLCL_CircularLinkedList.h"
#include <stdio.h>

CircularLinkedList new_circular_linked_list(const void * data, TypeDescriptor * type_descriptor){
    LinkedListDescriptor * lld;
    CircularLinkedList cll;
    if(!type_descriptor) return NULL;
    lld = linked_list_descriptor();
    lld->type_descriptor = type_descriptor;
    cll = linked_list_builder(data, lld);
    if(!cll) return NULL;
    /* Circular */
    cll->next = cll;
    /* Override affected function */
    cll->d->prepend = circular_linked_list_prepend;
    cll->d->append = circular_linked_list_append;
    cll->d->shift = circular_linked_list_shift;
    cll->d->search = circular_linked_list_search;
    cll->d->pop = circular_linked_list_pop;
    cll->d->free = circular_linked_list_free;
    cll->d->print = circular_linked_list_print;
    return cll;
}

CircularLinkedList circular_linked_list_search(CircularLinkedList ll, const void * data){
    CircularLinkedList tmp;
    if(!ll) return 0;
    if(!ll->d->type_descriptor->cmp(ll->data, data))
        return ll;
    tmp = ll->next;
    while(tmp->next != ll){
        if(!tmp->d->type_descriptor->cmp(tmp->data, data))
            return tmp;
        tmp = tmp->next;
    }
    return NULL;
}

int circular_linked_list_prepend(CircularLinkedList * ll, const void * data){
    LinkedCell * cell;
    void * data_tmp;
    if(!*ll)
        return 0;
    if(!(cell = linked_list_builder(data, (*ll)->d)))
        return 0;
    /*
      We have to switch the data of the cells
      because we don't want to mess with the pointer.
      As the last cell, from the point of view of the head, which we can't reach,
      still points to the head's address.
     */
    /* Add allocated cell next to the head */
    cell->next = (*ll)->next;
    (*ll)->next = cell;
    /* Switch data */
    data_tmp = cell->data;
    cell->data = (*ll)->data;
    (*ll)->data = data_tmp;
    (*ll)->d->length++;
    return 1;
}

int circular_linked_list_append(CircularLinkedList * cll, const void * data){
    LinkedCell * cell;
    LinkedCell * tmp;
    if(!*cll) return 0;
    tmp = (*cll)->next;
    while(tmp->next != *cll)
        tmp = tmp->next;
    if(!(cell = linked_list_builder(data, (*cll)->d)))
        return 0;
    cell->next = tmp->next;
    tmp->next = cell;
    (*cll)->d->length++;
    return 1;
}

void * circular_linked_list_shift(CircularLinkedList * ll){
    LinkedCell * tmp;
    LinkedCell * tmp_2;
    void * data;
    if(!*ll) return NULL;
    data = (*ll)->data;
    tmp = *ll;
    tmp_2 = (*ll)->next;
    **ll = *tmp_2;
    tmp->d->length--;
    if(tmp->d->length == 0){
        linked_list_free_descriptor(&tmp->d);
        *ll = NULL;
    }
    free(tmp_2);
    return data;
}

void * circular_linked_list_pop(CircularLinkedList * cll){
    LinkedCell * tmp;
    LinkedCell * tmp_2;
    void * data;
    if(!*cll) return NULL;
    tmp = (*cll)->next;
    if(tmp != *cll){
        /*
          1->2->3->4 ..->1
          we want to get the 3 to make it point to 1 and free the 4
         */
        while(tmp->next->next != *cll)
            tmp = tmp->next;
        tmp_2 = tmp->next;
        tmp->next = tmp->next->next;
    }else{
        tmp_2 = tmp;
    }
    data = tmp_2->data;
    tmp_2->next = NULL;
    tmp->d->length--;
    if(tmp->d->length == 0){
        linked_list_free_descriptor(&tmp->d);
        *cll = NULL;
    }
    free(tmp_2);
    return data;
}

void circular_linked_list_free(CircularLinkedList * cll){
    CircularLinkedList tmp;
    CircularLinkedList tmp_2;
    if(!*cll) return;
    tmp = (*cll)->next;
    while(tmp != *cll){
        tmp_2 = tmp->next;
        tmp->d->type_descriptor->free_data(&tmp->data);
        free(tmp);
        tmp = tmp_2;
    }
    (*cll)->d->type_descriptor->free_data(&(*cll)->data);
    linked_list_free_descriptor(&(*cll)->d);
    free(*cll);
    *cll = NULL;
}

void circular_linked_list_print(CircularLinkedList cll){
    CircularLinkedList tmp;
    if(!cll) return;
    tmp = cll->next;
    cll->d->print_cell(cll);printf(", ");
    while(tmp != cll){
        tmp->d->print_cell(tmp);printf(", ");
        tmp = tmp->next;
    }
}
