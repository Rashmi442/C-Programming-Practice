#include <stdio.h>

int main()
{
    char str[100], sub[100];
    int i, j, found = 0;

    printf("Enter main string: ");
    scanf("%s", str);

    printf("Enter substring: ");
    scanf("%s", sub);

    for(i = 0; str[i] != '\0'; i++)
    {
        for(j = 0; sub[j] != '\0'; j++)
        {
            if(str[i + j] != sub[j])
                break;
        }

        if(sub[j] == '\0')
        {
            found = 1;
            break;
        }
    }

    if(found)
        printf("Substring Found");
    else
        printf("Substring Not Found");

    return 0;
}