
#ifndef COMPILER_LEXER_H
#define COMPILER_LEXER_H

#endif //COMPILER_LEXER_H

enum tokenID {
    // Valuable Types
    INT = 0, VOID, FLOAT, LONG, DOUBLE, CHAR, SHORT,  BOOL, AUTO, ENUM,
    // valuable modifiers
    SIGNED = 20, UNSIGNED, STRUCT, SIZEOF, STATIC, CONST,
    // Reserved words
    IF = 100, ELSE, RETURN, WHILE,FOR, BREAK, CONTINUE, SWITCH, CASE, DEFAULT, DO, GOTO, RETURNY,
    // Special symbols
    PLUS = 200, MINUS, TIMES, DIVIDE, EQUAL, LESS_THAN, GREATER_THAN, OPEN_PARENTHESIS, CLOSE_PARENTHESIS, SEMICOLON,OPEN_BRACKET, CLOSE_BRACKET, OPEN_BRACE, CLOSE_BRACE, COMMA, ASSIGNMENT, NOT_EQUAL, LESS_THAN_OR_EQUAL, GREATER_THAN_OR_EQUAL, AND, OR, NOT,
    // Other tokens2
    NAME_ID_VALUABLE = 400, NUM, ERROR = -1
};

void InitLexer(const char *source);


void NextChar(const char **source);

void NextToken(const char **source);

int GetNextToken(const char **source);

int getPreviousToken(const char **source);

int SkipSpace(const char **string);

int getTokenID(char *token);

int isToken(char *token);

int isValuableType(char *token);

int isValuableModifier(char *token);

int isReservedWord(char *token);

int isSpecialSymbol(char *token);

int isOtherToken(char *token);

int isNameIDValuable(char *token);

int isNum(char *token);

int isError(char *token);

