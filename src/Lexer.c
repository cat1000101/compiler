#include "Lexer.h"
#include <malloc.h>
#include <stdio.h>


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

}

enum tokenID getValueableID(char *value) {

}

enum tokenID getValueableModifierID(char *value) {

}

enum tokenID getReservedWordID(char *value) {

}

enum tokenID getSpaicelSymbolID(char *value) {

}

enum tokenID getOtherTokenID(char *value) {

}