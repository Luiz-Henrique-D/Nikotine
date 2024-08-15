#include <stdio.h>

int isSkippableCharacter(char c)
{
    return c == ' ' || c == '\n' || c == '\0';
}

int isADigit(char c)
{
    return c >= '0' && c <= '9';
}

int isAlphabetLowerCase(char c)
{
    return c >= 'a' && c <= 'z';
}
