#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include "linked_list.h"

bool btest_init_linked_list(int data);
bool etest_init_linked_list(void);


int main(void){
    srand(time(NULL));
    printf("init_linked_list : %s\n", etest_init_linked_list() ? "ok" : "An error occured");
    return 0;
}

bool btest_init_linked_list(int data){
    linked_list list = init_linked_list(data);
    return list->data == data && list->next == NULL;
}

bool etest_init_linked_list(void){
    bool ok = true;
    for(int i = 0; i<10; i++){
        ok = ok && btest_init_linked_list(rand());
    }
    return ok;
}
