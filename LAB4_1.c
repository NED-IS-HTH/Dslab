//creating linked list and displaying it
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head;

int main()
{
    struct Node* newNode;
    struct Node* temp;
    int i;
    int n = 5;
    head = NULL;
    for (i = 0; i < n; i++) 
    {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = i;
        newNode->next = NULL;
        if (head == NULL)
        {
            head = newNode;
        } 
        else 
        {
            temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    return 0;
}
