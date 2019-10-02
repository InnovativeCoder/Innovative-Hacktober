// Recreate a half pyramid in C,
// albeit in text, using hashes (#) for bricks, a la the below. 
// Each hash is a bit taller than it is wide, so the pyramid itself is also be taller than it is wide.

#include <cs50.h>
#include <stdio.h>

int get_positive_height(string prompt);

int main(void)
{
    int height = get_positive_height("Height: \n");
    for (int i = 1; i <= height; i++) 
    {
        for (int j = 1; j <= height - i; j++) 
        {
            printf(" ");
        }
        for (int k = 1; k <= i ; k++) 
        {
            printf("#");
        }
        printf("\n");
    }
}

int get_positive_height(string prompt)
{
    int height;
    do
    {
        height = get_int("%s", prompt);
    }
    while (height < 1 || height > 8);
    return height;
}