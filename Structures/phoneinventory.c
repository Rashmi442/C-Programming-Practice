//passing array of structures to functions as arguments
#include<stdio.h>
struct Product{
    int productid;
    char prod_name[20];
    float price;
    int quantity;
} ;
void calcinVal(struct Product products[],int n); 
int main(){
   int n;
   printf("enter num of products: ");
   scanf("%d",&n);
   struct Product products[n];
   for(int i=0;i<n;i=i+1){
    printf("Enter the product id: ");
    scanf("%d",&products[i].productid);

    printf("Enter the product name: ");
    scanf("%s",&products[i].prod_name);

    printf("Enter the Price: ");
    scanf("%f",&products[i].price);

    printf("ENter the Quantity: ");
    scanf("%d",&products[i].quantity);
   }
    calcinVal(products,n);
    return 0;
}
void calcinVal(struct Product products[],int n){

    float inventoryvalue;

    printf("\n");
    printf("------MOBILE INVENTORY\n");

    for(int i=0;i<n;i++)
    {
        inventoryvalue = products[i].quantity * products[i].price;

        printf("Product ID : %d\n",products[i].productid);
        printf("Product Name: %s\n",products[i].prod_name);
        printf("Product Price : %.2f\n",products[i].price);
        printf("Product Quantity : %d\n",products[i].quantity);
        printf("Inventory Value : %.2f\n",inventoryvalue);

        printf("\n");
    }    
}