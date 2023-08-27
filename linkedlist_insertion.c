#include <stdio.h> 
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void traversal(struct Node *ptr) {
    
    while (ptr != NULL)
    {
        printf("Value of Node: %d\n", ptr->data);
        ptr = ptr->next;
    }
    
}

struct Node * start_insert(struct Node *head, int data) {
    
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));

    ptr->next = head;
    ptr->data = data;
    return ptr;
}

struct Node * between_insert(struct Node *head, int data, int index) {

    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;

    int i = 0;
    while (i != index-1)
    {
        p = p->next;
        i++;
    }
    
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;

    return head;
}

struct Node * end_insert(struct Node *head, int data) {
    
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;

    ptr->data = data;

    while (p->next != NULL)
    {
        p = p->next;
    }

    p->next = ptr;
    ptr->next = NULL;

    return head;
}

struct Node * node_insert(struct Node *head, struct Node *prevNode, int data) {

    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    
    ptr->data = data;
    ptr->next = prevNode->next;
    prevNode->next = ptr;

    return head;
}

int main() {
    
    struct Node *head;
    struct Node *second;
    struct Node *third;

    // Allocating memory for nodes in the linked list in Heap (Dynamic):
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    head->data = 2;
    head->next = second;

    second->data = 4;
    second->next = third;

    third->data = 6;
    third->next = NULL;

    printf("Linked list before any insertion: \n");
    traversal(head);
    
    // head = start_insert(head, 1);
    // head = between_insert(head, 5, 2);
    // head = end_insert(head, 8);
    head = node_insert(head, second, 5);

    printf("\nLinked list after insertion: \n");
    traversal(head);

    return 0;
}