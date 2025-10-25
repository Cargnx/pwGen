#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pwGen.h"

#define MAX_POOL_SIZE 256

void getSecureNumber(unsigned char *buffer, size_t size)
{
    FILE *urandom = fopen("/dev/urandom", "r");

    if (!urandom)
    {
        perror("Failed to open /dev/urandom");
        exit(1);
    }

    fread(buffer, 1, size, urandom);
    fclose(urandom);
}

void pwGen(const t_Symbols *strctPtr, char *password, int length)
{
    if (length <= 0 || length > MAX_POOL_SIZE)
    {
        fprintf(stderr, "Error: Invalid password length\n");
        return;
    }

    char pool[MAX_POOL_SIZE] = {0};
    strcpy(pool, strctPtr->smallChar);
    strcat(pool, strctPtr->largeChar);
    strcat(pool, strctPtr->numbers);
    strcat(pool, strctPtr->symbols);

    const int poolSize = strlen(pool);

    for (int i = 0; i < length; ++i)
    {
        unsigned char randomByte;
        getSecureNumber(&randomByte, 1);
        password[i] = pool[randomByte % poolSize];
    }
    password[length] = '\0';
}
