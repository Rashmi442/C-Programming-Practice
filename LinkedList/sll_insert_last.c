#include <stdio.h>
#include <stdlib.h> //malloc() and free()

struct Node
{
    int data;
    struct Node *next;
};

int main()
{
    int n, choice;

    printf("Enter the number of nodes: ");
    scanf("%d",&n);//5

    struct Node *head=NULL, *temp=NULL,*newnode=NULL;

    for(int i=0;i<n;i++)
    {
        newnode=(struct Node*)malloc(sizeof(struct Node));

        if(newnode==NULL)
        {
            printf("Memory allocation failed\n");
            return 1;
        }

        printf("Enter the data to be inserted for the node %d: ",i+1);
        scanf("%d",&newnode->data);//10

        newnode->next=NULL;

        if(head==NULL)
        {  
            head=newnode;
            temp=head;
        }
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
    }

    while(1)
    {
        printf("\n======= MENU =========\n");
        printf("1.Insert a new node at the last of the LL.\n");
        printf("2.Traverse the Linked List\n");
        printf("3.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                newnode=(struct Node*)malloc(sizeof(struct Node));

                if(newnode==NULL)
                {
                    printf("Memory allocation failed\n");
                    return 1;
                }

                printf("Enter the data to be inserted in new node: ");
                scanf("%d",&newnode->data);//111

                newnode->next=NULL;

                if(head == NULL)
                {
                    head=newnode;
                }
                else
                {
                    temp=head;
                    while(temp->next!=NULL){
                        temp=temp->next;
                    }
                    temp->next = newnode;
                }
                printf("New node inserted successfully\n");
                break;
            }

            case 2:
            {
                temp=head;
                if(head==NULL)
                {
                    printf("List is empty");
                }
                else
                {
                    while(temp!=NULL)
                    {
                        printf("Data : %d | Node Address : %p | New Node Address : %p\n",temp->data,temp,temp->next);
                        printf("\n");
                        temp=temp->next;
                    }
                };
                
            }
                    break;
            }
            case 3:
            { 
                temp=head;

                while(temp!=NULL)
                {
                    struct Node *nextnode = temp->next;
                    free(temp);
                    temp=nextnode;
                }

                printf("Exiting...\n");
                exit(0);
            }

            default:printf("Invalid choice\n");
        }
    }

    return 0;
}