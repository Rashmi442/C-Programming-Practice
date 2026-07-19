#include <stdio.h>
#include <string.h>

int main()
{
    int x, y;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &x, &y);

    int a[x][y], b[x][y];

    printf("Enter Matrix A:\n");
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter Matrix B:\n");
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }

    char str[500];

    printf("Enter a string: ");
    scanf("%s", str);

    int pos = 0;
    int len = strlen(str);

    printf("\nOutput:\n");

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            for (int p = 0; p < x; p++)
            {
                for (int q = 0; q < y; q++)
                {
                    if (a[i][j] == b[p][q])
                    {
                        int sum = i * j * p * q;

                        printf("\nMatch: %d\n", a[i][j]);
                        printf("Sum = %d\n", sum);

                        printf("Substring: ");

                        for (int k = 0; k < sum && pos < len; k++)
                        {
                            printf("%c", str[pos]);
                            pos++;
                        }

                        printf("\n");
                        break;
                    }
                }
            }
        }
    }

    return 0;
}