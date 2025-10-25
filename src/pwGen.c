#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pwGen.h"

void pwGen(const t_Symbols* strctPtr, char* password, int length) {
    char pool[100] = {0};
    strcpy(pool, strctPtr->smallChar);
    strcat(pool, strctPtr->largeChar);
    strcat(pool, strctPtr->numbers);
    strcat(pool, strctPtr->symbols);
    
    printf("DEBUG - Pool: %s\n", pool);
    printf("DEBUG - Pool length: %lu\n", strlen(pool)); 

    const int poolSize = strlen(pool);

    for (int i = 0; i < length; ++i) {
        const int randomIndex = rand() % poolSize;
        password[i] = pool[randomIndex];
    }
    password[length] = '\0';
}
