#include <stdio.h>

int myStrcmp(char str1[], char str2[])
{
    int i = 0;

    while(str1[i] == str2[i])
    {
        if(str1[i] == '\0')
            return 0;

        i++;
    }

    return str1[i] - str2[i];
}

int main()
{
    char str1[100], str2[100];

    printf("Enter first string: ");
    scanf("%s", str1);

    printf("Enter second string: ");
    scanf("%s", str2);

    if(myStrcmp(str1, str2) == 0)
        printf("Strings are Equal");
    else
        printf("Strings are Not Equal");

    return 0;
}