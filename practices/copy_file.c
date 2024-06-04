#include <stdio.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    FILE *srcFile = fopen(argv[1], "rb"); // read binary the first file
    FILE *dstFile = fopen(argv[2], "wb"); // write binary the second file

    BYTE b;

    while (fread(&b, sizeof(b), 1, srcFile) != 0)
    {
        fwrite(&b, sizeof(b), 1, dstFile);
    }

    fclose(srcFile);
    fclose(dstFile);
}

// Syntax of C fread():
// size_t fread(void * buffer, size_t size, size_t count, FILE * stream);
// buffer: It refers to the pointer to the buffer memory block where the data read will be stored.
// size: It refers to the size of each element in bytes.
// count: It refers to the count of elements to be read.
// stream: It refers to the pointer to the file stream.

// Syntax of C fwrite()
// size_t fwrite(const void *ptr, size_t size, size_t count, FILE *stream)
// ptr − This is the pointer to the array of elements to be written.
// size − This is the size in bytes of each element to be written.
// count − This is the count of elements,each one with a size of size bytes
// stream − This is the pointer to a FILE object that specifies an output stream.