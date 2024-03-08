#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char rotate(char c, int key);

// int argc allows me to. type in a argument on the command line when staring the code
int main(int argc, string argv[])
{
    // commadn line input validation
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    string inputString = argv[1];
    for (int i = 0; i < strlen(inputString); i++)
    {
        if (!isdigit(inputString[i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    // atoi takes a string and converts into the number 3
    int key = atoi(argv[1]);

    // ask the user for plain text
    string plaintext = get_string("Plaintext: ");

    // encipher the text
    char result[strlen(plaintext)];

    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        result[i] = rotate(plaintext[i], key);
    }

    result[strlen(plaintext)] = '\0';

    printf("ciphertext: %s\n", result);
}

char rotate(char c, int key)
{
    // if it is a alphabet
    if (isalpha(c))
    {
        if (isupper(c)) // if upper case
        {
            // convert ascii to alphabetical index
            int alphaIndex = c - 65;

            // shift the aplhabetical index using the formula
            int cipherIndex = (alphaIndex + key) % 26;

            // convert result back to ascii
            int ciphered = cipherIndex + 65;

            return (char) ciphered;
        }
        else if (islower(c))
        {
            int alphaIndex = c - 97;

            int cipherIndex = (alphaIndex + key) % 26;

            int ciphered = cipherIndex + 97;

            return (char) ciphered;
        }
    }
    else // not alphabetical character
    {
        return c;
    }

    return c;
}
