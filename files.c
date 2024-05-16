#include <stdio.h>
#include <stdlib.h>
#include "cs50.h"

int main()
{
    FILE *file;

    // Open a file for writing
    file = fopen("dictionary.csv", "w");
    if (file == NULL)
    {
        fprintf(stderr, "Could not open file for writing\n");
        return 1;
    }

    char *engWord = get_string("English word: ");
    char *vieWord = get_string("Vietnamese word: ");

    // Write to the file
    fprintf(file, "%s: %s\n", engWord, vieWord);

    // Close the file
    fclose(file);
    return 0;
}
