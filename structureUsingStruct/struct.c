#include <stdio.h>
#include <String.h>

struct Student
{
    char name[50];
    int age;
    float grade;
};
int main()
{
    struct Student s;

    strcpy(s.name, "Meet");
    s.age = 22;
    s.grade = 90;

    printf("Student Details :\n");
    printf("Name : %s\n", s.name);
    printf("Age : %d\n", s.age);
    printf("Grade : %d\n", s.grade);

    return 0;
} 
