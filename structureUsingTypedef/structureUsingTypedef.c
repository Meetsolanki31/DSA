#include <stdio.h>
#include <string.h>

typedef struct
{
    char name[50];
    int age;
    int grade;

} student;
int main()
{
    student s;

    strcpy(s.name, "Meet Solanki");
    s.age = 22;
    s.grade = 90;

    printf("Student details :\n");
    printf("Name : %s\n", s.name);
    printf("Age : %d\n", s.age);
    printf("Grade : %d\n", s.grade);
    return 0;
}
