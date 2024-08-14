#include <stdio.h>
#include "lexer/lexer.h"

typedef enum TokeType
{
    TOKEN_DELIMITER,
    TOKEN_IDENTIFIER,
    TOKEN_NUMBER,
    TOKEN_OPERATOR,
    TOKEN_KEYWORD,
    TOKEN_COMMENT,
    TOKEN_EOF,
    TOKEN_UNKNOWN
} TokenType;

typedef struct
{
    TokenType type;
    char *literal;
} Token;

typedef struct TokenNode
{
    Token *token;
    struct TokenNode *next;
} TokenNode;

void insertAtHead(TokenNode **head, TokenType type, char *literal);
void insertAtTail(TokenNode **head, TokenType type, char *literal);
void printNodes(TokenNode **head);
TokenNode *createNodeToken(TokenType type, char *literal);
