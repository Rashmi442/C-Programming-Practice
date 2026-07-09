#include <stdio.h>

void myStrrev(char str[])
{
    int i = 0, j = 0;
    char temp;

    while(str[j] != '\0')
    {
        j++;
    }

    j--;

    while(i < j)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;

        i++;
        j--;
    }
}

int main()
{
    char str[100];

    printf("Enter a string: ");
    scanf("%s", str);

    myStrrev(str);

    printf("%s", str);

    return 0;
}