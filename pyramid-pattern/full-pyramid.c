// Recreate a full pyramid in C,
// albeit in text, using hashes (#) for bricks, a la the below. 
// Each hash is a bit taller than it is wide, so the pyramid itself is also be taller than it is wide.
#include <cs50.h>
#include <stdio.h>

int get_positive_height(string prompt);
void get_hash(int i);
int main(void)
{
    int height = get_positive_height("Height: \n");
    for (int i = 1; i <= height; i++) 
    {
        for (int j = 0; j < height - i; j++) 
        {
            printf(" ");
        }
        get_hash(i);
        printf("  ");
        get_hash(i);
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
void get_hash(int i)
{
    for (int k = 0; k < i ; k++)
    {
        printf("#");
    }
}