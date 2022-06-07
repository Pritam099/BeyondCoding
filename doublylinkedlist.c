#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};
void traversalFromHead(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d", ptr->data);
        printf("->");
        ptr = ptr->next;
    }
    printf("NULL");
}
void traversalFromLast(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d", ptr->data);
        printf("->");
        ptr = ptr->prev;
    }
    printf("NULL");
}
int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    // Allocate memory for nodes in the linked list in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    // Link first and second nodes
    head->data = 7;
    head->prev = NULL;
    head->next = second;
    // Link second and third nodes
    second->data = 11;
    second->prev = head;
    second->next = third;
    // Link third and fourth nodes
    third->data = 41;
    third->prev = second;
    third->next = fourth;
    // Terminate the list at the third node
    fourth->data = 66;
    fourth->prev = third;
    fourth->next = NULL;
    //Doubly linked list traversal from the head element
    traversalFromHead(head);
    printf("\n");
    //Doubly linked list traversal from the tail element
    traversalFromLast(fourth);
    return 0;
}