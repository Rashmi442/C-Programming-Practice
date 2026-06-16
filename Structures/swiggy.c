/*Problem Statement: Swiggy Order Management System. Swiggy wants to maintain details of food items ordered by customers.

Write a C program using a structure to store the details of each food item, including Food ID, Price per Item, and Quantity Ordered.
Read the details of N food items from the user. Pass the array of structures to a function named displayOrders(), which should display the details of each food item along with its Total Cost (Price × Quantity).

Structure Members
food_id – Unique ID of the food item
price – Price of one food item
quantity – Number of items ordered

The displayOrders() function should print:
Food ID
Price per Item
Quantity Ordered
Total Cost for the food item

Sample Input
Enter the number of food items:
3
Enter Food ID: 101
Enter Price: 250
Enter Quantity: 2

Enter Food ID: 205
Enter Price: 180
Enter Quantity: 3

Enter Food ID: 310
Enter Price: 120
Enter Quantity: 5
Sample Output

Swiggy Order Details:

Food ID : 101
Price : 250.00
Quantity : 2.00
Total Cost : 500.00

Food ID : 205
Price : 180.00
Quantity : 3.00
Total Cost : 540.00

Food ID : 310
Price : 120.00
Quantity : 5.00
Total Cost : 600.00 */

// Passing array of structures to functions as arguments
#include<stdio.h>

struct food {
    int food_id;
    float price;
    int quantity;
};
//function declaration
 void displayOrders(struct food f[],int n);

 int main(){
    int n;
    printf("Enter the number of food items:");
    scanf("%d",&n);
    struct food f[n];

    for(int i=0;i<n;i=i+1){
    printf("Enter the Food id: ");
    scanf("%d",&f[i].food_id);

    printf("Enter the Price: ");
    scanf("%f",&f[i].price);

    printf("ENter the Quantity: ");
    scanf("%d",&f[i].quantity);
   }
   //Function call
    displayOrders(f,n);
     return 0;
 }

void displayOrders(struct food f[],int n){
    float cost;
    printf("\n---------ORDER DETAILS--------\n");
    for(int i=0;i<n;i=i+=1){
    cost =f[i].price*f[i].quantity;
    printf("FOOD ID:%d\n",f[i].food_id);
    printf("Price:%.2f\n",f[i].price);
    printf("Quantity:%d\n",f[i].quantity);
    printf("Total Cost: %.2f\n",cost);
}
 }