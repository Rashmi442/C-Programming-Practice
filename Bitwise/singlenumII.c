/*Problem
Every element appears 3 times except one.
Simple Exam Approach (Count Bits)
Count how many times each bit appears.
If count % 3 != 0, that bit belongs to the unique number.
Example
Input : [2,2,3,2]
Output: 3
*/
#include <stdio.h>

int singleNumber(int arr[], int n)
{
    int result = 0;

    for(int i = 0; i < 32; i++)
    {
        int sum = 0;

        for(int j = 0; j < n; j++)
        {
            if((arr[j] >> i) & 1)
                sum++;
        }

        if(sum % 3)
            result = result | (1 << i);
    }

    return result;
}

int main()
{
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements:\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Single Number = %d\n", singleNumber(arr, n));

    return 0;
}