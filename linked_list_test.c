#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include "linked_list.h"

#define NUMBER_OF_TEST ((int) 10)

bool btest_init_linked_list(int data);
bool etest_init_linked_list(void);
bool btest_append_linked_list(linked_list list, int data, node last_node);
bool etest_append_linked_list(void);


int main(void){
    srand(time(NULL));
    bool test_init_linked_list = etest_init_linked_list();
    printf("init_linked_list : %s\n", test_init_linked_list ? "ok" : "An error occured");
    if(! test_init_linked_list){
        return 1;
    }

    bool test_append_linked_list = etest_append_linked_list();
    printf("append_linked_list : %s\n", test_append_linked_list ? "ok" : "An error occured");
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