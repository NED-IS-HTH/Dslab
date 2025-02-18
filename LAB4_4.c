//deletion of linked list
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void del_at_big()
{
    struct Node *temp = head;
    head = head->next;
    free(temp);
}

void del_at_end()
{
    struct Node *temp = head;
    struct Node *prev = NULL;
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    free(temp);
}

void del_at_pos(int pos)
{
    struct Node *temp = head;
    struct Node *prev = NULL;
    for (int i = 0; i < pos; i++)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    free(temp);
}