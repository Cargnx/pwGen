#ifndef PWGEN_H
#define PWGEN_H

typedef struct symbols {
    const char* smallChar;
    const char* largeChar;
    const char* numbers;
    const char* symbols;
} t_Symbols;

void pwGen(const t_Symbols* strctPtr, char* password, int length);

#endif // PWGEN_H
