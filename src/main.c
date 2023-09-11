#include <stdio.h>
#include <string.h>
#include "Lexer.h"

int main() {
    const char *source = "int main() { return 0; }";
    struct lexer *lexer = createLexer(source);
    while (lexer->index < strlen(lexer->source)) {
        struct token *token = getToken(lexer);
        printToken(token);
        freeToken(token);
    }

    return 0;
}
