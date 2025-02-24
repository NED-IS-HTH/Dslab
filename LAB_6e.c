//frequency 

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

void print_frequency(struct Node *head)
{
    int freq[1000] = {0};
    struct Node *temp = head;
    while (temp != NULL)
    {
        freq[temp->data]++;
        temp = temp->next;
    }

    for (int i = 0; i < 1000; i++)
    {
        if (freq[i] != 0)
        {
            printf("%d occurs %d times\n", i, freq[i]);
        }
    }
}

int main()
{
    for (int i = 0; i < 10; i++)
    {
        insert(rand() % (1000), head);
    }
    print_frequency(head);
    return 0;
}

