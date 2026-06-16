// passing structure members to functions as arguments 
#include<stdio.h>
struct Employee{
    int id;
    float sal;
    float bonusper;
}e;
//function declaration
void bonus(int id,float sal, float bonusper);
int main(){
    printf("Enter Employee Details\n");
    printf("ENter Emp id: ");
    scanf("%d",&e.id);
    printf("Enter salary: ");
    scanf("%f",&e.sal);
    printf("ENter bonus percent: ");
    scanf("%f",&e.bonusper);
    bonus(e.id,e.sal,e.bonusper);
}

void bonus(int id,float sal, float bonusper){
    float B= sal*(bonusper/100);
    float total_sal = sal+B;
    printf("\n....EMPLOYEE DETAILS....\n");
    printf("EMPLOYEE ID:%d\n",id);
    printf("EMPLOYEE SALARY:%.2f\n",sal);
    printf("EMPLOYEE BONUS PER:%.2f\n",bonusper);
    printf("BONUS AMT:%.2f\n",B);
    printf("TOTAL SALARY:%.2f\n",total_sal);
}