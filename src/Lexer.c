#include "Lexer.h"
#include "string.h"
#include "stdio.h"
#include "stdlib.h"


void InitLexer(const char *source)
{
    const char **source1 = &source;
    while (**source1 != '\0') {
        SkipSpace(source1);
        int tokenID = GetNextToken(source1);
        NextToken(source1);
        switch (tokenID) {
            case INT:
                printf("INT\n");
                break;
            case VOID:
                printf("VOID\n");
                break;
            case FLOAT:
                printf("FLOAT\n");
                break;
            case LONG:
                printf("LONG\n");
                break;
            case DOUBLE:
                printf("DOUBLE\n");
                break;
            case CHAR:
                printf("CHAR\n");
                break;
            case SHORT:
                printf("SHORT\n");
                break;
            case BOOL:
                printf("BOOL\n");
                break;
            case AUTO:
                printf("AUTO\n");
                break;
            case ENUM:
                printf("ENUM\n");
                break;
            case SIGNED:
                printf("SIGNED\n");
                break;
            case UNSIGNED:
                printf("UNSIGNED\n");
                break;
            case STRUCT:
                printf("STRUCT\n");
                break;
            case SIZEOF:
                printf("SIZEOF\n");
                break;
            case STATIC:
                printf("STATIC\n");
                break;
            case CONST:
                printf("CONST\n");
                break;
            case IF:
                printf("IF\n");
                break;
            case ELSE:
                printf("ELSE\n");
                break;
            case RETURN:
                printf("RETURN\n");
                break;
            case WHILE:
                printf("WHILE\n");
                break;
            case FOR:
                printf("FOR\n");
                break;
            case BREAK:
                printf("BREAK\n");
                break;
            case CONTINUE:
                printf("CONTINUE\n");
                break;
            case SWITCH:
                printf("SWITCH\n");
                break;
            case CASE:
                printf("CASE\n");
                break;
            case DEFAULT:
                printf("DEFAULT\n");
                break;
            case DO:
                printf("DO\n");
                break;
            case GOTO:
                printf("GOTO\n");
                break;
            case RETURNY:
                printf("RETURNY\n");
                break;
            case PLUS:
                printf("PLUS\n");
                break;
            case MINUS:
                printf("MINUS\n");
                break;
            case TIMES:
                printf("TIMES\n");
                break;
            case DIVIDE:
                printf("DIVIDE\n");
                break;
            case EQUAL:
                printf("EQUAL\n");
                break;
            case LESS_THAN:
                printf("LESS_THAN\n");
                break;
            case GREATER_THAN:
                printf("GREATER_THAN\n");
                break;
            case OPEN_PARENTHESIS:
                printf("OPEN_PARENTHESIS\n");
                break;
            case CLOSE_PARENTHESIS:
                printf("CLOSE_PARENTHESIS\n");
                break;
            case SEMICOLON:
                printf("SEMICOLON\n");
                break;
            case OPEN_BRACKET:
                printf("OPEN_BRACKET\n");
                break;
            case CLOSE_BRACKET:
                printf("CLOSE_BRACKET\n");
                break;
            case OPEN_BRACE:
                printf("OPEN_BRACE\n");
                break;
            case CLOSE_BRACE:
                printf("CLOSE_BRACE\n");
                break;
            case COMMA:
                printf("COMMA\n");
                break;
            case ASSIGNMENT:
                printf("ASSIGNMENT\n");
                break;
            case NOT_EQUAL:
                printf("NOT_EQUAL\n");
                break;
            case LESS_THAN_OR_EQUAL:
                printf("LESS_THAN_OR_EQUAL\n");
                break;
            case GREATER_THAN_OR_EQUAL:
                printf("GREATER_THAN_OR_EQUAL\n");
                break;
            case AND:
                printf("AND\n");
                break;
            case OR:
                printf("OR\n");
                break;
            case NOT:
                printf("NOT\n");
                break;
            case NAME_ID_VALUABLE:
                printf("NAME_ID_VALUABLE\n");
                break;
            case NUM:
                printf("NUM\n");
                break;
            case ERROR:
                printf("ERROR\n");
                break;
            default:
                break;
        }
    }


    return;
}


int isValuableType(char *token)
{
    // INT = 0, VOID, FLOAT, LONG, DOUBLE, CHAR, SHORT,  BOOL, AUTO, ENUM,
    if (strcmp(token, "int") == 0)
        return INT;
    else if (strcmp(token, "void") == 0)
        return VOID;
    else if (strcmp(token, "float") == 0)
        return FLOAT;
    else if (strcmp(token, "long") == 0)
        return LONG;
    else if (strcmp(token, "double") == 0)
        return DOUBLE;
    else if (strcmp(token, "char") == 0)
        return CHAR;
    else if (strcmp(token, "short") == 0)
        return SHORT;
    else if (strcmp(token, "bool") == 0)
        return BOOL;
    else if (strcmp(token, "auto") == 0)
        return AUTO;
    else if (strcmp(token, "enum") == 0)
        return ENUM;
    else
        return -1;
}

int isValuableModifier(char *token)
{
    // SIGNED = 20, UNSIGNED, STRUCT, SIZEOF, STATIC, CONST,
    if (strcmp(token, "signed") == 0)
        return SIGNED;
    else if (strcmp(token, "unsigned") == 0)
        return UNSIGNED;
    else if (strcmp(token, "struct") == 0)
        return STRUCT;
    else if (strcmp(token, "sizeof") == 0)
        return SIZEOF;
    else if (strcmp(token, "static") == 0)
        return STATIC;
    else if (strcmp(token, "const") == 0)
        return CONST;
    else
        return -1;
}

int isReservedWord(char *token)
{
    // IF = 100, ELSE, RETURN, WHILE,FOR, BREAK, CONTINUE, SWITCH, CASE, DEFAULT, DO, GOTO, RETURNY,
    if (strcmp(token, "if") == 0)
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
    else if (strcmp(token, "switch") == 0)
        return SWITCH;
    else if (strcmp(token, "case") == 0)
        return CASE;
    else if (strcmp(token, "default") == 0)
        return DEFAULT;
    else if (strcmp(token, "do") == 0)
        return DO;
    else if (strcmp(token, "goto") == 0)
        return GOTO;
    else if (strcmp(token, "return") == 0)
        return RETURNY;
    else
        return -1;
}

int isSpecialSymbol(char *token)
{
    // PLUS = 200, MINUS, TIMES, DIVIDE, EQUAL, LESS_THAN, GREATER_THAN, OPEN_PARENTHESIS, CLOSE_PARENTHESIS, SEMICOLON,OPEN_BRACKET, CLOSE_BRACKET, OPEN_BRACE, CLOSE_BRACE, COMMA, ASSIGNMENT, NOT_EQUAL, LESS_THAN_OR_EQUAL, GREATER_THAN_OR_EQUAL, AND, OR, NOT,
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

int isToken(char *token)
{
    if (isValuableType(token) != -1)
        return isValuableType(token);
    else if (isValuableModifier(token) != -1)
        return isValuableModifier(token);
    else if (isReservedWord(token) != -1)
        return isReservedWord(token);
    else if (isSpecialSymbol(token) != -1)
        return isSpecialSymbol(token);
    else if (isOtherToken(token) != -1)
        return isOtherToken(token);
    else
        return -1;
}

int isNameIDValuable(char *token)
{
    if (getPreviousToken(&token) == ERROR)
        return -1;
    for (int i = 0; i < strlen(token); i++)
    {
        if ((token[i] < 'a' || token[i] > 'z') && (token[i] < 'A' || token[i] > 'Z') && !(token[i] < '0' || token[i] > '9') && token[i] != '_' && token[i] != '$')
            return -1;
    }
    return NAME_ID_VALUABLE;
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

void NextChar(const char **source)
{
    *source = *source + 1;
    return;
}

void NextToken(const char **source)
{
    SkipSpace(source);
    while (**source != ' ' && **source != '\t' && **source != '\n' && **source != '\0')
    {
        NextChar(source);
    }
    return;
}

int getTokenID(char *token)
{
    return isToken(token);
}

int GetNextToken(const char **source)
{
    char *token = (char *)malloc(sizeof(char) * 100);
    int i = 0;
    while (*(*source + i) == ' ' || *(*source + i) == '\t' || *(*source + i) == '\n')
        i++;

    while (**source != ' ' && **source != '\t' && **source != '\n' && **source != '\0')
    {
        token[i] = *(*source + i);
        i++;
    }
    token[i] = '\0';
    i = isToken(token);
    free(token);
    return i;
}

int getPreviousToken(const char **source)
{
    char *token = (char *)malloc(sizeof(char) * 100);
    int i = 0;
    while (*(*source - i) != ' ' && *(*source - i) != '\t' && *(*source - i) != '\n' && *(*source - i) != '\0')
    {
        i++;
    }
    for (int j = 0; j < i; j++)
    {
        token[j] = *(*source - i + j);
    }
    return getTokenID(token);
}

int SkipSpace(const char **string)
{
    while (**string == ' ' || **string == '\t' || **string == '\n')
        *string = *string + 1;
    return 0;
}

int isError(char *token)
{
    if (strcmp(token, "ERROR") == 0)
        return ERROR;
    else
        return -1;
}
