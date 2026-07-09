#include <stdio.h>

void myStrupr(char str[])
{
    int i = 0;

    while(str[i] != '\0')
    {
        if(str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = str[i] - 32;
        }
        i++;
    }
}

int main()
{
    char str[100];

    printf("Enter string: ");
    scanf("%s", str);

    myStrupr(str);

    printf("%s", str);

    return 0;
}