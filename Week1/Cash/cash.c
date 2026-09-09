#include <stdio.h>

int main()
{
    int money;
    int money_left;
    int counter;

    do
    {
        printf("enter the money:\n");
        scanf("%d", &money);
    }
    while (money < 0);

    if (money == 0)
    {
        printf("0\n");
    }
    else
    {
        counter = 0;
        money_left = money;
        while (money_left != 0)
        {
            if (money_left >= 25)
            {
                counter += money_left / 25;
                money_left = money_left % 25;
            }
            if (money_left < 25 && money_left >= 10)
            {
                counter += money_left / 10;
                money_left = money_left % 10;
            }
            if (money_left < 10 && money_left >= 5)
            {
                counter += money_left / 5;
                money_left = money_left % 5;
            }
            else
            {
                counter += money_left;
                money_left = 0;
            }
        }

        printf("%d!", counter);
    }

    return 0;
}
