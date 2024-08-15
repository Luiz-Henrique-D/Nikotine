#include <stdio.h>

typedef enum TokeType
{
    TOKEN_ILLEGAL = 0,
    TOKEN_EOF,
    TOKEN_IDENT,
    TOKEN_INT,

    TOKEN_DELIMITER_PAREN_OPEN,
    TOKEN_DELIMITER_PAREN_CLOSE,
    TOKEN_IDENTIFIER,
    TOKEN_NUMBER,
    TOKEN_OPERATOR,
    TOKEN_KEYWORD_LET,
    TOKEN_KEYWORD_FUNCTION,
    TOKEN_COMMENT,
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
typedef struct Parser
{
    TokenNode *tokens;
    int index;
    int count;
} Parser;
void freeNodes(TokenNode **head);
void insertAtHead(TokenNode **head, TokenType type, char *literal);
void insertAtTail(TokenNode **head, TokenType type, char *literal);
void printNodes(TokenNode **head);

TokenNode *createNodeToken(TokenType type, char *literal);
