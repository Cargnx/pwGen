#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pwGen.h"

int main(void) {
    srand(time(NULL));

    const t_Symbols sym = {
        "abcdefghijklmnopqrstuvwxyz",
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ",
        "123456789",
        "!@#$%^&*()"
    };

    char password[21];
    pwGen(&sym, password, 20);

    printf("Generated password: %s\n", password);

    return 0;
}