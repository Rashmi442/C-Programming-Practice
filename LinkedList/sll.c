#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
int main()
{
    int n, choice, pos, count;
    struct Node *head = NULL, *temp = NULL, *newnode = NULL, *ptr = NULL;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    // Create initial linked list
    for(int i = 0; i < n; i++)
    {
        newnode = (struct Node *)malloc(sizeof(struct Node));

        if(newnode == NULL)
        {
            printf("Memory allocation failed\n");
            return 1;
        }
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        if(head == NULL)
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
    while(1)
    {
        printf("\n1. Insert at beginning");
        printf("\n2. Insert at any position");
        printf("\n3. Insert at end");
        printf("\n4. Traverse");
        printf("\n5. Delete at any position");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            // Insert at beginning
            case 1:
                newnode = (struct Node *)malloc(sizeof(struct Node));
                if(newnode == NULL)
                {
                    printf("Memory allocation failed\n");
                    break;
                }
                printf("Enter data: ");
                scanf("%d", &newnode->data);
                newnode->next = head;
                head = newnode;
                break;
            // Insert at any position
            case 2:
                printf("Enter position: ");
                scanf("%d", &pos);
                newnode = (struct Node *)malloc(sizeof(struct Node));
                if(newnode == NULL)
                {
                    printf("Memory allocation failed\n");
                    break;
                }
                printf("Enter data: ");
                scanf("%d", &newnode->data);
                if(pos == 1)
                {
                    newnode->next = head;
                    head = newnode;
                }
                else
                {
                    count = 1;
                    temp = head;
                    while(count < pos - 1 && temp != NULL)
                    {
                        temp = temp->next;
                        count++;
                    }
                    if(temp == NULL)
                    {
                        printf("Invalid position\n");
                        free(newnode);
                    }
                    else
                    {
                        newnode->next = temp->next;
                        temp->next = newnode;
                    }
                }
                break;
            // Insert at end
            case 3:
                newnode = (struct Node *)malloc(sizeof(struct Node));

                if(newnode == NULL)
                {
                    printf("Memory allocation failed\n");
                    break;
                }
                printf("Enter data: ");
                scanf("%d", &newnode->data);
                newnode->next = NULL;
                if(head == NULL)
                {
                    head = newnode;
                }
                else
                {
                    temp = head;
                    while(temp->next != NULL)
                    {
                        temp = temp->next;
                    }
                    temp->next = newnode;
                }
                break;
            // Traverse
            case 4:
                if(head == NULL)
                {
                    printf("List is empty\n");
                }
                else
                {
                    temp = head;
                    printf("\nLinked List:\n");
                    while(temp != NULL)
                    {
                        printf("Data: %d | Present Address: %p | Next Address: %p\n",
                               temp->data,
                               (void *)temp,
                               (void *)temp->next);
                        temp = temp->next;
                    }
                }
                break;
            // Delete at any position
            case 5:
                if(head == NULL)
                {
                    printf("List is empty\n");
                    break;
                }
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                if(pos == 1)
                {
                    ptr = head;
                    head = head->next;
                    free(ptr);
                    printf("Node deleted successfully\n");
                }
                else
                {
                    count = 1;
                    temp = head;
                    while(count < pos - 1 && temp != NULL)
                    {
                        temp = temp->next;
                        count++;
                    }
                    if(temp == NULL || temp->next == NULL)
                    {
                        printf("Invalid position\n");
                    }
                    else
                    {
                        ptr = temp->next;
                        temp->next = ptr->next;
                        free(ptr);
                        printf("Node deleted successfully\n");
                    }
                }
                break;
            // Exit
            case 6:
                temp = head;
                while(temp != NULL)
                {
                    ptr = temp;
                    temp = temp->next;
                    free(ptr);
                }
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

