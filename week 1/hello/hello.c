#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //give name from user
    string name = get_string("What's your name? ");
    //print hi for user
    printf("hello, %s\n", name);
}