#include <stdio.h> 
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node * create_node(int data) {

    struct Node *n;  
    n = (struct Node *)malloc(sizeof(struct Node));  
    n->data = data;  

    n->left = NULL;  
    n->right = NULL;

    return n;
}

void pre_order(struct Node *root) {

    if (root != NULL)
    {
        printf("%d ", root->data);
        pre_order(root->left);
        pre_order(root->right);
    }
    
}

void in_order(struct Node *root) {

    if (root != NULL)
    {
        in_order(root->left);
        printf("%d ", root->data);
        in_order(root->right);
    }
    
}

void post_order(struct Node *root) {

    if (root != NULL)
    {
        post_order(root->left);
        post_order(root->right);
        printf("%d ", root->data);
    }
    
}



int main () {

    struct Node *head = create_node(10);
    struct Node *a = create_node(7);
    struct Node *b = create_node(15);
    struct Node *c = create_node(16);
    struct Node *d = create_node(12);

//     Tree:
//        4
//       / \
//      1   6
//     / \
//    2   5

    head->left = a;
    head->right = b;

    a->left = c;
    a->right = d;

    pre_order(head);

    printf("\n");

    in_order(head);
    
    printf("\n");

    post_order(head);

    return 0;
}