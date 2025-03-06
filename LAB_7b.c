//Deleting and inserting a node in doubly Linked list

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

void del_at_beg(struct Node** head_ref) 
{
    struct Node *temp = *head_ref;
    if (*head_ref == NULL)
    {
        printf("List is empty\n");
        return;
    }
    else if ((*head_ref)->next == NULL)
    {
        free(*head_ref);
        *head_ref = NULL;
    }
    else
    { 
        *head-ref = (*head_ref)->next;
        (*head_ref)->prev = NULL;
        free(temp);
    }
}

void del_at_end(struct Node **head)
{
    struct Node *temp = *head;
    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    else if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
    }
    else
    {
        while (temp->next !=NULL)
        {
            temp = temp->next;
        }
        temp->prev->next = NULL;
        free(temp);
    }
}

void del_at_pos(struct Node **head, int pos)
{
    struct Node *temp = *head;
    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    else if (pos == 1)
    {
        del_at_beg(**head);
    }
    else
    {
        for (int i = 1; i < pos; i++)
        {
            temp = temp->next;
            if (temp == NULL)
            {
                printf("Position not found\n");
                return;
            }
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
    }
}

void insert_at_beg(struct Node **head, int data)
{
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = *head;
    new_node->prev = NULL;
    *head = new_node;
}

void insert_at_end(struct Node *head, int data)
{
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node *temp = head;
    new_node->data = data;
    new_node->next = NULL;

    if (head == NULL)
    {
        new_node->prev = NULL;
        head = new_node;
        return;
    }

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->prev = temp;
    return;
}

void insert_at_pos(struct Node *head, int data, int pos)
{
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node *temp = head;
    new_node->data = data;
    new_node->next = NULL;

    if (head == NULL)
    {
        new_node->prev = NULL;
        head = new_node;
        return;
    }

    for (int i = 1; i < pos; i++)
    {
        temp = temp->next;
        if (temp == NULL)
        {
            printf("Position not found\n");
            return;
        }
    }
    new_node->next = temp->next;
    temp->next = new_node;
    new_node->prev = temp;
    new_node->next->prev = new_node;
    return;
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

int main()
{
    struct Node *head = NULL;
    insert_at_beg(&head, 10);
    insert_at_beg(&head, 20);
    insert_at_end(head, 30);
    insert_at_end(head, 40);
    insert_at_pos(head, 25, 2);
    display(head);
    del_at_beg(&head);
    display(head);
    del_at_end(&head);
    display(head);
    del_at_pos(&head, 2);
    display(head);
    return 0;
}