#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pwGen.h"

#define PASSWORD_LENGTH 20

int main(void)
{
    srand(time(NULL));

    const t_Symbols sym = {
        "abcdefghijklmnopqrstuvwxyz",
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ",
        "123456789",
        "!@#$%^&*()"};

    char password[PASSWORD_LENGTH + 1];
    pwGen(&sym, password, 20);

    printf("Generated password: %s\n", password);

    return 0;
}