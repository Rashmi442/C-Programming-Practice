#include<stdio.h>
#include<stdlib.h>

struct Order
{
    int order_id;
    char customer_name[100];
    char food_item[100];
    int quantity;
    float total_bill;
    struct Order *next;
};

int main()
{
    int n, choice, id, count;
    struct Order *head=NULL, *temp=NULL, *neworder=NULL, *ptr=NULL;

    printf("Enter number of orders: ");
    scanf("%d",&n);

    // Initial orders
    for(int i=0;i<n;i++)
    {
        neworder=(struct Order *)malloc(sizeof(struct Order));

        printf("Enter Order ID: ");
        scanf("%d",&neworder->order_id);

        printf("Enter Customer Name: ");
        scanf("%s",neworder->customer_name);

        printf("Enter Food Item: ");
        scanf("%s",neworder->food_item);

        printf("Enter Quantity: ");
        scanf("%d",&neworder->quantity);

        printf("Enter Total Bill: ");
        scanf("%f",&neworder->total_bill);

        neworder->next=NULL;

        if(head==NULL)
        {
            head=neworder;
            temp=neworder;
        }
        else
        {
            temp->next=neworder;
            temp=neworder;
        }
    }

    while(1)
    {
        printf("\n------MENU------\n");
        printf("1. Add a new customer order\n");
        printf("2. Display all orders\n");
        printf("3. Search order by Order ID\n");
        printf("4. Cancel an order\n");
        printf("5. Count total pending orders\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                neworder=(struct Order *)malloc(sizeof(struct Order));

                printf("Enter Order ID: ");
                scanf("%d",&neworder->order_id);

                printf("Enter Customer Name: ");
                scanf("%s",neworder->customer_name);

                printf("Enter Food Item: ");
                scanf("%s",neworder->food_item);

                printf("Enter Quantity: ");
                scanf("%d",&neworder->quantity);

                printf("Enter Total Bill: ");
                scanf("%f",&neworder->total_bill);

                neworder->next=NULL;

                if(head==NULL)
                {
                    head=neworder;
                }
                else
                {
                    temp=head;

                    while(temp->next!=NULL)
                    {
                        temp=temp->next;
                    }

                    temp->next=neworder;
                }

                printf("Order added successfully.\n");
                break;

            case 2:
                if(head==NULL)
                {
                    printf("No orders available.\n");
                }
                else
                {
                    temp=head;

                    while(temp!=NULL)
                    {
                        printf("Order ID : %d | Customer Name : %s | Food Item : %s | Quantity : %d | Total Bill : %.2f\n",
                               temp->order_id,
                               temp->customer_name,
                               temp->food_item,
                               temp->quantity,
                               temp->total_bill);

                        temp=temp->next;
                    }
                }
                break;

            case 3:
                printf("Enter Order ID to search: ");
                scanf("%d",&id);

                temp=head;

                while(temp!=NULL)
                {
                    if(temp->order_id==id)
                    {
                        printf("Order Found\n");

                        printf("Order ID : %d | Customer Name : %s | Food Item : %s | Quantity : %d | Total Bill : %.2f\n",
                               temp->order_id,
                               temp->customer_name,
                               temp->food_item,
                               temp->quantity,
                               temp->total_bill);

                        break;
                    }

                    temp=temp->next;
                }

                if(temp==NULL)
                {
                    printf("Order not found.\n");
                }

                break;

            case 4:
                printf("Enter Order ID to cancel: ");
                scanf("%d",&id);

                if(head==NULL)
                {
                    printf("No orders available.\n");
                }
                else if(head->order_id==id)
                {
                    ptr=head;
                    head=head->next;
                    free(ptr);

                    printf("Order cancelled successfully.\n");
                }
                else
                {
                    temp=head;

                    while(temp->next!=NULL && temp->next->order_id!=id)
                    {
                        temp=temp->next;
                    }

                    if(temp->next==NULL)
                    {
                        printf("Order not found.\n");
                    }
                    else
                    {
                        ptr=temp->next;
                        temp->next=ptr->next;
                        free(ptr);

                        printf("Order cancelled successfully.\n");
                    }
                }

                break;

            case 5:
                count=0;
                temp=head;

                while(temp!=NULL)
                {
                    count++;
                    temp=temp->next;
                }

                printf("Total pending orders = %d\n",count);
                break;

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