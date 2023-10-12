#include <stdio.h> 
#include <stdlib.h>

struct Queue
{
    int size;
    int front;
    int rear;
    int *arr;
};

int isFull(struct Queue *head) {
    if (head->rear == head->size - 1)
    {
        return 1;
    }

    return 0;
    
}

int isEmpty(struct Queue *head) {
    if (head->front == head->rear)
    {
        return 1;
    }

    return 0;
    
}

void enq(struct Queue *head, int data) {
    if (isFull(head))
    {
        printf("Queue is Full \n");
    }

    else 
    {
        head->rear++;
        head->arr[head->rear] = data;
    }
    
}

void deq(struct Queue *head) {
    if (isEmpty(head))
    {
        printf("Stack is Empty \n");
    }

    else 
    {
        head->front++;
        printf("Item dequeued: %d \n", head->arr[head->front]);
    }
    
}

void display(struct Queue *head) {

    printf("The Queue: \n");

    if (head->front == -1)
    {
        for (int i = 0; i <= head->rear; i++)
        {
            printf("%d ", head->arr[i]);
        }
        
    }

    else
    {
        for (int i = (head->front + 1); i <= head->rear; i++)
        {
            printf("%d ", head->arr[i]);
        }
        
    }
    
    
    printf("\n");
}

int main() {

    struct Queue q;
    q.size = 50;
    q.front = q.rear = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));

    enq(&q, 1);
    enq(&q, 2);
    enq(&q, 3);
    enq(&q, 4);
    display(&q);

    printf("\n");
    
    deq(&q);
    deq(&q);
    display(&q);

    return 0;
}