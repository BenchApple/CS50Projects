#include <cs50.h>
#include <stdio.h>

int length(long long n) //Finds the amount of digits in a number
{
    int len = 1;

    while (n >= 10) //Finds one minus the acutal length
    {
        len++;
        n /= 10;
    }
    n++; //Adds the final length, since loop misses one digit.
    return len;
}

int expo(int base, int exponent) //Returns a number to a power
{
    long long tracker = base; //Simplifies later on
    for (int i = 0; i < exponent; i++)
    {
        tracker *= base;
    }
    return tracker;
}

bool luhn(int n[], int len) //Executes Luhns algorithm, and returns true if valid
{
    int sum = 0;

    for (int i = 0; i < len; i++) //Sums the number as described.
    {
        if (i % 2 == 1)
        {
            int findDigitsOf = 2 * n[i];
            do //Adds the digits of the doubled digits.
            {
                sum += findDigitsOf % 10;
                findDigitsOf /= 10;
            } while (findDigitsOf > 0);
        }
        else
        {
            sum += n[i];
        }
    }

    //printf("Luhn Gets executed.\n");

    if (sum % 10 == 0) //Returns True if card is valid as described.
    {
        return true;
    }
    return false;
}

char isValid(long long n)
{
    int len = length(n);

    if (len == 15 || len == 16 || len == 13) //Checks if length of number is valid for card.
    {
        int array[len]; //Chunk converts to an array.

        for (int i = 0; i < len; i++) //Singling out each digit using modulous
        {
            array[i] = n % 10;
            n /= 10;
        }

        if (luhn(array, len))
        {
            //printf("Luhn Came back as valid.\n");
            switch (array[len - 1]) //Determines which type of card, if any.
            {
                //Uses last one because switching to array turns number around.
                case 4 :
                    if (len == 13 || len == 16)
                    {
                        return 'v';
                    }
                    break;
                case 5 :
                    if ((array[len - 2] > 0 && array[len - 2] < 6) && len == 16)
                    {
                        return 'm';
                    }
                    else
                    {
                        return 'i';
                    }
                    break;
                case 3 :
                    if ((array[len - 2] == 4 || array[len - 2] == 7) && len == 15)
                    {
                        return 'a';
                    }
                    else
                    {
                        return 'i';
                    }
                    break;
                default :
                    return 'i';
            }
        }
        else
        {
            return 'i';
        }
    }
    else
    {
        return 'i';
    }



    return 0;
}

int main()
{
    long long creditNum = get_long_long("Credit Card Number: ");

    switch (isValid(creditNum)) //Prints the final verdict.
    {
        case 'i' :
            printf("INVALID\n");
            break;
        case 'a' :
            printf("AMEX\n");
            break;
        case 'm' :
            printf("MASTERCARD\n");
            break;
        case 'v' :
            printf("VISA\n");
            break;
    }
    return 0;
}