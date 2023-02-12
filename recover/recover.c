#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

const char *name = "card.raw";

int a = -1;
char recovered[1000];

uint8_t buffer[512];


int main(int argc, char *argv[])
{
    if (argc != 2 || (strcmp(argv[1], name) != 0))
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    FILE *card = fopen(argv[1], "r");


    if (card == NULL)
    {
        printf("Could not open file\n");
        return 1;
    }

    FILE *output = NULL;

    while (fread(buffer, sizeof(buffer), 1, card))
    {
        if ((buffer[0] == 0xff) && (buffer[1] == 0xd8) && (buffer[2] == 0xff) && ((buffer[3] & 0xf0) == 0xe0))
        {
            if (output != NULL)
            fclose(output);
            ++a;
            sprintf(recovered, "%03d.jpg", a);
            output = fopen(recovered, "w");
            if (output == NULL)
            {
                printf("Could not create file %03d/n", a);
                return 1;
            }
        }


        if (output != NULL)
        fwrite(buffer, sizeof(buffer), 1, output);
    }


    if (output != NULL)
        fclose(output);

    fclose(card);

    return 0;
}