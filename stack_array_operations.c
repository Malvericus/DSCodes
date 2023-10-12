#include <stdio.h> 
#include <stdlib.h>

#define max 10

int count = 0; 

struct Stack
{
    int items[max];
    int top;
};

void create_empty_stack(struct Stack * node) {
    node->top = -1;
}

int isFull(struct Stack * node) {
    if (node->top == max - 1)
    {
       return 1;
    }

    return 0;
    
}

int isEmpty(struct Stack * node) {
    if (node->top == -1)
    {
       return 1;
    }

    return 0;
    
}

void push(struct Stack * node, int data) {
    if (isFull(node))
    {
       printf("Stack is Full");
    }

    else 
    {
        node->top++; // It will update from -1 to 0 
        node->items[node->top] = data;

    }

    count++;  // For the user to know how many items have been pushed into the stack. Count should not exceed max
    
}

void pop(struct Stack *node) {
    if (isEmpty(node))
    {
        printf("\n Stack is Empty \n");
    }
    
    else
    {
        printf("Item popped = %d", node->items[node->top]);
        node->top--;
    }

    count--;
    printf("\n");
}

void display(struct Stack *node) {
    
    printf("Stack: ");
    for (int i = 0; i < count; i++)
    {
        printf("%d ", node->items[i]);
    }
    printf("\n");

    printf("Count Value: %d", count);
    printf("\n");
    
}

void search(struct Stack * node, int data) {

    for (int i = 0; i < count; i++)
    {
        if (node->items[i] == data)
        {
            printf("Item %d found in stack \n", data);
            break;
        }
        
    }
    
}


int main() {   

    struct Stack * sk = (struct Stack *)malloc(sizeof(struct Stack));

    create_empty_stack(sk);

    push(sk, 1);
    push(sk, 2);
    push(sk, 3);
    push(sk, 4);

    display(sk);

    pop(sk);

    printf("\nAfter popping: \n");
    display(sk);

    printf("\n");

    search(sk, 1);

    return 0;
}