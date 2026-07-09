#include <stdio.h>

void myStrcpy(char dest[], char src[])
{
    int i = 0;

    while(src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }

    dest[i] = '\0';
}

int main()
{
    char str1[100], str2[100];

    printf("Enter a string: ");
    scanf("%s", str1);

    myStrcpy(str2, str1);

    printf("Copied String = %s", str2);

    return 0;
}