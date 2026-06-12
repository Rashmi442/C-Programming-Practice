#include <stdio.h>
struct Product
{
    int id;
    char name[30];
    int quantity;
    float price;
};
int main()
{
    //Array of Structures
    struct Product products[3]={
        {101,"Laptop",10,50000},
        {102,"Mouse",50,500},
        {103,"Keyboard",20,1500}
    };
    //Total value of all the items in stock and set it to 0
    float totalinventoryvalue = 0;
    //Prints the header row for the inventory table using tabs(\t) for spacing
    printf("ID\tName\t\tQty\tPrice\n");
    for(int i=0;i<3;i++)
    {
        //%d = integer, %-10s = left-aligned string with 10 characters width
        //%.2f = float with 2 decimal spaces
        printf("%d\t%-10s\t%d\t%.2f\n",products[i].id,products[i].name,products[i].quantity,products[i].price);

        //Calculate the value for the current product (quantity * price)
       
        totalinventoryvalue += products[i].quantity * products[i].price;
    } // End of the loop
    printf("\nTotal Inventory Value = %.2f\n",totalinventoryvalue);
    return 0;
}