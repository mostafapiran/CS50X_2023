#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Definition of variables:
    int start, end, years = 0;

    // TODO: Prompt for start size
    do
    {
        start = get_int("Start llamas No: ");
    }
    while (start < 9);

    // TODO: Prompt for end size
    do
    {
        end = get_int("End llamas No: ");
    }
    while (end < start);

    // TODO: Calculate number of years until we reach threshold
    while (start < end)
    {
        start = start - (start / 4) + (start / 3);
        years++;
    }

    // TODO: Print number of years
    printf("Years: %i\n", years);
}