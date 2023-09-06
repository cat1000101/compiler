#include <stdio.h>
#include <string.h>
#include "Lexer.h"

int main() {
    const char *source = "int main() { return 0; }";
    InitLexer(source);
    printf ("hi");
    return 0;
}
