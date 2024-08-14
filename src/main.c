#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lexer/lexer.h"
void inputLoop()
{
    char *input = (char *)malloc(2048);
    if (input == NULL)
    {
        fprintf(stderr, "Falha na alocação de memória\n");
        return;
    }

    while (1)
    {
        printf("Nikotine> ");

        if (fgets(input, 2048, stdin) == NULL)
        {
            fprintf(stderr, "Erro ao ler a entrada\n");
            free(input);
            return;
        }

        size_t len = strlen(input);
        if (len > 0 && input[len - 1] == '\n')
        {
            input[len - 1] = '\0';
        }
        grammarWrapLexically(input, &len);
        printf("Você digitou: %s\n", input);
    }
    free(input);
}

int main(void)
{
    puts("Nikotine version: 0.0.0.0.1");
    puts("CTRL+C to exit...");

    inputLoop();

    return 0;
}