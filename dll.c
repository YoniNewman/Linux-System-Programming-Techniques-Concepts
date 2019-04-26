#include <stdlib.h>
#include <stdio.h>
#include "dll.h"

#define CHECK_ALLOCATE(ptr) if(ptr==NULL){\
                                printf("Allocate failed!\n");\
                                exit(1);}\


dll_t *create_dll(){
    dll_t *list = NULL;
    list = (dll_t*)malloc(sizeof(dll_t));
    if(!list){
        exit(1);
    }
    list->head = NULL;
    return list;
}

void dll_append(dll_t* list, void *data){
    
    //List hasnt been created!
    if(!list)
        list = create_dll();
    
    //Append the data to the head
    dll_node *new_node = (dll_node*)malloc(sizeof(dll_node));
    CHECK_ALLOCATE(new_node)
    new_node->data = data;
    new_node->right = NULL;
    if(!list->head){
        new_node->left = NULL; 
        list->head = new_node; 
    }
    else{
        dll_node *temp_node = list->head;
        while(temp_node->right)
            temp_node = temp_node->right;
        temp_node->right = new_node;
        temp_node->right->left = temp_node;
    }
}

void dll_delete(dll_t* list){
    dll_node *list_node= list->head;
    if(!list_node)
        return;
    dll_node* temp = list_node, *curr = list_node;
    while(curr){
        temp = curr;
        curr = curr->right;
        //free(temp->data);
        free(temp);
    }
}

void* get_app_from_dll(void* list_node){
   dll_node *node = (dll_node*)list_node;
   return (void*)node->data;
}

void list_print(void* list, void (*print_func)(void*)){
    dll_t *list_temp = (dll_t*)list;
    dll_node *node = list_temp->head;
    while(node){
        print_func(node->data);
        node = list_iterator(node);
    }
}

void* list_iterator (void *_listObj){
    dll_node *node = (dll_node*)_listObj;
    if(node->right)
        return node->right;
    else
        return NULL;
}