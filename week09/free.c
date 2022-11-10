// Demonstration of free and malloc use after free 
// Patrick Chambers (z5264081), 14/4/22

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *create_node(int data);

int main(void) {

    struct node *head = create_node(4);
    printf("Data: %d\n", head->data);

    // If we don't use free, we'll get a memory leak 
    // Check for memory leaks using 'dcc --leakcheck -o filename filename.c'
    // free(head);
    
    // If we print this data after freeing the data that head points at, 
    // we'll get a 'malloc use after free' error
    // printf("Data: %p\n", head->data);

    return 0;
}

// Returns a pointer to a struct node initialised with the data given
struct node *create_node(int data) {
    struct node *new = malloc(sizeof(struct node));
    new->data = data;
    new->next = NULL;
    return new;
}

