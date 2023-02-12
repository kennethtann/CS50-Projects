#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Height = ");
    }
    while (n < 1 || n > 8);



    for (int f = 0; f < n; f++)
    {
        for (int c = 0; c < n; c++)
        {
            if (n - c > (f + 1))
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }

        }

        printf("\n");
    }


}