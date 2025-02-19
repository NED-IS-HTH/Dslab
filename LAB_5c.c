//apply bubble sort on Linked list
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void bubble_sortLst(struct Node *head)
{
    struct Node *nextnode,*temp ;
    if (head == NULL)
        printf("List is empty\n");
    else
    {
        nextnode = head;
        while(nextnode->next != NULL)
        {
            temp = nextnode->next;
            while(temp != NULL)
            {
                if (nextnode->data > temp->data)
                {
                    int t = nextnode->data;
                    nextnode->data = temp->data;
                    temp->data = t;
                }
            }
        }
    }
}

int main()
{
    struct Node *newnode, *temp;
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    for(int i=0;i<n;i++)
    {
        newnode = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter the data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        if (head == NULL)
        {
            head = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }
    bubble_sortLst(head);
    temp = head;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    return 0;
}