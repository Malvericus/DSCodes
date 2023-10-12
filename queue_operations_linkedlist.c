#include <stdio.h> 
#include <stdlib.h>

struct Node {
    int data;
    struct Node * next;
};

struct Node * front = NULL;
struct Node * rear = NULL;

void enq(int data) {
    struct Node *ptr = malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = NULL;

    if ((front == NULL) && (rear == NULL))
    {
        front = rear = ptr;
    }

    else 
    {
        rear->next = ptr;
        rear = ptr;
    }

    printf("Node is inserted \n");
    
}

int deq() {
    if (front == NULL)
    {
        printf("\n Underflow \n");
        return -1;
    }

    else 
    {
        struct Node * temp = front;
        int temp_data = front->data;
        front = front->next;
        free(temp);
        return temp_data;
    }
    
}

void display() {
    struct Node * temp;
    if (front == NULL && rear == NULL)
    {
       printf("Queue is Empty");
    }

    else
    {
        printf("The queue is: \n");
        temp = front;
        while (temp)
        {
            printf("%d-->", temp->data);
            temp = temp->next;
        }

        printf("NULL \n");
        
    }

}

int main() {

    int choice, data;
    printf("TITLE \n");

    while (choice != 4)
    {
        printf("1. enq \n 2. Deq \n 3. Display \n 4. Exit \n");
        printf("Enter choice: ");
        printf("%d", &choice);

        switch (choice) 
        {
            case 1:
            {
                printf("Enter value to insert: ");
                scanf("%d", &data);

                enq(data);
                break;
            }

            case 2:
            {
                deq();
                break;
            }

            case 3:
            {
                display();
                break;
            }

            case 4:
            {
                exit(0);
                break;
            }

            default:
            {
                printf("Invalid Option Selected \n");
            }
        }
    }
    

    return 0;
}