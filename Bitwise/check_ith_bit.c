#include<stdio.h>

int main()
{
    int n, i;

    printf("Enter number: ");
    scanf("%d", &n);

    printf("Enter bit position: ");
    scanf("%d", &i);

    if(n & (1 << i))
        printf("Bit is set");
    else
        printf("Bit is not set");

    return 0;
}