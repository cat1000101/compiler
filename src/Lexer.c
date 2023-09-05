#include "Lexer.h"
#include "string.h"

int tokenID(char *token);

int isReservedWord(char *token)
{
    //INT = 0, VOID, FLOAT, IF , ELSE, RETURN, WHILE,FOR, BREAK, CONTINUE = 9,
    if (strcmp(token, "int") == 0)
        return INT;
    else if (strcmp(token, "void") == 0)
        return VOID;
    else if (strcmp(token, "float") == 0)
        return FLOAT;
    else if (strcmp(token, "if") == 0)
        return IF;
    else if (strcmp(token, "else") == 0)
        return ELSE;
    else if (strcmp(token, "return") == 0)
        return RETURN;
    else if (strcmp(token, "while") == 0)
        return WHILE;
    else if (strcmp(token, "for") == 0)
        return FOR;
    else if (strcmp(token, "break") == 0)
        return BREAK;
    else if (strcmp(token, "continue") == 0)
        return CONTINUE;
    else
        return -1;
}

int isSpecialSymbol(char *token)
{
    //PLUS = 10, MINUS, TIMES, DIVIDE, EQUAL, LESS_THAN, GREATER_THAN, OPEN_PARENTHESIS, CLOSE_PARENTHESIS, SEMICOLON, ,OPEN_BRACKET, CLOSE_BRACKET, OPEN_BRACE, CLOSE_BRACE, COMMA, ASSIGNMENT, NOT_EQUAL, LESS_THAN_OR_EQUAL, GREATER_THAN_OR_EQUAL, AND, OR, NOT = 31,
    if (strcmp(token, "+") == 0)
        return PLUS;
    else if (strcmp(token, "-") == 0)
        return MINUS;
    else if (strcmp(token, "*") == 0)
        return TIMES;
    else if (strcmp(token, "/") == 0)
        return DIVIDE;
    else if (strcmp(token, "=") == 0)
        return EQUAL;
    else if (strcmp(token, "<") == 0)
        return LESS_THAN;
    else if (strcmp(token, ">") == 0)
        return GREATER_THAN;
    else if (strcmp(token, "(") == 0)
        return OPEN_PARENTHESIS;
    else if (strcmp(token, ")") == 0)
        return CLOSE_PARENTHESIS;
    else if (strcmp(token, ";") == 0)
        return SEMICOLON;
    else if (strcmp(token, "[") == 0)
        return OPEN_BRACKET;
    else if (strcmp(token, "]") == 0)
        return CLOSE_BRACKET;
    else if (strcmp(token, "{") == 0)
        return OPEN_BRACE;
    else if (strcmp(token, "}") == 0)
        return CLOSE_BRACE;
    else if (strcmp(token, ",") == 0)
        return COMMA;
    else if (strcmp(token, "==") == 0)
        return ASSIGNMENT;
    else if (strcmp(token, "!=") == 0)
        return NOT_EQUAL;
    else if (strcmp(token, "<=") == 0)
        return LESS_THAN_OR_EQUAL;
    else if (strcmp(token, ">=") == 0)
        return GREATER_THAN_OR_EQUAL;
    else if (strcmp(token, "&&") == 0)
        return AND;
    else if (strcmp(token, "||") == 0)
        return OR;
    else if (strcmp(token, "!") == 0)
        return NOT;
    else
        return -1;
}

int isOtherToken(char *token)
{
    //NAME_ID_VALUABLE = 32, NUM, ERROR = 34
    if (isNameIDValuable(token) != -1)
        return NAME_ID_VALUABLE;
    else if (isNum(token) != -1)
        return NUM;
    else if (isError(token) != -1)
        return ERROR;
    else
        return -1;
}

int isNameIDValuable(char *token)
{
    return -1;
}

int isNum(char *token)
{
    for (int i = 0; i < strlen(token); i++)
    {
        if (token[i] < '0' || token[i] > '9')
            return -1;
    }
    return NUM;
}

int isToken(char *token)
{
    if (isReservedWord(token) != -1)
        return isReservedWord(token);
    else if (isSpecialSymbol(token) != -1)
        return isSpecialSymbol(token);
    else if (isOtherToken(token) != -1)
        return isOtherToken(token);
    else
        return -1;
}

int isError(char *token){
    return 1;
}
/*
char NextString(char* string)
{
    char* newString = string;
    int count = 0;
    while (*newString != '\0')
    {
        count++;
    }
    char returnString[count];
    for (int i = 0; i < count; i++)
    {
        returnString[i] = string[i + 1];
    }
}
*/