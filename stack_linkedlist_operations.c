#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Stack {
    struct Node* top;
};

void create_empty_stack(struct Stack* node) {
    node->top = NULL;
}

int isEmpty(struct Stack* node) {
    return node->top == NULL;
}

void push(struct Stack* node, int data) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    if (ptr == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    ptr->data = data;
    ptr->next = node->top;
    node->top = ptr;
}

void pop(struct Stack* node) {
    if (isEmpty(node)) {
        printf("Stack is empty\n");
        return;
    }
    struct Node* temp = node->top;
    node->top = node->top->next;
    printf("Item popped = %d\n", temp->data);
    free(temp);
}

void display(struct Stack* node) {
    if (isEmpty(node)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack: ");
    struct Node* current = node->top;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void search(struct Stack* node, int data) {
    struct Node* current = node->top;
    while (current != NULL) {
        if (current->data == data) {
            printf("Item %d found in node\n", data);
            return;
        }
        current = current->next;
    }
    printf("Item %d not found in node\n", data);
}

int main() {
    struct Stack node;
    create_empty_stack(&node);

    push(&node, 1);
    push(&node, 2);
    push(&node, 3);
    push(&node, 4);

    display(&node);

    pop(&node);

    printf("\nAfter popping:\n");
    display(&node);

    printf("\n");

    search(&node, 1);

    return 0;
}
