#include <cs50.h>
#include <stdio.h>

int getHeight() //Get the users desired pyramid height.
{
    int height = 0;
    height = get_int("Height of the Half Pyramids: ");
    while (height > 23 || height < 0)
    {
        height = get_int("Height of the Half Pyramids: ");
    }
    return height;
}


int main()
{
    //int gap = 2;
    int height = getHeight(); //Set users desired pyramid height.

    for (int i = 1; i <= height; i++) //Go through each line and print, vertical
    {
        for (int j = 0; j < height; j++) //Horizantal, first half pyramid
        {
            if (j < height - i)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }

        //for (int j = 0; j < height / 2; j++)
        //{
        //    printf(" ");
        //}
        printf("  "); //Prints the spaces in between the two halves.

        for (int j = 0; j < height; j++) //Horizantal, second half pyramid
        {
            if (j <= i - 1)
            {
                printf("#");
            }
        }
        printf("\n");
    }
}