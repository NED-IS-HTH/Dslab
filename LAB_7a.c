//Creating and travesrsing doubly Linked list

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

//struct Node *head = NULL;

void insert(int new_data, struct Node **head)
{
    if (*head == NULL)
    {
        struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
        newnode->data = new_data;
        newnode->next = NULL;
        newnode->prev = NULL;
        *head = newnode;
    }
    else
    {
        struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
        struct Node *tail = *head;
        newnode->data = new_data;
        newnode->next = NULL;
        while (tail->next != NULL)
        {
            tail = tail->next;
        }
        tail->next = newnode;
        newnode->prev = tail;
    }
}

void display(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void display_reverse(struct Node *head)
{
    struct Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
}

int main()
{
    struct Node *head = NULL;
    for (int i = 0; i < 10; i++)
    {
        insert(rand() % (100), &head);
    }
    display(head);
    printf("\n");
    display_reverse(head);
    return 0;
}