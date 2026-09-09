#include <stdio.h>

int main()
{
    int height;
    int i, j;

    do
    {
        printf("enter the height:\n");
        scanf("%d", &height);
    }
    while (height <= 0 || height >= 9);

    for (i = 0; i < height; i++)
    {
        for (j = 0; j < height - i - 1; j++)
        {
            printf(" ");
        }
        for (j = 0; j < i + 1; j++)
        {
            printf("#");
        }

        printf("\n");
    }
}
