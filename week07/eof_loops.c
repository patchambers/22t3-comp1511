#include <stdio.h>

#define MAX_LETTERS 100

int main (void) {

    /*
    // Scanning in character by character using scanf
    char my_var;
    while (scanf(" %c", &my_var) == 1) {
        printf("Input: %c\n", my_var);
    }
    */
    
    // Scanning in line by line using fgets
    char my_string[MAX_LETTERS];
    while (fgets(my_string, MAX_LETTERS, stdin) != NULL) {
        printf("Input: %s\n", my_string);
    }
    return 0;
}

