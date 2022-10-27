// Using struct pointers to swap numbers in 2 struct person's
// Patrick Chambers (z5264081), 27/10/22

#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

struct person {
    char name[MAX_LEN];
    int num;
};

void swap_numbers(struct person *member1, struct person *member2);

int main(void) {

    // Create 2 people
    struct person person1;
    strcpy(person1.name, "Sasha");
    person1.num = 1;
    struct person person2;
    strcpy(person2.name, "Jake");
    person2.num = 2;

    // Print numbers
    printf("%s's Number: %d\n", person1.name, person1.num);
    printf("%s's Number: %d\n", person2.name, person2.num);

    //struct person *person_1_pointer = &person1;
    // Swap Numbers
    swap_numbers(&person1, &person2);

    // Print numbers again
    printf("%s's Number: %d\n", person1.name, person1.num);
    printf("%s's Number: %d\n", person2.name, person2.num);

    return 0;
}

// Swaps the numbers of each struct
void swap_numbers(struct person *member1, struct person *member2) {
    int temp_num = (*member1).num;
    // (*member1).num is equivalent to member1->num
    member1->num = member2->num;
    member2->num = temp_num;
}
