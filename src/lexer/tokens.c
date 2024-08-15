#include "lexer/tokens.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void freeNodes(TokenNode **head)
{
    TokenNode *current = *head;
    TokenNode *next;

    while (current != NULL)
    {
        next = current->next;
        free(current->token);
        free(current);
        current = next;
    }
    *head = NULL;
}

void printNodes(TokenNode **head)
{
    TokenNode *current = *head;
    while (current != NULL)
    {
        printf("Token type: %d\nToken literal: %s\n", current->token->type, current->token->literal);
        current = current->next;
    }
}
void insertAtHead(TokenNode **head, TokenType type, char *literal)
{
    TokenNode *newNode = createNodeToken(type, literal);
    newNode->next = *head;
    *head = newNode;
}
void insertAtTail(TokenNode **head, TokenType type, char *literal)
{
    TokenNode *newNode = createNodeToken(type, literal);

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
TokenNode *createNodeToken(TokenType type, char *literal)
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
    token->literal = strdup(literal);
    newNode->token = token;
    newNode->next = NULL;
    return newNode;
}