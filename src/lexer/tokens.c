#include "lexer/tokens.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void insertAtHead(TokenNode **head, TokenType type, char *value)
{
    TokenNode *newNode = createNodeToken(type, value);
    newNode->next = *head;
    *head = newNode;
}

void insertAtTail(TokenNode **head, TokenType type, char *value)
{
    TokenNode *newNode = (TokenNode *)malloc(sizeof(TokenNode));
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    TokenNode *current = *head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = newNode;
}

TokenNode *createNodeToken(TokenType type, const char *value)
{
    TokenNode *newNode = (TokenNode *)malloc(sizeof(TokenNode));
    if (newNode == NULL)
    {
        printf("Fail in memory allocation!");
        exit(1);
    }

    Token *token = (Token *)malloc(sizeof(Token));
    if (token == NULL)
    {
        printf("Fail in memory allocation!");
        exit(1);
    }
    token->type = type;
    token = value = strdup(value);
    newNode->token = token;
    newNode->next = NULL;
}