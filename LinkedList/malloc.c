#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *head = NULL, *temp=NULL, *newnode=NULL;
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {

        newnode = (struct Node *)malloc(sizeof(struct Node));

        if(newnode == NULL) {
            printf("Memory Allocation failed\n");
            return 1;
        }

        printf("Enter data for Node %d: ",i+1);
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

    printf("Linked List: \n");
    // redirect top head so, that we print from head , before temp was pointing to last node.
    temp = head;
    while(temp != NULL)
    {
        printf("Data : %d |Address : %p |next Node Address :%p\n", temp->data,temp,temp->next);
        printf("\n");
        temp = temp->next;
    }
   //free()
   temp=head;
   while(temp!=NULL)
   {
    struct Node *nextnode=temp->next;
    free(temp);
    temp=nextnode;
   }
    return 0;
}
