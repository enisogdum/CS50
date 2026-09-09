#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        for (int i = 0; argv[1][i] != '\0'; i++)
        {
            if (!isdigit(argv[1][i]))
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }
    }

    int key = atoi(argv[1]);
    string text = get_string("plaintext: ");

    int i = 0;

    while (text[i] != '\0')
    {
        if (isalpha(text[i]))
        {
            if (isupper(text[i]))
            {
                text[i] = ((text[i] - 'A' + key) % 26) + 'A';
            }
            else
            {
                text[i] = ((text[i] - 'a' + key) % 26) + 'a';
            }
        }
        i++;
    }

    printf("ciphertext: %s\n", text);

    return 0;
}
