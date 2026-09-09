#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Accept a single command-line argument
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    // Open the memory card
    FILE *card = fopen(argv[1], "r");

    if (card == NULL)
    {
        printf("Could not open %s.\n", argv[1]);
        return 1;
    }
    

    // Create a buffer for a block of data
    uint8_t buffer[512];
    FILE *current_file = NULL;
    int count_jpeg = 0;
    char name_jpeg[100];

    // While there's still data left to read from the memory card
    while (fread(buffer, 1, 512, card) == 512)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && ((buffer[3] & 0xf0) == 0xe0))
        {
            if (count_jpeg == 0)
            {
                sprintf(name_jpeg,"%03i.jpg",count_jpeg);
                FILE *outptr = fopen(name_jpeg,"w");
                if (outptr == NULL)
                {
                    printf("Could not open %s.\n", name_jpeg);
                    return 1;
                }
                current_file = outptr;
                fwrite(buffer, 1, 512, outptr);
                count_jpeg++;
            }
            else
            {
                fclose(current_file);
                sprintf(name_jpeg,"%03i.jpg",count_jpeg);
                FILE *outptr = fopen(name_jpeg,"w");
                if (outptr == NULL)
                {
                    printf("Could not open %s.\n", name_jpeg);
                    return 1;
                }
                current_file = outptr;
                fwrite(buffer, 1, 512, outptr);
                count_jpeg++;
            }
            
        }
        else if (count_jpeg > 0)
        {
            fwrite(buffer, 1, 512, current_file);
        }
        
    }
    fclose(card);

    if (current_file != NULL)
    {
        fclose(current_file);
    }
    

    return 0;
}