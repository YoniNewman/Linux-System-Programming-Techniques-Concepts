#include "dll.h"
#include <stdlib.h>

int is_dll_empty(dll_t *list){
    dll_node *node = list->head;
    if(!node->data)
        return 0;
    else
        return -1;       
}


int remove_data_from_dll_by_data_ptr(dll_t *list, void *data){
    dll_node *node = list->head, *temp_node = NULL, *curr_node = NULL;

    if(!is_dll_empty(list))
        return -1;
    temp_node = list->head;
    curr_node = list->head;
    if(curr_node->data==data){
        temp_node = curr_node;
        node = curr_node->right;
        node->left = NULL;
        free(temp_node);
    }
    else{
        while(curr_node->data != data){
            if(curr_node->right->data == data){
                temp_node = curr_node->right;
                break;
            }
            curr_node = curr_node->right;
        }
        curr_node->right = curr_node->right->right;
        curr_node->right->right->left = curr_node;
        free(temp_node);
    }
    return 0;
}