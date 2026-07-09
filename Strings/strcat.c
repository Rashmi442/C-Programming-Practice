#include <stdio.h>
void myStrcat(char str1[], char str2[])
{
    int i = 0, j = 0;

    // Find the end of str1
    while(str1[i] != '\0')
    {
        i++;
    }

    // Copy str2 to the end of str1
    while(str2[j] != '\0')
    {
        str1[i] = str2[j];
        i++;
        j++;
    }

    // Add null character at the end
    str1[i] = '\0';
}

int main()
{
    char str1[100], str2[100];

    printf("Enter first string: ");
    scanf("%s", str1);

    printf("Enter second string: ");
    scanf("%s", str2);

    myStrcat(str1, str2);

    printf("Concatenated string is %s.\n", str1);

    return 0;
}