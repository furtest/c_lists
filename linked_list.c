#include <stdlib.h>
#include "linked_list.h"

/*
Custom linked list implementation.
If the list is empty the next pointer of the first element points to itself.
linked_list and node are the same type but the different names allows for better distinction between what they represent.
*/

/// @brief Initialize a linked list by creating the first node
/// @param data the data that will be contained by the first element
/// @return a pointer to the first node (linked_list type)
linked_list init_linked_list(int data){
    linked_list base = malloc(sizeof(struct linked_list_struct));
    if(base == NULL){
        return NULL;
    }
    base->data = data;
    base->next = NULL;
    return base;
}

/// @brief returns the last element of a linked list, returns NULL if the list is empty
/// @param start the first node of the list
/// @return a pointer to the last element or NULL
node get_linked_list_last_element(linked_list start){
    if(start->next == start){
        return NULL;
    }
    node current = start;
    while (current->next != NULL){
        current = current->next; 
    }
    return current;
}

/// @brief returns the second to last element of a linked list, if there is only one element returns this element, if there is no element returns NULL
/// @param start the first node of the list
/// @return a pointer to the second to last element or NULL
node get_linked_list_second_to_last_element(linked_list start){
    if(start->next == start){
        return NULL;
    }
    if(start->next == NULL){
        return start;
    }
    node current = start->next;
    node last = start;
    while (current->next != NULL){
        last = current;
        current = current->next;
    }
    return last;
}

node get_linked_list_nth_element(linked_list start, unsigned int index){
    if(start->next == start || index < 0){
        return NULL;
    }
    node current = start;
    for(int i = 0; i < index; ++i){
        if(current->next == NULL){
            return NULL;
        }
        current = current->next;
    }
    return current;
}

/// @brief add a new element at the end of a linked list
/// @param list pointer to the first element of the list
/// @param data the data to be added
/// @return -1 : error when mallocing the data; 0 all good
int append_linked_list(linked_list list, int data){
    node last = get_linked_list_last_element(list);
    node new = malloc(sizeof(struct linked_list_struct));
    if(new == NULL){
        return -1;
    }
    last->next = new;
    new->data = data;
    new->next = NULL;
    return 0;
}

/// @brief deletes the last element of the linked list and returns it, if an error occurs returns zero and sets the error pointer 
/// @param list the first element of the list
/// @return the value of the element popped
/// @exception 0 : No error all good
/// @exception 1 : The given list is empty
int pop_linked_list(linked_list list, int *error){
    node last = get_linked_list_last_element(list);
    if(last == NULL){
        if(error != NULL){
            *error = 1;
        }
        return 0;
    }
    node new_last = get_linked_list_second_to_last_element(list);
    int data = 0;
    if(new_last->next == NULL){
        data = last->data;
        last->data = 0; //So we don't keep data that is supposed to be removed
        last->next = last; //Nothing in the list anymore so we follow the specifications
    }
    else{
        data = last->data;
        free(last);
        new_last->next = NULL;
    }
    if(error != NULL){
        *error = 0;
    }
    return data;
}

int free_linked_list(linked_list start){
    if(start->next == NULL || start->next == start){
        free(start);
        return 0;
    }
    node current = start;
    node next = start->next;
    while(next->next != NULL){
        free(current);
        current = next;
        next = next->next;
    }
    free(current);
    free(next);
    return 0;
}

int insert_in_linked_list(linked_list list, int index, int value){
    return -1;
}