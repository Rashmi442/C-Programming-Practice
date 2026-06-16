#include<stdio.h>
struct Node
{
    int data;
    struct Node *next;
};
int main()
{
    struct Node n;
    printf("size of Data: %zu bytes\n",sizeof(n.data));
    printf("size of pointer : %zu bytes\n",sizeof(n.next));
    printf("size of structure : %zu bytes\n",sizeof(struct Node));

}