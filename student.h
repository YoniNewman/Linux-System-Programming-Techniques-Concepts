#define NAME_LENGTH 300
#define ADDRESS_LENGTH 300 
#define ID_LENGTH  10

typedef unsigned int u_int;

typedef struct Student{
    char *name;
    char *address;
    u_int  id;
    u_int age;
    u_int GPA;
}student_t;

typedef enum{
    STUDENT_ERROR = -1,
    STUDENT_SUCCESS
}student_e;


void *CreateStudentByUserInput();
void* CreateStudent(char *name,char *address, u_int id,u_int age,u_int gpa);
void PrintStudent(void *_studentobj);
void DeleteStudent(void *_studentobj);
int student_comparator (void *_studentobj1, void *_studentobj2);