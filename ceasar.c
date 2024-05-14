#include <stdio.h>
#include "cs50.h"
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool only_digits(string s);
string encrypt(string plaintext, int k);
char rotate(char c, int k);

int main(int argc, string argv[])
{
    if (argc != 2 || only_digits(argv[1]))
    {
        printf("Usage: ./ceasar key\n");
        return 1;
    }
    int k = atoi(argv[1]);
    string plaintext = get_string("plain text: ");
    string ciphertext = encrypt(plaintext, k);
    printf("cypher text: %s\n", ciphertext);
    return 0;
}

bool only_digits(string s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (!isdigit(s[i]))
        {
            return 1;
        }
    }
    return 0;
}

string encrypt(string plaintext, int k)
{
    for (int i = 0; i < strlen(plaintext); i++)
    {
        plaintext[i] = rotate(plaintext[i], k);
    }
    return plaintext;
}

char rotate(char c, int k)
{
    if (!isalpha(c))
    {
        return c;
    }
    int remainder = k % 26;
    int total = remainder + c;
    if (c >= 'a' && total > 'z')
    {
        return (char)(total - 26);
    }
    if (c <= 'Z' && total > 'Z')
    {
        return (char)(total - 26);
    }
    return (char)total;
}