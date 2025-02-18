//creating and two list and joining them to make 3rd list 
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};


int main()
{
    struct Node *head1 = NULL;
    struct Node *head2 = NULL;
    struct Node *newNode, *temp;
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    while (n != 0)
    {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter the data: ");
        scanf("%d", &newNode->data);
        newNode->next = NULL;
        if (head1 == NULL)
        {
            head1 = newNode;
            temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
        n--;
    }
    printf("List 1 is created\n");

    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    while (n != 0)
    {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter the data: ");
        scanf("%d", &newNode->data);
        newNode->next = NULL;
        if (head2 == NULL)
        {
            head2 = newNode;
            temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
        n--;
    }
    printf("List 2 is created\n");

    struct Node *head3 = NULL;
    struct Node *temp1 = head1;
    struct Node *temp2 = head2;
    while (temp1 != NULL)
    {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = temp1->data;
        newNode->next = NULL;
        if (head3 == NULL)
        {
            head3 = newNode;
            temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
        temp1 = temp1->next;
    }
    while (temp2 != NULL)
    {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = temp2->data;
        newNode->next = NULL;
        if (head3 == NULL)
        {
            head3 = newNode;
            temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
        temp2 = temp2->next;
    }
    printf("List 3 is created\n");

    temp = head3;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    return 0;
}