#include <stdio.h>
#include <stdlib.h>

struct Tree 
{
    int data;
    struct Tree *left;
    struct Tree *right;
};

struct Tree *root = NULL;


struct Stack {
    struct Tree *data;
    struct Stack *next;
};

struct Stack *top = NULL;

void push(struct Tree * tree_node) {
    struct Stack *ptr = (struct Stack *)malloc(sizeof(struct Stack));
    
    if (ptr == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    ptr->data = tree_node;
    ptr->next = top;
    top = ptr;
}

struct Tree *pop() {
    
    if (top == NULL) {
        printf("Stack is empty.\n");
        return NULL;
    }

    struct Stack *temp = top;
    struct Tree *tree_node = temp->data;
    top = temp->next;
    free(temp);

    return tree_node;
}


void create_tree() {
    
    struct Tree *node;
    int n;
   
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("\nEnter data for the tree nodes: ");
    for (int i = 0; i < n; i++) 
    {
        node = (struct Tree *)malloc(sizeof(struct Tree));
        
        if (node == NULL) {
            printf("Memory allocation failed.\n");
            exit(1);
        }

        scanf("%d", &node->data);
        
        node->left = NULL;
        node->right = NULL;
        
        if (root == NULL) 
        {
            root = node;
        }
        
        else 
        {
            struct Tree *temp = root;
            while (1) 
            {
                if (node->data < temp->data) 
                {
                    if (temp->left == NULL) {
                        temp->left = node;
                        break;
                    } 
                    
                    else 
                    {
                        temp = temp->left;
                    }
                } 
                
                else 
                {
                    if (temp->right == NULL) 
                    {
                        temp->right = node;
                        break;
                    } 
                    
                    else 
                    {
                        temp = temp->right;
                    }
                }
            }
        }
    }
}

void pre_order() {
    struct Tree *ptr = root;

    while (ptr != NULL || top != NULL) 
    {
        while (ptr != NULL) 
        {
            printf("%d ", ptr->data);
            push(ptr);
            ptr = ptr->left;
        }

        ptr = pop();

        ptr = ptr->right;
    }
}


void in_order() {
    struct Tree *ptr = root;

    while (ptr != NULL || top != NULL) 
    {
        while (ptr != NULL) 
        {
            push(ptr);
            ptr = ptr->left;
        }

        ptr = pop();

        printf("%d ", ptr->data);

        ptr = ptr->right;
    }
}


void post_order() {
   
}



int main() {
    create_tree();

    printf("\nPre-order Traversal: ");
    pre_order();

    printf("\nIn-order Traversal: ");
    in_order();

    printf("\nPost-order Traversal: ");
    //post_order();

    return 0;
}