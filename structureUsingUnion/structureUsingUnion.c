#include <stdio.h>
#include <string.h>

// Define a union
union Data {
    int intValue;
    float floatValue;
    char str[20];
};

int main() {
    // Declare a variable of type union Data
    union Data data;

    // Assign an integer to intValue
    data.intValue = 5;
    printf("Integer: %d\n", data.intValue);

    // Assign a float to floatValue
    data.floatValue = 3.14;
    printf("Float: %.2f\n", data.floatValue);

    // Assign a string to str
    strcpy(data.str, "Hello");
    printf("String: %s\n", data.str);

    // Print all values to see how they overwrite each other
    printf("\nAfter assigning string:\n");
    printf("Integer: %d\n", data.intValue);    // May print garbage
    printf("Float: %.2f\n", data.floatValue);  // May print garbage
    printf("String: %s\n", data.str);

    return 0;
}
