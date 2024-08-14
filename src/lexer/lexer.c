#include "lexer/lexer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <lexer/tokens.h>
int isSkippableCharacter(char c)
{
    return c == ' ' || c == '\n' || c == '\0';
}

void removeCurrent(char **src, int index, size_t *size)
{
    memmove(*src + index, *src + index + 1, (*size - index - 1) * sizeof(char));

    size_t new_size = *size - 1;
    char *new_array = (char *)realloc(*src, new_size * sizeof(char));
    if (new_array == NULL)
    {
        fprintf(stderr, "Falha na realocação\n");
        return;
    }
    *size = new_size;
}
void grammarWrapLexically(char *src, size_t *size)
{
}