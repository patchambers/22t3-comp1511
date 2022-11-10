// Program to do various linked list exercises
// Written by <your-name> (zID) on <date>

#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int main(void) {

    // Demo Copy
    struct node *head = NULL;
    head = add_last(head, 10);
    head = add_last(head, 11);
    head = add_last(head, 12);

    struct node *copied = copy(head);

    printf("COPYING LIST\n");
    printf("------------------------------------------------------------\n");
    printf("Original list:         ");
    print_list(head);
    printf("Copy of original list: ");
    print_list(copied);
    printf("Changing the first node of copy to 42 ...\n");
    copied->data = 42;
    printf("After changing the copy, original list should be unchanged:\n");
    printf("Original list:         ");
    print_list(head);
    printf("Copy of original list: ");
    print_list(copied);
    
    // Demo list append
    struct node *list_1 = NULL;
    list_1 = add_last(list_1, 10);
    list_1 = add_last(list_1, 11);
    list_1 = add_last(list_1, 12);
    struct node *list_2 = NULL;
    list_2 = add_last(list_2, 13);
    list_2 = add_last(list_2, 14);
    list_2 = add_last(list_2, 15);

    struct node *appended = list_append(list_1, list_2);

    printf("\n\n");
    printf("APPENDING LISTS\n");
    printf("------------------------------------------------------------\n");
    printf("List 1:        ");
    print_list(list_1);
    printf("List 2:        ");
    print_list(list_2);
    printf("Appended list: ");
    print_list(appended);

    return 0;
}

/** PRESCRIBED FUNCTIONS **/

// Creates a node with the given data and appends it to the end of the linked 
// list pointed at by head. Returns head.
// If head is NULL, returns a pointer to the the new node. 
struct node *add_last(struct node *head, int data) {
    struct node *new = malloc(sizeof(struct node));
    new->data = data;
    new->next = NULL;

    // Return new if linked list is initially empty
    if (head == NULL) {
        return new;
    }

    // Otherwise, loop to end of list and add node.
    struct node *curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = new;

    // We are inserting at the end --> head will not change
    return head;
}

// Prints the linked list pointed at by head in the format:
//      1 -> 2 -> 3 -> X
void print_list(struct node *head) {
    struct node *curr = head;
    while (curr != NULL) {
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("X\n");
}

// Create a copy of list and return a pointer to the head of it
struct node *copy(struct node *list) {
    
    // Set copied to NULL. When we use add_last the first time, copy will be set
    // to point at the first node. 
    struct node *copied = NULL;
    struct node *current = list;
    while (current != NULL) {
        // Using add_last, create a new node with the value of the current node 
        // in the original list and add it to the end of the copy
        int value = current->data;
        copied = add_last(copied, value);

        current = current->next;
    }
    return copied;
}

// Creates a new list consisting of the values in the second list appended to 
// the values in the first list
// Returns a pointer to the head of the appended list
struct node *list_append(struct node *first_list, struct node *second_list) {
    // Copy the lists so the appended list is completely independent of the 
    // original lists
    struct node *first_copy = copy(first_list);    
    struct node *second_copy = copy(second_list);    
    // If the first list is empty, the appended list just consists of the second
    // list
    if (first_copy == NULL) {
        return second_copy;
    }
    
    // Move current to the end of the first list
    struct node *current = first_copy;
    while (current->next != NULL) {
        current = current->next;
    }

    // current now points at the last node in first_copy
    current->next = second_copy;
    return first_copy;
}
