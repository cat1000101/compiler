#include <stdio.h>
#include <string.h>
#include "Lexer.h"

int main() {
    const char *source = "int main() { return 0; }";
    struct lexer *lexer = createLexer(source);
    lexer->tokens = createTokenCollection(NULL);
    while (lexer->index < strlen(lexer->source)) {
        struct token *token = getToken(lexer);
        addToken(lexer, token);
        printToken(token);
        freeToken(token);
    }
    //printLexer(lexer);
    return 0;
}