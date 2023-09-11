#include "Lexer.h"
#include <malloc.h>
#include <stdio.h>
#include <string.h>


struct token *createToken(enum tokenID id, char *value, int line, int column) {
    struct token *token = malloc(sizeof(struct token));
    token->id = id;
    token->value = value;
    token->line = line;
    token->column = column;
    return token;
}

void freeToken(struct token *token) {
    free(token->value);
    free(token);
}

struct lexer *createLexer(char *source) {
    struct lexer *lexer = malloc(sizeof(struct lexer));
    lexer->source = source;
    lexer->index = 0;
    lexer->line = 1;
    lexer->column = 1;
    return lexer;
}

void freeLexer(struct lexer *lexer) {
    free(lexer->source);
    free(lexer);
}

void printToken(struct token *token) {
    printf("Token: %d, %s, %d, %d\n", token->id, token->value, token->line, token->column);
}

void printLexer(struct lexer *lexer) {
    printf("Lexer: %s, %d, %d\n", lexer->source, lexer->line, lexer->column);
}

enum tokenID getID(char *value) {
    if (getValueableID(value))
        return getValueableID(value);
    else if (getValueableModifierID(value))
        return getValueableModifierID(value);
    else if (getReservedWordID(value))
        return getReservedWordID(value);
    else if (getSpaicelSymbolID(value))
        return getSpaicelSymbolID(value);
    else if (getOtherTokenID(value))
        return getOtherTokenID(value);
    else
        return 0;
}

enum tokenID getValueableID(char *value) {
    if (strcmp(value, "int") == 0) {
        return INT;
    } else if (strcmp(value, "char") == 0) {
        return CHAR;
    } else if (strcmp(value, "bool")) {
        return BOOL;
    } else if (strcmp(value, "float")) {
        return FLOAT;
    } else if (strcmp(value, "double")) {
        return DOUBLE;
    } else if (strcmp(value, "void")) {
        return VOID;
    } else if (strcmp(value, "auto")) {
        return AUTO;
    } else if (strcmp(value, "short")) {
        return SHORT;
    } else if (strcmp(value, "long")) {
        return LONG;
    } else if (strcmp(value, "enum")) {
        return ENUM;
    } else {
        return 0;
    }
}

enum tokenID getValueableModifierID(char *value) {
    if (strcmp(value, "signed") == 0) {
        return SIGNED;
    } else if (strcmp(value, "unsigned") == 0) {
        return UNSIGNED;
    } else if (strcmp(value, "struct") == 0) {
        return STRUCT;
    } else if (strcmp(value, "static") == 0) {
        return STATIC;
    } else if (strcmp(value, "const") == 0) {
        return CONST;
    } else {
        return 0;
    }
}

enum tokenID getReservedWordID(char *value) {
    if (strcmp(value, "if") == 0) {
        return IF;
    } else if (strcmp(value, "else") == 0) {
        return ELSE;
    } else if (strcmp(value, "return") == 0) {
        return RETURN;
    } else if (strcmp(value, "while") == 0) {
        return WHILE;
    } else if (strcmp(value, "for") == 0) {
        return FOR;
    } else if (strcmp(value, "break") == 0) {
        return BREAK;
    } else if (strcmp(value, "continue") == 0) {
        return CONTINUE;
    } else if (strcmp(value, "switch") == 0) {
        return SWITCH;
    } else if (strcmp(value, "case") == 0) {
        return CASE;
    } else if (strcmp(value, "default") == 0) {
        return DEFAULT;
    } else if (strcmp(value, "do") == 0) {
        return DO;
    } else if (strcmp(value, "goto") == 0) {
        return GOTO;
    } else if (strcmp(value, "return") == 0) {
        return RETURNY;
    } else {
        return 0;
    }
}

enum tokenID getSpaicelSymbolID(char *value) {
    if (strcmp(value, "+") == 0) {
        return PLUS;
    } else if (strcmp(value, "-") == 0) {
        return MINUS;
    } else if (strcmp(value, "*") == 0) {
        return TIMES;
    } else if (strcmp(value, "/") == 0) {
        return DIVIDE;
    } else if (strcmp(value, "=") == 0) {
        return EQUAL;
    } else if (strcmp(value, "<") == 0) {
        return LESS_THAN;
    } else if (strcmp(value, ">") == 0) {
        return GREATER_THAN;
    } else if (strcmp(value, "(") == 0) {
        return OPEN_PARENTHESIS;
    } else if (strcmp(value, ")") == 0) {
        return CLOSE_PARENTHESIS;
    } else if (strcmp(value, ";") == 0) {
        return SEMICOLON;
    } else if (strcmp(value, "[") == 0) {
        return OPEN_BRACKET;
    } else if (strcmp(value, "]") == 0) {
        return CLOSE_BRACKET;
    } else if (strcmp(value, "{") == 0) {
        return OPEN_BRACE;
    } else if (strcmp(value, "}") == 0) {
        return CLOSE_BRACE;
    } else if (strcmp(value, ",") == 0) {
        return COMMA;
    } else if (strcmp(value, "==") == 0) {
        return ASSIGNMENT;
    } else if (strcmp(value, "!=") == 0) {
        return NOT_EQUAL;
    } else if (strcmp(value, "<=") == 0) {
        return LESS_THAN_OR_EQUAL;
    } else if (strcmp(value, ">=") == 0) {
        return GREATER_THAN_OR_EQUAL;
    } else if (strcmp(value, "&&") == 0) {
        return AND;
    } else if (strcmp(value, "||") == 0) {
        return OR;
    } else if (strcmp(value, "!") == 0) {
        return NOT;
    } else {
        return 0;
    }
}

enum tokenID getOtherTokenID(char *value) {
    if (strcmp(value, "true") == 0) {
        return TRUE;
    } else if (strcmp(value, "false") == 0) {
        return FALSE;
    } else {
        return 0;
    }
}

int isNumber(struct lexer *lexer) {
    char c = lexer->source[lexer->index];
    while (c >= '0' && c <= '9') {
        lexer->index++;
        lexer->column++;
        c = lexer->source[lexer->index];
    }
    if (c == '.') {
        lexer->index++;
        lexer->column++;
        c = lexer->source[lexer->index];
        while (c >= '0' && c <= '9') {
            lexer->index++;
            lexer->column++;
            c = lexer->source[lexer->index];
        }
    }
    return lexer->index > 0;
}

struct token *getToken(struct lexer *lexer) {
    char c = lexer->source[lexer->index];
    if (c == '/' && (lexer->source[lexer->index + 1] == '/' || lexer->source[lexer->index + 1] == '*')) {
        skipComments(lexer);
        skipWhiteSpaces(lexer);
        return getToken(lexer);
    }
    if (c == "'" || c == '"') {
        int index = lexer->index;
        int line = lexer->line;
        int column = lexer->column;
        lexer->index++;
        lexer->column++;
        c = lexer->source[lexer->index];
        while (c != '\'' && c != '"') {
            lexer->index++;
            lexer->column++;
            c = lexer->source[lexer->index];
        }
        lexer->index++;
        lexer->column++;
        char *value = malloc(sizeof(char) * (lexer->index - index + 1));
        memcpy(value, lexer->source + index, (size_t) (lexer->index - index));
        value[lexer->index - index] = '\0';
        return createToken(STRING, value, line, column);
    }
    int index = lexer->index;
    int line = lexer->line;
    int column = lexer->column;
    while ((c >= 'a' && c <= 'z') ||(c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == '_') {
        lexer->index++;
        lexer->column++;
        c = lexer->source[lexer->index];
    }
    char *value = malloc(sizeof(char) * (lexer->index - index + 1));
    memcpy(value, lexer->source + index, (size_t) (lexer->index - index));
    value[lexer->index - index] = '\0';
    return createToken(getID(value), value, line, column);

}

struct token *getNextToken(struct lexer *lexer) {
    int index = lexer->index;
    int line = lexer->line;
    int column = lexer->column;
    nextToken(lexer);
    struct token *token = getToken(lexer);
    lexer->index = index;
    lexer->line = line;
    lexer->column = column;
    return token;
}

struct token *getPreviousToken(struct lexer *lexer) {
    int index = lexer->index;
    int line = lexer->line;
    int column = lexer->column;
    previousToken(lexer);
    struct token *token = getToken(lexer);
    lexer->index = index;
    lexer->line = line;
    lexer->column = column;
    return token;
}

void nextToken(struct lexer *lexer) {
    while (lexer->source[lexer->index] == ' ' || lexer->source[lexer->index] == '\t' ||
           lexer->source[lexer->index] == '\n') {
        if (lexer->source[lexer->index] == '\n') {
            lexer->line++;
            lexer->column = 1;
        } else {
            lexer->column++;
        }
        lexer->index++;
    }
}

void previousToken(struct lexer *lexer) {
    while (lexer->source[lexer->index] == ' ' || lexer->source[lexer->index] == '\t' ||
           lexer->source[lexer->index] == '\n') {
        if (lexer->source[lexer->index] == '\n') {
            lexer->line--;
            lexer->column = 1;
        } else {
            lexer->column--;
        }
        lexer->index--;
    }
}

void skipComments(struct lexer *lexer) {
    char c = lexer->source[lexer->index];
    if (c == '/') {
        lexer->index++;
        lexer->column++;
        c = lexer->source[lexer->index];
        if (c == '/') {
            lexer->index++;
            lexer->column++;
            c = lexer->source[lexer->index];
            while (c != '\n') {
                lexer->index++;
                lexer->column++;
                c = lexer->source[lexer->index];
            }
            lexer->index++;
            lexer->column++;
        } else if (c == '*') {
            lexer->index++;
            lexer->column++;
            c = lexer->source[lexer->index];
            while (c != '*') {
                lexer->index++;
                lexer->column++;
                c = lexer->source[lexer->index];
            }
            lexer->index++;
            lexer->column++;
            c = lexer->source[lexer->index];
            if (c == '/') {
                lexer->index++;
                lexer->column++;
            } else {
                printf("ERROR: Expected '/' but got '%c' at line %d, column %d\n", c, lexer->line, lexer->column);
            }
        } else {
            printf("ERROR: Expected '/' or '*' but got '%c' at line %d, column %d\n", c, lexer->line, lexer->column);
        }
    } else {
        printf("ERROR: Expected '/' but got '%c' at line %d, column %d\n", c, lexer->line, lexer->column);
    }
}


void skipWhiteSpaces(struct lexer *lexer){
    char c = lexer->source[lexer->index];
    while (c == ' ' || c == '\t' || c == '\n') {
        if (c == '\n') {
            lexer->line++;
            lexer->column = 1;
        } else {
            lexer->column++;
        }
        lexer->index++;
        c = lexer->source[lexer->index];
    }
}