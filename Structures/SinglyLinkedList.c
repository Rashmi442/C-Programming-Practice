//Implementation of Singly Linked LISt
#include<stdio.h>
struct Node{
    int data;
    struct Node *next;
}n1,n2,n3,n4,n5;

int main(){
    
    n1.data=10;
    n1.next=&n2;

    n2.data=20;
    n2.next=&n3;

    n3.data=30;
    n3.next=&n4;
    
    n4.data=30;
    n4.next=&n5;
    
    n5.data=30;
    n5.next=NULL;

    printf("NOde 1 data:\n");
    printf("Data : %d | Address : %p | Next node address : %p\n",n1.data,&n1,n1.next);

    printf("NOde 2 data:\n");
    printf("Data : %d | Address : %p | Next node address : %p\n",n2.data,&n2,n2.next);
    
    printf("NOde 3 data:\n");
    printf("Data : %d | Address : %p | Next node address : %p\n",n3.data,&n3,n4.next);

    printf("NOde 4 data:\n");
    printf("Data : %d | Address : %p | Next node address : %p\n",n4.data,&n4,n5.next);

    printf("NOde 5 data:\n");
    printf("Data : %d | Address : %p | Next node address : %p\n",n5.data,&n5,n5.next);
}
/*
Output: 
C:\Users\Rashm\Documents\C-Programming-Practice\Structures>gcc SinglyLinkedList.c -o SinglyLinkedList

C:\Users\Rashm\Documents\C-Programming-Practice\Structures>SinglyLinkedList
NOde 1 data:
Data : 10 | Address : 00407090 | Next node address : 00407080
NOde 2 data:
Data : 20 | Address : 00407080 | Next node address : 00407070
NOde 3 data:
Data : 30 | Address : 00407070 | Next node address : 00407078
NOde 4 data:
Data : 30 | Address : 00407088 | Next node address : 00000000
NOde 5 data:
Data : 30 | Address : 00407078 | Next node address : 00000000*/