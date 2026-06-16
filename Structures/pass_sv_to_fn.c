//passing structure variable to functions as arguments
//online shopping

#include<stdio.h>

struct Order{
    int id;
    float price;
}ord;

void calcGST(struct Order ord,float GST);
int main(){
   float GST;
   printf("ENter order id: ");
   scanf("%d",&ord.id);
   printf("enter price: ");
   scanf("%f",&ord.price);
   printf("GST %: ");
   scanf("%f",&GST);
   calcGST(ord,GST);
}

void calcGST(struct Order ord,float GST){
    float P=ord.price*GST/100;
    float totprice= P+ord.price;
    printf("\n....ORDER DETAILS....\n");
    printf("ORDER ID:%d\n",ord.id);
    printf("ORDER PRICE:%.2f\n",ord.price);
    printf("ORDER GST PER:%.2f\n",GST);
    printf("GST AMT:%.2f\n",P);
    printf("TOTAL PRICE:%.2f\n",totprice);
}