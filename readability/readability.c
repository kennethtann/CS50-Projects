#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    int f = 0;
    int g = 0;
    int h = 0;
    string text = get_string("Text: ");

    int letters = strlen(text);


    //to get number of letters
    for(int z = 0; z < letters; z++)
    {
        if( isalnum(text[z]))
        {
            f++;
        }

    }



    //to get number of words
    for(int x = 0; x < letters; x++)
    {
        if( isspace(text[x]))
        {
            g++;
        }
    }


    //to get number of sentences
    for(int y = 0; y < letters; y++)
    {
        if(text[y] == '.' || text[y] == '!' || text[y] == '?')
        {
            h++;
        }
    }

    //calculation
    float result = (0.0588 * f / (g + 1) * 100) - (0.296 * h / (g + 1) * 100) - 15.8;


    int index = round(result);

    //print results
    if(index  > 16)
    {
        printf("Grade 16+\n");
    }
    else if(index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }



}




