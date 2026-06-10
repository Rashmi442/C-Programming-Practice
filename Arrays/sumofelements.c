#include <stdio.h>

int main()
{
    int n, sum = 0;

    printf("Enter size: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int *ptr = arr;

    for(int i = 0; i < n; i++)
    {
        sum = sum + *(ptr + i);
    }

    printf("Sum = %d", sum);

    return 0;
}