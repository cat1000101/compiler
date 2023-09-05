
#ifndef COMPILER_LEXER_H
#define COMPILER_LEXER_H

#endif //COMPILE_LEXER_H

enum tokenID {
    // Reserved words
    INT = 0, VOID, FLOAT, IF , ELSE, RETURN, WHILE,FOR, BREAK, CONTINUE = 9,
    // Special symbols
    PLUS = 10, MINUS, TIMES, DIVIDE, EQUAL, LESS_THAN, GREATER_THAN, OPEN_PARENTHESIS, CLOSE_PARENTHESIS, SEMICOLON, ,OPEN_BRACKET, CLOSE_BRACKET, OPEN_BRACE, CLOSE_BRACE, COMMA, ASSIGNMENT, NOT_EQUAL, LESS_THAN_OR_EQUAL, GREATER_THAN_OR_EQUAL, AND, OR, NOT = 31,
    // Other tokens
    NAME_ID_VALUABLE = 32, NUM, ERROR = 34
};

int tokenID(char *token);

int isReservedWord(char *token);

int isSpecialSymbol(char *token);

int isOtherToken(char *token);

int isNameIDValuable(char *token);

int isNum(char *token);

int isError(char *token);

int isToken(char *token);

char NextChar(char *string);