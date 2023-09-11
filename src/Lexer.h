
#ifndef COMPILER_LEXER_H
#define COMPILER_LEXER_H

#endif //COMPILER_LEXER_H

enum tokenID {
    // Valuable Types
    INT = 1,
    BOOL,
    CHAR,
    SHORT,
    LONG,
    FLOAT,
    DOUBLE,
    VOID,
    AUTO,
    ENUM,
    STRING,
    // valuable modifiers
    SIGNED = 20,
    UNSIGNED,
    STRUCT,
    STATIC,
    CONST,
    // Reserved words
    IF = 100,
    ELSE,
    RETURN,
    WHILE,
    FOR,
    BREAK,
    CONTINUE,
    SWITCH,
    CASE,
    DEFAULT,
    DO,
    GOTO,
    RETURNY,
    // Special symbols
    PLUS = 200,
    MINUS,
    TIMES,
    DIVIDE,
    EQUAL,
    LESS_THAN,
    GREATER_THAN,
    OPEN_PARENTHESIS,
    CLOSE_PARENTHESIS,
    SEMICOLON,
    OPEN_BRACKET,
    CLOSE_BRACKET,
    OPEN_BRACE,
    CLOSE_BRACE,
    COMMA,
    ASSIGNMENT,
    NOT_EQUAL,
    LESS_THAN_OR_EQUAL,
    GREATER_THAN_OR_EQUAL,
    AND,
    OR,
    NOT,
    // Other tokens
    NAME_ID_VALUABLE = 400,
    NUM,
    TRUE,
    FALSE,
    ERROR = -100
};

struct token {
    enum tokenID id;
    char *value;
    int line;
    int column;
};

struct tokenCollection {
    struct token *token;
    struct tokenCollection *next;
};

struct lexer {
    char *source;
    int index;
    int line;
    int column;
    struct tokenCollection *tokens;
};


struct token *createToken(enum tokenID id, char *value, int line, int column);

void freeToken(struct token *token);

struct lexer *createLexer(char *source);

void freeLexer(struct lexer *lexer);

struct tokenCollection *createTokenCollection(struct token *token);

void freeTokenCollection(struct tokenCollection *tokenCollection);

void addToken(struct lexer *lexer, struct token *token);

void printTokenCollection(struct tokenCollection *tokenCollection);

void printToken(struct token *token);

void printLexer(struct lexer *lexer);

struct token *getToken(struct lexer *lexer);

struct token *getNextToken(struct lexer *lexer);

struct token *getPreviousToken(struct lexer *lexer);

void nextToken(struct lexer *lexer);

void previousToken(struct lexer *lexer);

void skipComments(struct lexer *lexer);

void skipWhiteSpaces(struct lexer *lexer);

enum tokenID getID(char *value);

enum tokenID getValueableID(char *value);

enum tokenID getValueableModifierID(char *value);

enum tokenID getReservedWordID(char *value);

enum tokenID getSpaicelSymbolID(char *value);

enum tokenID getOtherTokenID(char *value);

int isNumber(struct lexer *lexer);
