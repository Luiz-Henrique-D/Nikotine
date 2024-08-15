#include <stdio.h>
#include <stdlib.h>
#include "lexer/tokens.h"
typedef enum NodeType
{
    NODE_NUMBER,
    NODE_BINARYOP
} NodeType;

typedef struct ASTNode
{
    NodeType type;
    union
    {
        int value;
        struct
        {
            struct ASTNode *left;
            char op;
            struct ASTNode *right;
        } BINARY_EXPRESSION;
    };

} ASTNode;

ASTNode *parseExpression(TokenNode **tk);
void astPrint(ASTNode *node);