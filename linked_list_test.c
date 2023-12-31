#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include "linked_list.h"

#define NUMBER_OF_TEST ((int) 10)
#define INIT_LINKED_LIST_ENABLED ((bool) true)
#define APPEND_LINKED_LIST_ENABLED ((bool) true)
#define GET_LINKED_LIST_LAST_ELEMENT_ENABLED ((bool) true)

bool btest_init_linked_list(int data);
bool etest_init_linked_list(void);
bool btest_append_linked_list(linked_list list, int data, node last_node);
bool etest_append_linked_list(void);
bool btest_get_linked_list_last_element(linked_list start, node last_element, int value);
bool etest_get_linked_list_last_element(void);

int main(void){
    srand(time(NULL));
    if(INIT_LINKED_LIST_ENABLED){
        bool test_init_linked_list = etest_init_linked_list();
        printf("init_linked_list : %s\n", test_init_linked_list ? "ok" : "An error occured");
    }
    if(APPEND_LINKED_LIST_ENABLED){
        bool test_append_linked_list = etest_append_linked_list();
        printf("append_linked_list : %s\n", test_append_linked_list ? "ok" : "An error occured");
    }
    if(GET_LINKED_LIST_LAST_ELEMENT_ENABLED){
        bool test_get_linked_list_last_element = etest_get_linked_list_last_element();
        printf("get_linked_list_last_element : %s\n", test_get_linked_list_last_element ? "ok": "An error occured");
    }
    return 0;
}

/// @brief one test of the function init_linked_list, checks if the data is written and if the next pointer is set to NULL
/// @param data 
/// @return true if it functionned false otherwise
bool btest_init_linked_list(int data){
    linked_list list = init_linked_list(data);
    return (list->data == data) && (list->next == NULL);
}

/// @brief multiple tests of init_linked_list, calls btest_init_linked_list with random values
/// @return true if the function works
bool etest_init_linked_list(void){
    bool ok = true;
    for(int i = 0; i < NUMBER_OF_TEST; i++){
        int value = rand();
        bool test = btest_init_linked_list(rand());
        if(! test){
            printf("Fail of the function init_linked_list with value %d", value);
        }
        ok = ok && test;
    }
    return ok;
}

/// @brief base test for the function append_linked_list, given the last node it checks if the value is added after and the next pointer modified
/// @param list 
/// @param data 
/// @param last_node a pointer to the last node of the list (before it is appended)
/// @return true if the list got successfully appended
bool btest_append_linked_list(linked_list list, int data, node last_node){
    if(last_node->next != NULL){
        return false;
    }
    append_linked_list(list, data);
    if(last_node->next == NULL){
        return false;
    }
    if(last_node->next->data != data){
        return false;
    }
    return true;
}

/// @brief wrapper for btest_append_linked_list create the list, keep track of the last node and gives the values to add
/// @return true if all the values got correctly appended
bool etest_append_linked_list(void){
    linked_list list = init_linked_list(0);
    node current = list;
    bool ok = true;
    for(int i = 0; i < NUMBER_OF_TEST; i++){
        int value = rand();
        ok = btest_append_linked_list(list, value, current);
        if( ! ok){
            printf("Fail of the function append_linked_list on the test #%d with the value %d", i, value);
            if(current->next != NULL){
                current = current->next;
            }
        }
        else{
            current = current->next;
        }
    }
    return ok;
}

/// @brief base test for get_linked_list_last_element, checks for the address, the content and if there is no next element
/// @param start the first node of the list
/// @param last_element a pointer to the last element
/// @param value the value of the last element
/// @return true if it functionned as intended
bool btest_get_linked_list_last_element(linked_list start, node last_element, int value){
    node function_last = get_linked_list_last_element(start);
    return function_last == last_element && function_last->data == value && function_last->next == NULL;
}

/// @brief wrapper for btest_get_linked_list_last_element, provides the values add elements to the list and keep track of the last element
/// @return true if all test passed
bool etest_get_linked_list_last_element(void){
    int value = rand();
    bool ok = true;
    linked_list list = init_linked_list(value);
    node last = list;
    for(int i = 0; i < NUMBER_OF_TEST; ++i){
        ok = btest_get_linked_list_last_element(list, last, value);
        if(! ok){
            printf("Fail of the function get_linked_list_last_element on the test #%d with the value %d", i, value);
            return false;
        }
        value = rand();
        append_linked_list(list, value);
        if(last->next == NULL){
            printf("Something wrong happened with append linked list");
            return false;
        }
        last = last->next;
    }
    return ok;
}