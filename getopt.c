#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    // Define allowable filters
    char *filters = "bgrs";
    int opt;

    // Parse command-line options
    while ((opt = getopt(argc, argv, filters)) != -1)
    {
        switch (opt)
        {
            case 'b':
                printf("Filter 'b' selected\n");
                break;
            case 'g':
                printf("Filter 'g' selected\n");
                break;
            case 'r':
                printf("Filter 'r' selected\n");
                break;
            case 's':
                printf("Filter 's' selected\n");
                break;
            case '?':
                printf("Invalid option: %c\n", optopt);
                return 1;
        }
    }

    // Expected outcome: -1 No more options to process.
    printf("%i No more options to process.\n", opt);

    return 0;
}
