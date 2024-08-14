#include <stdio.h>
#include "lexer/lexer.h"
void insertAtHead(TokenNode **head, TokenType type, char *value);
void insertAtTail(TokenNode **head, TokenType type, char *value);
TokenNode *createNodeToken(TokenType type, const char *value);
typedef enum TokeType
{
    TOKEN_IDENTIFIER,
    TOKEN_NUMBER,
    TOKEN_OPERATOR,
    TOKEN_DELIMITER,
    TOKEN_KEYWORD,
    TOKEN_COMMENT,
    TOKEN_EOF,
    TOKEN_UNKNOWN
} TokenType;

typedef struct
{
    TokenType type;
    char *value;
} Token;

typedef struct TokenNode
{
    Token *token;
    struct TokenNode *next;
} TokenNode;
