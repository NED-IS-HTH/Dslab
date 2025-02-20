#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
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

void del_at_beg(struct Node *head)
{
    struct Node *temp = head;
    head = head->next;
    free(temp);
}

int main()
{
    struct Node *head = NULL;
    instert(0,head);
    insert(4,head);
    insert(7,head);
    insert(13,head);
    insert(2,head);
    insert(6,head);
    insert(9,head);
    insert(1,head);

    struct Node *head1 = NULL;
    struct Node *head2 = NULL;
    struct Node *temp = head;

    del_at_beg(head);

    while (temp !=NULL)
    {
        if(temp->data % 2 != 0)
        {
            insert(temp->data,head1);
        }
        else
        {
            insert(temp->data,head2);
        }
    }
    print(head1);
    print(head2);
    return 0;
}