#include "lexer/lexer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <lexer/tokens.h>
TokenNode *head = NULL;

const Token KEYWORDS[] = {
    {.type = TOKEN_KEYWORD_FUNCTION, .literal = "fun"}, {.type = TOKEN_KEYWORD_LET, .literal = "let"}};

void newToken(char *src, int index, TokenType type)
{
    char bff[2] = {src[index],
                   '\0'};
    insertAtTail(&head, TOKEN_OPERATOR_ASTERISK, strdup(bff));
}

int isSkippableCharacter(char c)
{
    return c == ' ' || c == '\n' || c == '\0';
}

int isADigit(char c)
{
    return c > '0' && c < '9';
}

int isAlphabetLowerCase(char c)
{
    return c >= 'a' && c <= 'z';
}

void grammarWrapLexically(char *src, size_t *size)
{
    for (int i = 0; i < *size; i++)
    {
        switch (src[i])
        {
        case '(':
            newToken(src, i, TOKEN_DELIMITER_PAREN_OPEN);
            break;
        case ')':
            newToken(src, i, TOKEN_DELIMITER_PAREN_CLOSE);
            break;
        case '+':
            newToken(src, i, TOKEN_OPERATOR_PLUS);
            break;
        case '-':
            newToken(src, i, TOKEN_OPERATOR_MINUS);
            break;
        case '/':
            newToken(src, i, TOKEN_OPERATOR_SLASH);
            break;
        case '*':
            newToken(src, i, TOKEN_OPERATOR_ASTERISK);
            break;
        default:
            if (isAlphabetLowerCase(src[i]))
            {
                char buffer[256];
                int j = 0;
                while (i < *size && isAlphabetLowerCase(src[i]))
                {
                    buffer[j++] = src[i++];
                }
                buffer[j] = '\0';
                for (j = 0; j < sizeof(KEYWORDS) / sizeof(KEYWORDS[0]); j++)
                {

                    if (strcmp(buffer, KEYWORDS[j].literal) == 0)
                    {
                        insertAtTail(&head, KEYWORDS[j].type, strdup(buffer));
                    }
                }
                i--;
            }
            if (isADigit(src[i]))
            {
                char buffer[256];
                int j = 0;
                while (i < *size && isADigit(src[i]))
                {
                    buffer[j++] = src[i++];
                }
                buffer[j] = '\0';
                insertAtTail(&head, TOKEN_NUMBER, strdup(buffer));
                i--;
            }
            else if (isSkippableCharacter(src[i]))
            {
                continue;
            }

            break;
        }
    }
    printNodes(&head);
    freeNodes(&head);
}