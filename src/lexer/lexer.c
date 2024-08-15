#include "lexer/lexer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils/utils.h"
#include "parser/parser.h"
TokenNode *head = NULL;

struct Parser parser;

const Token KEYWORDS[] = {
    {.type = TOKEN_KEYWORD_FUNCTION, .literal = "fun"}, {.type = TOKEN_KEYWORD_LET, .literal = "let"}};

void newToken(char *src, int index, TokenType type)
{
    char bff[2] = {src[index],
                   '\0'};
    insertAtTail(&head, TOKEN_OPERATOR, strdup(bff));
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
        case '-':
        case '/':
        case '*':
            newToken(src, i, TOKEN_OPERATOR);
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

    ASTNode *root = parseExpression(&head);
    printf("aaaaaaaaaa %d", root->value);
    astPrint(root);

    freeNodes(&head);
}