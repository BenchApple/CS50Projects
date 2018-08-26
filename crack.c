#define _XOPEN_SOURCE
#include <unistd.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

string iterate(int len, int tracker, char salt[], string toDecrypt, char solution[], char guess[])
{
    if (tracker >= len - 1) //Base case, does not return the same function.
    {
        for (int i = 'A'; i <= 'z'; i++) //Run through and test every letter.
        {
            guess[tracker] = i;

            if (strcmp(crypt(guess, salt), toDecrypt) == 0) //Check for correctness
            {
                //printf("%s\n", crypt(guess, salt));
                return guess;
            }

            if (i == 'Z') //Wrap to the lowercase characters.
            {
                i = 'a' - 1; // -1 makes sure that 'a' also gets checked.
            }
        }
        return "\0";
    }
    else //Otherwise case, will return the same function.
    {
        for (int i = 'A'; i <= 'z'; i++) //Run through and test every letter.
        {
            guess[tracker] = i; //Set the current position to the current letter.

            solution = iterate(len, tracker + 1, salt, toDecrypt, solution, guess);
            if (strcmp(solution, "\0") != 0)
            {
                return solution;
            }
            // Returns the higher levels of the recursive loop, effectively returning solutions

            if (i == 'Z') //Wrap to the lowercase characters.
            {
                i = 'a' - 1; // -1 makes sure that 'a' also gets checked.
            }
        }
        return "\0";
    }
}

int main(int arc, string argv[])
{
    if (arc == 2) //Makes sure there is only one input.
    {
        string encrypted = argv[1];

        char salt[2];
        salt[0] = encrypted[0]; //Separates the salt from the rest of the encryption.
        salt[1] = encrypted[1];

        string solution = "\0\0\0\0\0\0"; //Set up string holders.
        char guess[6] = "\0\0\0\0\0\0";

        for (int i = 1; i <= 5; i++) //Run through each of the potential lengths.
        {
            solution = iterate(i, 0, salt, encrypted, solution, guess); //Find solution.

            if (strcmp(solution, "\0") != 0)
            {
                break; //When a solution is found, break the loop for length.
            }
        }
        printf("%s\n", solution);

        return 0;
    }
    else
    {
        eprintf("ERROR: Must enter exactly one argument.\n");
        return 1;
    }
}