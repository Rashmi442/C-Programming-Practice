#include <stdio.h>

int main()
{
    char str[100], ch;
    int i = 0, found = 0;

    printf("Enter string: ");
    scanf("%s", str);

    printf("Enter character: ");
    scanf(" %c", &ch);

    while(str[i] != '\0')
    {
        if(str[i] == ch)
        {
            printf("Found at position %d", i);
            found = 1;
            break;
        }
        i++;
    }

    if(found == 0)
        printf("Character not found");

    return 0;
}