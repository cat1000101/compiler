#include <stdio.h>
#include <string.h>
#include "Lexer.h"

int main() {
    const char *source = "int main() { return 0; }";
    InitLexer(source);
    return 0;
}
