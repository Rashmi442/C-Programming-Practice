//passing pointer to structurees to functions as arguments
// Electricity Bill
#include<stdio.h>
struct ElectricityBill{
    int consumer_no;
    float units;
}e;
void calculateEbill(struct ElectricityBill *e);
int main()
{
    printf("enter consumer num: ");
    scanf("%d",&e.consumer_no);
    printf("enter units: ");
    scanf("%f",&e.units);

    calculateEbill(&e);
}
void calculateEbill(struct ElectricityBill *e){
    float amt=e->units *8.50f;
    printf("\n.....ELECTRICITY BILL......\n");
    printf("Conumer number:%d\n",e->consumer_no);
    printf("unit used:%.2f\n",e->units);
    printf("BILL:%.2f\n",amt);
}
