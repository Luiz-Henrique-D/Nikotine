#include "lexer/lexer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <lexer/tokens.h>
int isSkippableCharacter(char c)
{
    return c == ' ' || c == '\n' || c == '\0';
}
TokenNode *head = NULL;

int isADigit(char c)
{
    return c > '0' && c < '9';
}

void grammarWrapLexically(char *src, size_t *size)
{
    for (int i = 0; i < *size; i++)
    {
        switch (src[i])
        {
        case '(':
        case ')':
            // Adiciona um token de delimitador
            char delimiter[2] = {src[i], '\0'};
            insertAtTail(&head, TOKEN_DELIMITER, strdup(delimiter));
            break;
        case '+':
        case '-':
            // Adiciona um token de operador
            char operator[2] = { src[i],
                                 '\0' };
            insertAtTail(&head, TOKEN_OPERATOR, strdup(operator));
            break;
        default:
            if (isADigit(src[i]))
            {
                // Construa o literal do número
                char buffer[256];
                int j = 0;
                while (i < *size && isADigit(src[i]))
                {
                    buffer[j++] = src[i++];
                }
                buffer[j] = '\0';
                insertAtTail(&head, TOKEN_NUMBER, strdup(buffer));
                i--; // Reajusta o índice
            }
            else if (isSkippableCharacter(src[i]))
            {
                // Ignora caracteres não relevantes
                continue;
            }
            break;
        }
    }
    printNodes(&head);
}