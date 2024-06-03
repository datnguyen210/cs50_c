#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

typedef BYTE BLOCK[512];

int main(int argc, char *argv[])
{
 // Check command-line arguments
    if (argc != 2)
    {
        printf("Usage: ./recover file_name.jpeg\n");
        return 1;
    }
    FILE* input = fopen(argv[1], "rb");
    if (input == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", argv[1]);
        return 1;
    }
    BLOCK buffer;
    int file_counter = 0;
    FILE* output = NULL;
    while (fread(buffer, sizeof(BYTE), 512, input) == 512)
    {
        if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if(output != NULL)
            {
                fclose(output);
            }
            char file_name[10];
            sprintf(file_name, "%03d.jpeg", file_counter);
            output = fopen(file_name, "wb");
            if (output == NULL)
            {
                fprintf(stderr, "Could not create output file.\n");
                fclose(input);
                return 2;
            }
            file_counter++;
        }
        if(output != NULL)
        {
            fwrite(buffer, sizeof(BYTE), 512, output);
        }
    }
    if(output != NULL)
    {
        fclose(output);
    }
    fclose(input);

    return 0;
}