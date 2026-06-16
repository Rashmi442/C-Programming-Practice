// passing structure members to functions as arguments 
#include<stdio.h>
struct Student{
    int rollnum;
    char name[20];
    float marks;
}s;

void display(int rollnum, char name[], float marks);

int main(){
    printf("Enter roll number: ");
    scanf("%d",&s.rollnum);
    printf("Enter name: ");
    scanf(" %[^\n]",s.name);
    printf("Enter mark: ");
    scanf("%f",&s.marks);
    display(s.rollnum, s.name, s.marks);
    return 0;
}

void display(int rollnum, char name[], float marks){
    printf("Student Details\n");
    printf("Roll number: %d\n",rollnum);
    printf("Name: %s\n",name);
    printf("Mark :%.2f",marks);
}