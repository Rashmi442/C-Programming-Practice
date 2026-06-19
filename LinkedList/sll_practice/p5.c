/*Problem 5: Library Book Borrower Management (Singly Linked List)
Problem Statement
A library maintains the details of students who borrowed a particular book. Each record contains:
Student ID
Student Name
Borrow Date
Return Date


Develop a C program using a Singly Linked List to:
Add a borrower.
Display all borrowers.
Search a borrower.
Remove the borrower after returning the book.
Display the total number of borrowers.
Exit.
*/
#include<stdio.h>
#include<stdlib.h>
struct Borrower
{
    int student_id;
    char student_name[100];
    char borrow_date[20];
    char return_date[20];
    struct Borrower *next;
};
int main()
{
    int n, choice, id, count;
    struct Borrower *head=NULL, *temp=NULL, *newborrower=NULL, *ptr=NULL;
    printf("Enter number of borrowers: ");
    scanf("%d",&n);
    // Create initial list
    for(int i=0;i<n;i++)
    {
        newborrower=(struct Borrower *)malloc(sizeof(struct Borrower));
        printf("Enter Student ID: ");
        scanf("%d",&newborrower->student_id);
        printf("Enter Student Name: ");
        scanf("%s",newborrower->student_name);
        printf("Enter Borrow Date: ");
        scanf("%s",newborrower->borrow_date);
        printf("Enter Return Date: ");
        scanf("%s",newborrower->return_date);
        newborrower->next=NULL;
        if(head==NULL)
        {
            head=newborrower;
            temp=newborrower;
        }
        else
        {
            temp->next=newborrower;
            temp=newborrower;
        }
    }
    while(1)
    {
        printf("\n------ MENU ------\n");
        printf("1. Add a borrower\n");
        printf("2. Display all borrowers\n");
        printf("3. Search a borrower\n");
        printf("4. Remove borrower after returning book\n");
        printf("5. Display total number of borrowers\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            // Add borrower
            case 1:
                newborrower=(struct Borrower *)malloc(sizeof(struct Borrower));
                printf("Enter Student ID: ");
                scanf("%d",&newborrower->student_id);
                printf("Enter Student Name: ");
                scanf("%s",newborrower->student_name);
                printf("Enter Borrow Date: ");
                scanf("%s",newborrower->borrow_date);
                printf("Enter Return Date: ");
                scanf("%s",newborrower->return_date);
                newborrower->next=NULL;
                if(head==NULL)
                {
                    head=newborrower;
                }
                else
                {
                    temp=head;
                    while(temp->next!=NULL)
                    {
                        temp=temp->next;
                    }
                    temp->next=newborrower;
                }
                printf("Borrower added successfully.\n");
                break;
            // Display borrowers
            case 2:
                if(head==NULL)
                {
                    printf("No borrowers found.\n");
                }
                else
                {
                    temp=head;
                    while(temp!=NULL)
                    {
                        printf("Student ID : %d\n",temp->student_id);
                        printf("Student Name : %s\n",temp->student_name);
                        printf("Borrow Date : %s\n",temp->borrow_date);
                        printf("Return Date : %s\n",temp->return_date);
                        printf("\n");
                       temp=temp->next;
                    }
                }
                break;
            // Search borrower
            case 3:
                printf("Enter Student ID to search: ");
                scanf("%d",&id);
                temp=head;
                while(temp!=NULL)
                {
                    if(temp->student_id==id)
                    {
                        printf("Borrower Found\n");
                        printf("Student ID : %d\n",temp->student_id);
                        printf("Student Name : %s\n",temp->student_name);
                        printf("Borrow Date : %s\n",temp->borrow_date);
                        printf("Return Date : %s\n",temp->return_date);
                        break;
                    }
                    temp=temp->next;
                }
                if(temp==NULL)
                {
                    printf("Borrower not found.\n");
                }
                break;
            // Remove borrower
            case 4:
                printf("Enter Student ID to remove: ");
                scanf("%d",&id);
                if(head==NULL)
                {
                    printf("No borrowers available.\n");
                }
                else if(head->student_id==id)
                {
                    ptr=head;
                    head=head->next;
                    free(ptr);
                    printf("Borrower removed successfully.\n");
                }
                else
                {
                    temp=head;
                    while(temp->next!=NULL && temp->next->student_id!=id)
                    {
                        temp=temp->next;
                    }
                    if(temp->next==NULL)
                    {
                        printf("Borrower not found.\n");
                    }
                    else
                    {
                        ptr=temp->next;
                        temp->next=ptr->next;
                        free(ptr);
                        printf("Borrower removed successfully.\n");
                    }
                }
                break;
            // Count borrowers
            case 5:
                count=0;
                temp=head;
                while(temp!=NULL)
                {
                    count++;
                    temp=temp->next;
                }
                printf("Total number of borrowers = %d\n",count);
                break;
            // Exit
            case 6:
                temp=head;
                while(temp!=NULL)
                {
                    ptr=temp;
                    temp=temp->next;
                    free(ptr);
                }
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}