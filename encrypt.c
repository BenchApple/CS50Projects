#define _XOPEN_SOURCE
#include <unistd.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int arc, string argv[])
{
    if (arc == 2)
    {
        printf("%s\n", crypt(argv[1], "aa"));
    }
}