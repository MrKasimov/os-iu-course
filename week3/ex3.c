#include <stdlib.h>

// represents element in linked list
struct node {
    int value;
    struct node *next;
};

// prints all elements
void print_list(struct node *head) {
    struct node *current = head;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

// inserts node with new_value after prev_node
void insert_node(struct node *head, int new_value, struct node *prev_node) {
    struct node *current = head;
    while (current != prev_node && current != NULL)
        current = current->next;

    if (current != NULL) {
        struct node *new_node = (struct node *)malloc(sizeof(struct node));

        if(new_node == NULL)
            return;

        new_node->value = new_value;
        new_node->next = prev_node->next;
        prev_node->next = new_node;
    }
}

// deletes node specified by del_node
void delete_node(struct node *head, struct node *del_node) {
    struct node *current = head;
    while (current->next != del_node && current != NULL)
        current = current->next;

    if (current != NULL) {
        current->next = del_node->next;
        del_node->next = NULL;
        free(del_node);
    }
}

int main() {
    struct node *head = NULL;

    // directly create 3-element linked list
    struct node element3 = {3, NULL};
    struct node element2 = {2, &element3};
    struct node element1 = {1, &element2};
    head = &element1;

    printf("This is original linked list: ");
    print_list(head);

    // insert 4th element and print all
    insert_node(head, 4, &element3);
    printf("This is linked list after insertion of 4th element: ");
    print_list(head);

    // delete 3rd element and print all
    printf("This is linked list after deletion of 3rd element: ");
    delete_node(head, &element3);
    print_list(head);
    return 0;
}
