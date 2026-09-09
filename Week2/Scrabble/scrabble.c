#include <cs50.h>
#include <stdio.h>

int main()
{
    int point1, point2;
    int numbers[] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                     1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    point1 = 0;
    point2 = 0;

    int i = 0;

    while (word1[i] != '\0')
    {
        if (word1[i] < 'a' && (word1[i] >= 'A'))
        {
            point1 += numbers[word1[i] - 'A'];
        }
        else if (word1[i] >= 'a' && (word1[i] <= 'z'))
        {
            point1 += numbers[word1[i] - 'a'];
        }
        i++;
    }
    i = 0;
    while (word2[i] != '\0')
    {
        if (word2[i] < 'a' && (word2[i] >= 'A'))
        {
            point2 += numbers[word2[i] - 'A'];
        }
        else if (word2[i] >= 'a' && (word2[i] <= 'z'))
        {
            point2 += numbers[word2[i] - 'a'];
        }
        i++;
    }

    if (point1 > point2)
    {
        printf("Player 1 wins!");
    }
    else if (point2 > point1)
    {
        printf("Player 2 wins!");
    }
    else
    {
        printf("Tie");
    }

    return 0;
}
