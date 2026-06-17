#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int main()
{
    int n, choice, pos;

    struct Node *head = NULL, *temp = NULL, *newnode = NULL;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // Create initial linked list
    for(int i = 0; i < n; i++)
    {
        newnode = (struct Node *)malloc(sizeof(struct Node));

        if(newnode == NULL)
        {
            printf("Memory Allocation Failed\n");
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
        printf("\n========== MENU ==========\n");
        printf("1. Insert Node at Any Position\n");
        printf("2. Traverse Linked List\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            {
                newnode = (struct Node *)malloc(sizeof(struct Node));

                if(newnode == NULL)
                {
                    printf("Memory Allocation Failed\n");
                    break;
                }

                printf("Enter data: ");
                scanf("%d", &newnode->data);

                printf("Enter position: ");
                scanf("%d", &pos);

                newnode->next = NULL;

                if(pos < 1)
                {
                    printf("Invalid Position\n");
                    free(newnode);
                    break;
                }

                // Insert at beginning
                if(pos == 1)
                {
                    newnode->next = head;
                    head = newnode;
                }
                else
                {
                    temp = head;

                    for(int i = 1; i < pos - 1 && temp != NULL; i++)
                    {
                        temp = temp->next;
                    }

                    if(temp == NULL)
                    {
                        printf("Invalid Position\n");
                        free(newnode);
                    }
                    else
                    {
                        newnode->next = temp->next;
                        temp->next = newnode;

                        printf("Node Inserted Successfully\n");
                    }
                }

                break;
            }

            case 2:
            {
                if(head == NULL)
                {
                    printf("Linked List is Empty\n");
                }
                else
                {
                    temp = head;

                    printf("\nLinked List:\n");

                    while(temp != NULL)
                    {
                        printf("Data: %d | Current Address: %p | Next Address: %p\n",
                               temp->data, temp, temp->next);

                        temp = temp->next;
                    }
                }

                break;
            }

            case 3:
            {
                temp = head;

                while(temp != NULL)
                {
                    struct Node *nextnode = temp->next;
                    free(temp);
                    temp = nextnode;
                }

                printf("Exiting...\n");
                return 0;
            }

            default:
            {
                printf("Invalid Choice\n");
            }
        }
    }

    return 0;
}