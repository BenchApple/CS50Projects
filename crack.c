#define _XOPEN_SOURCE
#include <unistd.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

string iterate(const int len, int tracker, const char salt[],
               const string toDecrypt, string solution) //Second line due to monitor constraints.
{
    if (tracker >= len - 1) //Base case, does not return the same function.
    {
        for (int i = 'A'; i <= 'z'; i++) //Run through and test every letter.
        {
            solution[tracker] = i;

            if (strcmp(crypt(solution, salt), toDecrypt) == 0)
            {
                return solution;
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
            solution[tracker] = i; //Set the current position to the current letter.

            return iterate(len, tracker + 1, salt, toDecrypt, solution);
            // Returns the higher levels of the recursive loop, effectively returning solutions
        }
    }
}

string guessSolutions(int len, char salt[], string toDecrypt) //Proxy Method.
{
    //guess[len] = '\0';
    string solution = " ";
    return iterate(len, 0, salt, toDecrypt, solution);
}

int main(int arc, string argv[])
{
    if (arc == 2) //Makes sure there is only one input.
    {
        string encrypted = argv[1];

        char salt[2];
        salt[0] = encrypted[0]; //Separates the salt from the rest of the encryption.
        salt[1] = encrypted[1];

        string solution = " ";
        for (int i = 1; i <= 5; i++)
        {
            solution = guessSolutions(i, salt, encrypted);
            printf("%s\n", solution);
        }

        return 0;
    }
    else
    {
        eprintf("ERROR: Must enter exactly one argument.\n");
        return 1;
    }
}


