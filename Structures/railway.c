/*Problem Statement
A railway reservation system stores passenger ticket information using a structure.
Create a structure named Ticket with the following members:

Ticket Number (int)
Passenger Name (char)
Source (char)
Destination (char)
Fare (float)


Write a C program to:
Read the ticket details from the user.
Store the details in a structure variable named ticket.


Pass the structure variable ticket to a function:
C
void printTicket(struct Ticket ticket);
The function should display all the ticket details in a neat format.


Note: Pass the entire structure variable to the function (pass by value), not individual members.
Sample Input

Enter Ticket Number: 10245
Enter Passenger Name: Annamalai
Enter Source: Chennai
Enter Destination: Salem
Enter Fare: 245.50
Sample Output

----------
-Railway Ticket ------------
Ticket Number : 10245
Passenger Name : Annamalai
Source : Chennai
Destination : Salem
Fare : Rs. 245.50
----------------------------------------*/

#include<stdio.h>

struct Ticket{
    int Ticket_num;
    char PassengerName[20];
    char Source[20];
    char Destination[20] ;
    float Fare ;
} ticket;
void printTicket(struct Ticket ticket);
int main(){
     printf("enter ticket num: ");
     scanf("%d",&ticket.Ticket_num);
     printf("enter name:");
     scanf(" %[^\n]",ticket.PassengerName);
     printf("enter source: ");
     scanf(" %[^\n]",ticket.Source);
     printf("enter detination: ");
     scanf(" %[^\n]",ticket.Destination);
     printf("entwer fare: ");
     scanf(" %f",&ticket.Fare);
     printTicket(ticket);
}
void printTicket(struct Ticket ticket){
     printf("\n....Passenger Details.....\n");
     printf("Ticket num:%d\n",ticket.Ticket_num);
     printf("Name:%s\n",ticket.PassengerName);
     printf("Source:%s\n",ticket.Source);
     printf("Detination:%s\n",ticket.Destination);
     printf("Fare (Rs):%.2f\n",ticket.Fare);
}
