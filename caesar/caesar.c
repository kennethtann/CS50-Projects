#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>



int main(int argc, string argv[])
{

    int length = strlen(argv[1]);
    string input = argv[1];

    for (int i = 0; i < length; i++)
    {
        if( isdigit(input[i]) && argc == 2)
        {

        }
        else
        {
            printf("Usage: ./caesar key\n");
            exit(1);
        }
    }




string plaintext = get_string("Plaintext: ");
int lengthtext = strlen(plaintext);
printf("Ciphertext: ");
//converting ASCII to alphabetical index than ciphertext alphabetical index, then to ciphertext ASCII

    for (int y = 0; y < lengthtext; y++)
    {
        if ( isupper(plaintext[y]))
        {
            printf("%c", (((plaintext[y] - 65) + atoi(argv[1])) % 26) + 65);
        }

        else if ( islower(plaintext[y]))
        {
            printf("%c", (((plaintext[y] - 65 - 32) + atoi(argv[1])) % 26) + 65 + 32);
        }
        else
        {
            printf("%c", plaintext[y]);
        }
    }

    printf("\n");

}

