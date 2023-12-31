#ifndef LINKED_LIST_HEADER
#define LINKED_LIST_HEADER

struct linked_list_struct
{
    int data;
    struct linked_list_struct *next; 
};

typedef struct linked_list_struct* linked_list; //Used to keep track of the first element
typedef struct linked_list_struct* node; //Used to point any node in the list

linked_list init_linked_list(int data);
int append_linked_list(linked_list list, int data);
node get_linked_list_last_element(linked_list start);
node get_linked_list_second_to_last_element(linked_list start);
int pop_linked_list(linked_list list, int *error);
int insert_in_linked_list(linked_list list, int index, int value);
node get_linked_list_nth_element(linked_list start, unsigned int index);


#endif