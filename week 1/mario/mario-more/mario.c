#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Definition of variables:
    int h;

    //give height
    do
    {
        h = get_int("Height: ");
    }
    while (h < 1 || h > 8);

    //plot 
    for (int i = 0; i < h; i++)
    {
        for (int j = (h - 1); j > i; j--)
        {
            printf(" ");
        }

        for (int k = 0; k <= i; k++)
        {
            printf("#");
        }

        printf("  ");

        for (int l = 0; l <= i; l++)
        {
            printf("#");
        }

        printf("\n");
    }
}