//merge two List
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insert(int new_data, struct Node *head)
{
    if (head == NULL)
    {
        struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
        newnode->data = new_data;
        newnode->next = NULL;
        head = newnode;
    }
    else
    {
        struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
        struct Node *tail = head;
        newnode->data = new_data;
        newnode->next = NULL;
        while (tail->next != NULL)
        {
            tail = tail->next;
        }
        tail->next = newnode;
    }
}

void print(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    struct Node *head1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node *head2 = (struct Node*)malloc(sizeof(struct Node));
    struct Node *head3 = NULL;

    for (int i = 0; i < 5; i++)
    {
        insert(i, head1);
    }
    for (int i = 5; i < 10; i++)
    {
        insert(i, head2);
    }
    
    struct Node *tail = head1;
    while (tail->next != NULL)
    {
        if (head3 == NULL)
        {
            struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
            newnode->data = tail->data;
            newnode->next = NULL;
            head3 = newnode;
        }
        else
        {
            struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
            newnode->data = tail->data;
            newnode->next = NULL;
            while (tail->next != NULL)
            {
                tail = tail->next;
            }
            tail->next = newnode;
        }
        tail = tail->next;
    }
    tail = head2;
    while (tail->next != NULL)
    {
        
        struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
        newnode->data = tail->data;
        newnode->next = NULL;
        while (tail->next != NULL)
        {
            tail = tail->next;
        }
        tail->next = newnode;
        tail = tail->next;
    }
    print(head3);
    return 0;
}