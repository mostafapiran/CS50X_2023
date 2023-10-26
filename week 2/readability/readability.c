#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    string text = get_string("Text: ");

    float l = 0;
    float w = 1;
    float s = 0;
    int n = strlen(text);
    for (int i = 0; i < n; i++)
    {
        /*way 1
        if (isalpha(text[i]) != 0)
        {
            l++;
        }
        */
        //way 2
        if ((text[i] >= 97 && text[i] <= 122) || (text[i] >= 65 && text[i] <= 90))
        {
            l++;
        }

        if (text[i] == 32)
        {
            w++;
        }

        if (text[i] == 46 || text[i] == 33 || text[i] == 63)
        {
            s++;
        }

    }
    float L = 100 * (l / w);
    float S = 100 * (s / w);
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}