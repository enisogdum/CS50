#include <cs50.h>
#include <stdio.h>

int main()
{

    int i, j;
    int digit_number;
    int sum;
    int num;
    char new_number[100];
    string number = get_string("Number: ");

    i = 0;
    j = 0;
    while (number[i] != '\0')
    {
        if (number[i] != '-')
        {
            new_number[j] = number[i];
            j++;
        }

        i++;
    }
    new_number[j] = '\0';
    digit_number = j;

    sum = 0;

    while (digit_number > 1)
    {
        if ((2 * (new_number[digit_number - 2] - '0')) >= 10)
        {
            sum += (2 * (new_number[digit_number - 2] - '0')) % 10 + 1;
        }
        else
        {
            sum += (2 * (new_number[digit_number - 2] - '0'));
        }
        digit_number = digit_number - 2;
    }

    digit_number = j;

    while (digit_number > 0)
    {
        sum += new_number[digit_number - 1] - '0';
        digit_number = digit_number - 2;
    }

    if (sum % 10 == 0)
    {
        if ((new_number[0]) - '0' == 4 && (j == 13 || j == 16))
        {
            printf("VISA\n");
        }
        else
        {
            num = (new_number[0] - '0') * 10 + ((new_number[1]) - '0');
            if (j == 15 && (num == 34 || num == 37))
            {
                printf("AMEX\n");
            }
            else if (j == 16 && (num >= 51 && num <= 55))
            {
                printf("MASTERCARD\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
    }
    else
    {
        printf("INVALID\n");
    }

    return 0;
}
