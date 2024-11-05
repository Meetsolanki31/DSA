#include <stdio.h>
#include <string.h>

// A structure is a user-defined data type that
// allows us to create various members under a single name.
struct student // 
{
    char name[50];
    int age;
    int grade;
};

int main()
{
    // Here we have made structure variable so that we can access member of structure
    struct student s;
    struct student *ptr; // pointer variable
    ptr = &s;
     // we have stored the address of s variable into pointer variablr ptr 
    //  so that we can access all the members of structure through the pointer variable

    // to access all the member of structure, "->" operator is used.
    strcpy(ptr->name, "Meet");
    ptr->age = 22;
    ptr->grade = 90;

    // we can also access structure data member through like below:- 
    // (*ptr).age = 23; 
    // (*ptr).grade = 95; 

    printf("Student Details :\n");
    printf("Name :%s \n",ptr->name); // %s is for printing string
    printf("Age :%d \n",ptr->age);
    printf("Grader :%d \n",ptr->grade);

    return 0;
}
