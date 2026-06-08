#include <stdio.h>
int singleNumber(int arr[], int n)
{
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        ans = ans ^ arr[i];
    }
    return ans;
}
int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the array elements:\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Single Number = %d", singleNumber(arr, n));
    return 0;
}