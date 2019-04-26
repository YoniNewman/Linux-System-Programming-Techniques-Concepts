#include <stdio.h>
#include <string.h>
#include "dll.h"
#include "student.h"

/**********MACROS**********/
#define INPUT_LENGTH 7

/**************************/

/**********GLOBAL VARIABLES**********/
dll_t *list = NULL;
dll_t *list2 = NULL;

/************************************/


/**********Functions Declarations**********/
extern int
diff (void *root1,    /*pointer to first node of data struture 1*/
        void *root2,    /*pointer to first node of data struture 2*/
        void *(*iterator)(void *), /*Iterator function callback*/
        int (*comparator)(void *, void *),
        void *(*get_app_data)(void *)); /*Comparison function callback*/


void MainMenuCase1Handler();
void MainMenuCase2Handler();
void MainMenuCase3Handler();


void MainMenuCase9Handler();


/****************************/

void clear_buffer(){
    int c;
    while(c = getchar() != '\n' && c != EOF);
}

void PrintMenu(){
    printf("0. Exit\n");
    printf("1. Add student to doubly linked list by user.\n");
    printf("2. Add student to doubly linked list.\n");    
    printf("3. Compare 2 data structures.\n");    
    
    printf("9. Print linked list\n");
}

void MainMenu(){
    int quit = 0;
    int input = 0;
    dll_node *student_node = NULL;
    dll_node *temp_node = NULL;
    
    do{
        PrintMenu();
        printf("Please enter you're choice:\n");
        scanf("%d", &input);
        clear_buffer();
        switch(input){
            case 0:
                quit=1;
                break;
            case 1:{
                MainMenuCase1Handler();
                break;
                }//case 1
            case 2:{
                MainMenuCase2Handler();
                break;
                }//case 2
            case 3:{
                MainMenuCase3Handler();
                break;
                }//case 2
            case 9:{
                MainMenuCase9Handler();
                break;
            }//case 9
            default:
                break;
        }//switch case

    }while(!quit);
    student_node = list;
    while(student_node){
        temp_node = student_node;
        DeleteStudent(temp_node->data);
        student_node = list_iterator((void*)student_node);
    }
}

void MainMenuCase1Handler(){
    int quit_case1 = 1;
    do{
        void *student = CreateStudentByUserInput();
        if(student)
            dll_append(list,student);
            printf("To stop insert press 0.\n");
            scanf("%d",&quit_case1);
            clear_buffer();
   }while(quit_case1);    
}

void MainMenuCase2Handler(){
    void *student1 = CreateStudent("Yoni Newman", "Moshe Hess 17B Rehovot",123123,29,81);
    void *student2 = CreateStudent("Almog Zaafran", "Shlomo Hameleh 13 Beer Sheva",3312312,26,95);
    void *student3 = CreateStudent("Itamar Newman", "Rabin Square 6 Tel Aviv",111111,29,84);
    void *student4 = CreateStudent("Cable", "Shlomo Hameleh 3 Beer Sheva",999999,28,81);
    void *student5 = CreateStudent("Liron Vaknin", "Somewhere in Tel Aviv",888888,28,81);
    dll_append(list,student1);
    dll_append(list,student2);
    dll_append(list,student3);
    dll_append(list,student4);
    dll_append(list,student5);

    // void *student1_2 = CreateStudent("Yoni Newman", "Moshe Hess 17B Rehovot",123123,29,81);
    // void *student2_2 = CreateStudent("Almog Zaafran", "Shlomo Hameleh 13 Beer Sheva",312312,26,95);
    // void *student3_2 = CreateStudent("Itamar Newman", "Rabin Square 6 Tel Aviv",222222,29,84);
    // void *student4_2 = CreateStudent("Cable", "Shlomo Hameleh 3 Beer Sheva",9999999,28,81);
    // void *student5_2 = CreateStudent("Liron Vaknin", "Somewhere in Tel Aviv",888888,28,81);
    void *student1_2 = CreateStudent("Yoni Newman", "Moshe Hess 17B Rehovot",123123,29,81);
    void *student2_2 = CreateStudent("Almog Zaafran", "Shlomo Hameleh 13 Beer Sheva",3312312,26,95);
    void *student3_2 = CreateStudent("Itamar Newman", "Rabin Square 6 Tel Aviv",111111,29,84);
    void *student4_2 = CreateStudent("Cable", "Shlomo Hameleh 3 Beer Sheva",999999,28,81);
    void *student5_2 = CreateStudent("Liron Vaknin", "Somewhere in Tel Aviv",888888,28,81);
    dll_append(list2,student1_2);
    dll_append(list2,student2_2);
    dll_append(list2,student3_2);
    dll_append(list2,student4_2);
    dll_append(list2,student5_2);
}

void MainMenuCase3Handler(){
   if(diff((void*)list->head, (void*)list2->head,
            list_iterator, student_comparator,
             get_app_from_dll))

        printf("Both lists ARENT clones!\n");
    else
     printf("Both lists are clones!\n");
}

void MainMenuCase9Handler(){
    printf("list1:\n");
    list_print((void*)list, PrintStudent);
    printf("list2:\n");
    list_print((void*)list2, PrintStudent);
}

void main(){
    list = create_dll();
    list2 = create_dll();
    MainMenu();
}



