//remove duplication
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *head = NULL;

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

void del_at_pos(int n)
{
    struct Node *temp = head;
    struct Node *prev = NULL;
    for (int i = 0; i < n; i++)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    free(temp);
}

int main()
{
    for (int i = 0; i < 10; i++)
    {
        insert(rand() % (100), head);
    }
    print(head);

    struct Node *temp = head;
    int A[100];
    for
}