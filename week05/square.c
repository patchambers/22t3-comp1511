// Demonstrating how variables get passed into functions
// Pat Chambers (z5264081), 13/10/22

#include <stdio.h>

int square(int x);

int main(void) {

    int input;
    printf("Enter a value: ");
    scanf("%d", &input);

    printf("value before square: %d\n", input);

    // Pass the inputted value into the square function, storing its return
    // value in a variable
    int result = square(input);

    printf("value after square: %d\n", result);

    return 0;
}

// Returns the square of 'x'
int square(int x) {
    x = x * x;
    return x;
}
