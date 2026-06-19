/*Problem 6: Product Inventory Management System (Singly Linked List)
Problem Statement
A supermarket maintains its product inventory. Each product contains:
Product ID
Product Name
Price
Quantity


Develop a menu-driven C program using a Singly Linked List to:
Add a product.
Display all products.
Search for a product.
Delete a product.
Update product quantity.
Count total products.
Exit.*/
#include<stdio.h>
#include<stdlib.h>

struct Product{
    int prod_id;
    char prod_name[100];
    float price;
    int qty;
    struct Product *next;
};
int main(){
    int n, c=0,choice,i,id;
    struct Product *head=NULL,*temp=NULL,*newprod=NULL;
    printf("Enter the number of Products: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        newprod=(struct Product*)malloc(sizeof(struct Product));
        printf("Enter the product ID: ");
        scanf("%d",&newprod->prod_id);
        printf("Enter product name: ");
        scanf("%s",newprod->prod_name);
        printf("Enter the price: ");
        scanf("%f",&newprod->price);
        printf("Enter the Quantity: ");
        scanf("%d",&newprod->qty);
        newprod->next=NULL;
        if(head==NULL){
            head=newprod;
            temp=head;
        }
        else{
            temp->next=newprod;
            temp=newprod;
        }
    }
    while(1){
        printf("\n---------PRODUCT INVENTORY-------\n");
        printf("1.Add a product\n");
        printf("2.Display all products.\n");
        printf("3.Search for a product.\n");
        printf("4.Delete a product.\n");
        printf("5.Update product quantity.\n");
        printf("6.Count total products.\n");
        printf("7.Exit.\n");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                newprod=(struct Product *)malloc(sizeof(struct Product));
                printf("Enter the product ID: ");
                scanf("%d",&newprod->prod_id);
                printf("Enter product name: ");
                scanf("%s",newprod->prod_name);
                printf("Enter the price: ");
                scanf("%f",&newprod->price);
                printf("Enter the Quantity: ");
                scanf("%d",&newprod->qty);
                newprod->next=NULL;
                if(head==NULL)
                {
                    head=newprod;
                }
                else
                {
                    temp=head;
                    while(temp->next!=NULL)
                    {
                        temp=temp->next;
                    }
                    temp->next=newprod;
                }
                printf("Product added successfully.\n");
                break;
            case 2:
                if(head==NULL)
                {
                    printf("No products avilable.\n");
                }
                else{
                    temp=head;
                    while(temp!=NULL)
                    {
                        printf("Product ID: %d | Product Name: %s | Product Price : %.2f | Product Quantity: %d",temp->prod_id,temp->prod_name,temp->price,temp->qty);
                        printf("\n");
                        temp=temp->next;
                    }
                }
                break;
            case 3:
                printf("Product ID to search: ");
                scanf("%d",&id);
                temp=head;
                while(temp!=NULL){
                    if(temp->prod_id==id){
                        printf("Product found.\n");
                        printf("Product ID: %d | Product Name: %s | Product Price : %.2f | Product Quantity: %d",temp->prod_id,temp->prod_name,temp->price,temp->qty);
                        printf("\n");
                    }
                    temp=temp->next;
                }
                if(temp==NULL){
                    printf("Product not found.\n");
                }
                break;
            case 4:
                printf("Enter Product ID to cancel: ");
                scanf("%d",&id);

                if(head==NULL)
                {
                    printf("No products available.\n");
                }
                else if(head->prod_id==id)
                {
                    newprod=head;
                    head=head->next;
                    free(newprod);

                    printf("Product cancelled successfully.\n");
                }
                else
                {
                    temp=head;

                    while(temp->next!=NULL && temp->next->prod_id!=id)
                    {
                        temp=temp->next;
                    }

                    if(temp->next==NULL)
                    {
                        printf("Product not found.\n");
                    }
                    else
                    {
                        newprod=temp->next;
                        temp->next=newprod->next;
                        free(newprod);

                        printf("Product cancelled successfully.\n");
                    }
                }
                break;
            case 5:
                printf("Enter Product ID: ");
                scanf("%d", &id);
                temp = head;
                while(temp != NULL)
                {
                    if(temp->prod_id == id)
                    {
                        printf("Current Quantity = %.2f %%\n", temp->qty);
                        printf("Enter new Quantity: ");
                        scanf("%f", &temp->qty);
                        printf("Quantity Updated Successfully.\n");
                        break;
                    }
                    temp = temp->next;
                }
                if(temp == NULL)
                {
                    printf("Student not found.\n");
                }
                break;
            case 6:
                 c=0;
                 temp=head;
                 while(temp!=NULL){
                    c++;
                    temp=temp->next;
                 }
                 printf("Number of products: %d",c);
                 break;
            case 7:
                temp=head;
                while(temp!=NULL)
                {
                    newprod=temp;
                    temp=temp->next;
                    free(newprod);
                }
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid position....\n"); 
        }
    }
}