#include <stdio.h>
#include <stdlib.h>
#include "parser/parser.h"

int convertToInt(char *value)
{
    return atoi(value);
}

ASTNode *createASTNumberNode(char *value)
{
    int intValue = convertToInt(value);
    ASTNode *newNode = malloc(sizeof(ASTNode));
    if (newNode == NULL)
    {
        perror("Memory allocation failed!");
    }
    newNode->value = intValue;
    newNode->type = NODE_NUMBER;
    return newNode;
}

ASTNode *createASTBinaryOP(ASTNode *left, ASTNode *right, char *op)
{
    ASTNode *newNode = malloc(sizeof(ASTNode));
    if (newNode == NULL)
    {
        perror("Memory allocation failed!");
    }
    newNode->BINARY_EXPRESSION.left = left;
    newNode->BINARY_EXPRESSION.right = right;
    newNode->BINARY_EXPRESSION.op = *op;
    newNode->type = NODE_BINARYOP;
    return newNode;
}

int precedence(char op)
{
    switch (op)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    default:
        return 0;
        break;
    }
}

TokenNode *currentTokenNode(TokenNode **tk)
{
    TokenNode *current = *tk;
    return current;
}

TokenNode *nextTokenNode(TokenNode **tk)
{
    TokenNode *current = *tk;
    if (current != NULL)
    {
        current = current->next;
        *tk = current;
    }
    return current;
}

ASTNode *parsePrimary(TokenNode **tk)
{

    TokenNode *token = currentTokenNode(tk);
    if (token == NULL)
        return NULL;

    if (token->token->type == TOKEN_NUMBER)
    {
        nextTokenNode(tk);
        return createASTNumberNode(token->token->literal);
    }
    else if (token->token->type == TOKEN_DELIMITER_PAREN_OPEN)
    {
        nextTokenNode(tk);
        ASTNode *node = parseExpression(tk);
        token = currentTokenNode(tk);

        if (token->token->type == TOKEN_DELIMITER_PAREN_CLOSE)
        {
            nextTokenNode(tk);
        }

        return node;
    }
    return NULL;
}

ASTNode *parseExpression(TokenNode **tk)
{
    ASTNode *node = parsePrimary(tk);
    if (node == NULL)
        return NULL;

    TokenNode *token = currentTokenNode(tk);

    while (token && (token->token->type == TOKEN_OPERATOR))
    {
        char *op = token->token->literal;

        nextTokenNode(tk); // Consome o operador
        ASTNode *right = parsePrimary(tk);

        if (right == NULL)
            return NULL;
        node = createASTBinaryOP(node, right, op);
        token = currentTokenNode(tk);
    }
    return node;
}

void astPrint(ASTNode *node)
{
    if (node == NULL)
        return;
    if (node->type == NODE_NUMBER)
    {
        printf("%d", node->value);
    }
    else if (node->type == NODE_BINARYOP)
    {
        printf("(");
        astPrint(node->BINARY_EXPRESSION.left);
        printf(" %c ", node->BINARY_EXPRESSION.op);
        astPrint(node->BINARY_EXPRESSION.right);
        printf(")\n");
    }
}
