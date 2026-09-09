#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    for (int i = 0; argv[1][i] != '\0'; i++)
    {
        if (strlen(argv[1]) != 26)
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
        else if (!isalpha(argv[1][i]))
        {
            printf("Key must only contain alphabetic characters.\n");
            return 1;
        }
    }

    int i = 0;

    while (i < 26)
    {
        int j = i + 1;

        while (j < 26)
        {
            if (tolower(argv[1][i]) == tolower(argv[1][j]))
            {
                printf("Key must not contain repeated characters.\n");
                return 1;
            }

            j++;
        }

        i++;
    }

    string text = get_string("plaintext: ");
    int difference_upperlower = 'a' - 'A';

    i = 0;
    i = 0;

    while (text[i] != '\0')
    {
        if (isalpha(text[i]))
        {
            if (isupper(text[i]) && isupper(argv[1][text[i] - 'A']))
            {
                text[i] = argv[1][text[i] - 'A'];
            }
            else if (isupper(text[i]) && islower(argv[1][text[i] - 'A']))
            {
                text[i] = argv[1][text[i] - 'A'] - difference_upperlower;
            }
            else if (islower(text[i]) && isupper(argv[1][text[i] - 'a']))
            {
                text[i] = argv[1][text[i] - 'a'] + difference_upperlower;
            }
            else if (islower(text[i]) && islower(argv[1][text[i] - 'a']))
            {
                text[i] = argv[1][text[i] - 'a'];
            }
        }

        i++;
    }
    printf("ciphertext: %s\n", text);

    return 0;
}
