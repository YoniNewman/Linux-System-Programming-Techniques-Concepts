
typedef struct double_linked_list_node{
    struct double_linked_list_node *left,*right;
    void *data;
}dll_node;

typedef struct double_linked_list{
    struct double_linked_list_node *head;
}dll_t;


dll_t *create_dll();
void dll_append(dll_t* list, void *data);
void print_dll(dll_t* list);
void dll_delete(dll_t* list);
void* get_app_from_dll(void* list_root);
int is_dll_empty(dll_t *list);
int remove_data_from_dll_by_data_ptr(dll_t *list, void *data);
void* list_iterator (void *_listObj);
void list_print(void* list, void (*print_func)(void*));
