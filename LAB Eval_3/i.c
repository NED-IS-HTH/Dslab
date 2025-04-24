//finding the kth smallest no. in a binary search tree

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

int count = 0;
void inorder(struct node *root,int k)
{
    if (root == NULL)
        return;

    inorder(root->left,k);
    count++;
    if (count == k)
    {
        printf("%d\n", root->data);
        return;
    }
    inorder(root->right,k);
}

int main()
{
    struct node *root = (struct node *)malloc(sizeof(struct node));
    root->data = 5;
    root->left = (struct node *)malloc(sizeof(struct node));
    root->left->data = 3;
    root->right = (struct node *)malloc(sizeof(struct node));
    root->right->data = 7;
    root->left->left = (struct node *)malloc(sizeof(struct node));
    root->left->left->data = 2;
    root->left->right = (struct node *)malloc(sizeof(struct node));
    root->left->right->data = 4;
    root->right->left = (struct node *)malloc(sizeof(struct node));
    root->right->left->data = 6;
    root->right->right = (struct node *)malloc(sizeof(struct node));
    root->right->right->data = 8;

    int k = 3; // Change this value to find the kth smallest element
    inorder(root, k);

    return 0;
}
