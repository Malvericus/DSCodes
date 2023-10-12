#include <stdio.h> 
#include <stdlib.h>

struct Node
{
    int data;
    struct Node * right;
    struct Node * left;
    int height;
};

void pre_order(struct Node *root) {

    if (root != NULL)
    {
        printf("%d ", root->data);
        pre_order(root->left);
        pre_order(root->right);
    }
    
}


int get_height(struct Node * n) {
    if (n == NULL)
    {
        return 0;
    }

    return n->height;
    
}

struct Node * create_node(int data) {

    struct Node * node = (struct Node *)malloc(sizeof(struct Node));

    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;

    return node;
}

int balance_factor(struct Node * n) {
    if (n == NULL)
    {
        return 0;
    }

    return get_height(n->left) - get_height(n->right);
}

int max_height(int x, int y) {
   
   return (x > y)? x : y;
    
}

struct Node * right_rotate(struct Node * node) {
   
    struct Node * ptr1 = node->left;
    struct Node * ptr2 = ptr1->right;

    ptr1->right = node;
    node->left = ptr2;

    node->height = max_height(get_height(node->right), get_height(node->left)) + 1;
    ptr1->height = max_height(get_height(ptr1->right), get_height(ptr1->left)) + 1;

    return ptr1;
}

struct Node * left_rotate(struct Node * node) {
   
    struct Node * ptr1 = node->right;
    struct Node * ptr2 = ptr1->left;

    ptr1->left = node;
    node->right = ptr2;

    node->height = max_height(get_height(node->left), get_height(node->right)) + 1;
    ptr1->height = max_height(get_height(ptr1->left), get_height(ptr1->right)) + 1;

    return ptr1;
}

struct Node * insert(struct Node * node, int data) {
    if (node == NULL)
    {
        return (create_node(data));
    }

    if (data < node->data)
    {
        node->left = insert(node->left, data);
    }

    else if (data > node->data)
    {
        node->right = insert(node->right, data);
    }

    node->height = max_height(get_height(node->left), get_height(node->right)) + 1;
    int bf = balance_factor(node);

    // Left - Left Case:
    if (bf > 1 && data < node->left->data)
    {
        return right_rotate(node);
    }

    // Right - Right Case:
    if (bf < -1 && data > node->right->data)
    {
        return left_rotate(node);
    }
    
    // Left - Right Case:
    if (bf > 1 && data > node->left->data)
    {
        node->left = left_rotate(node->left);
        return right_rotate(node);
    }

    // Right - Left Case:
    if (bf < -1 && data < node->right->data)
    {
        node->right = right_rotate(node->right);
        return left_rotate(node);
    }
    
    return node;
    
}


int main() {

    struct Node * root = NULL;
    
    root = insert(root, 7);
    root = insert(root, 1);
    root = insert(root, 10);
    root = insert(root, 17);
    root = insert(root, 16);  
    
    pre_order(root);
    
    return 0;
}