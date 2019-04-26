#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "student.h"

#define CHECK_ALLOCATE(ptr) if(ptr==NULL){\
                                printf("Allocate failed!\n");\
                                return NULL;}\


extern void clear_buffer();

void fix_str(char *str){
    int length = strlen(str);
    for(int i=0;i<length;i++){
        if(str[i]=='\n')
            str[i] = 0;
    }
}

char* allocate_str(char *str){
    char *res_str = NULL;
    int length = strlen(str);
    int i;
    res_str = (char*)malloc(sizeof(char)*(length+1));
    CHECK_ALLOCATE(res_str)
    strncpy(res_str, str, length);
    res_str[length] = 0;
    return res_str;
}

void *CreateStudentByUserInput(){
    char temp_name[NAME_LENGTH] = {0};
    char temp_addr[ADDRESS_LENGTH] = {0};
    u_int id,age,gpa;
    
    //insert name
    printf("Please enter a student's name:\n");
    fgets(temp_name,NAME_LENGTH,stdin);
    fix_str(temp_name);
    
    //insert address
    printf("Please enter a student's address:\n");
    fgets(temp_addr,NAME_LENGTH,stdin);
    fix_str(temp_addr);   

    //insert id
    printf("Please enter a student's ID:\n");
    scanf("%d", &id);
    clear_buffer();
    
    //insert age
    printf("Please enter a student's age:\n");
    scanf("%d",&age);    
    clear_buffer();
    
    //insert GPA
    printf("Please enter a student's GPA:\n");
    scanf("%d",&gpa);
    clear_buffer();
    return CreateStudent(temp_name, temp_addr, id, age, gpa);
}

void* CreateStudent(char *name,char *address, u_int id,u_int age,u_int gpa){
    student_t* stdnt = NULL;
    stdnt = (student_t*)malloc(sizeof(student_t));
    CHECK_ALLOCATE(stdnt)    
    stdnt->name = allocate_str(name);
    stdnt->address = allocate_str(address);
    stdnt->id = id;
    stdnt->age = age;
    stdnt->GPA = gpa;
    void *_studentobj = (void*)stdnt;
    return _studentobj;
}

void  PrintStudent(void *_studentobj){
    student_t *stdnt = (student_t*)_studentobj;    
    printf("\nName: %s\nID: %10d\nAddress: %s\nAge:%d\nGPA:%d\n",stdnt->name,
    stdnt->id,
    stdnt->address,
    stdnt->age,
    stdnt->GPA);
}

void DeleteStudent(void *_studentobj){
    student_t *stdnt = (student_t*)_studentobj;
    if(!stdnt)
        return;
    free(stdnt->name);
    free(stdnt->address);
    free(stdnt);
    _studentobj = NULL;
}

int student_comparator (void *_studentobj1, void *_studentobj2){
    student_t *stdnt1 = (student_t*)_studentobj1;
    student_t *stdnt2 = (student_t*)_studentobj2;
    if(strcmp(stdnt1->name,stdnt2->name) || strcmp(stdnt1->address,stdnt2->address) )
        return -1;
    if(stdnt1->age != stdnt2->age || stdnt1->id != stdnt2->id || stdnt1->GPA != stdnt2->GPA)
        return -1;
    return 0;
} 