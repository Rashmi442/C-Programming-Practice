#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node
{
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node* createNode(int value)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to print the linked list
void printList(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to reverse the linked list
struct Node* reverseList(struct Node *head)
{
    struct Node *prev = NULL;
    struct Node *current = head;
    struct Node *next = NULL;

    while (current != NULL)
    {
        next = current->next;   // Save next node
        current->next = prev;   // Reverse the link
        prev = current;         // Move prev forward
        current = next;         // Move current forward
    }

    return prev;   // New head
}

int main()
{
    // Creating the linked list: 10 -> 20 -> 30 -> 40
    struct Node *head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);

    printf("Original Linked List:\n");
    printList(head);

    head = reverseList(head);

    printf("Reversed Linked List:\n");
    printList(head);

    return 0;
}