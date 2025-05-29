#ifndef TOKEN_H
#define TOKEN_H

enum class TokenType {
    // keywords
    KEYWORD_LET,
    KEYWORD_CONST,
    KEYWORD_VAR,
    KEYWORD_FUNCTION,
    KEYWORD_IF,
    KEYWORD_ELSE,
    KEYWORD_FOR,
    KEYWORD_WHILE,
    KEYWORD_RETURN,
    KEYWORD_TRUE,
    KEYWORD_FALSE,
    KEYWORD_NULL,
    KEYWORD_UNDEFINED,
    KEYWORD_NEW,
    KEYWORD_THIS,
    KEYWORD_CLASS,
    KEYWORD_SUPER,
    KEYWORD_EXTENDS,
    KEYWORD_IMPORT,
    KEYWORD_DEFAULT,
    KEYWORD_ASYNC,
    KEYWORD_AWAIT,
    KEYWORD_TRY,
    KEYWORD_CATCH,
    KEYWORD_FINALLY,
    KEYWORD_THROW,
    KEYWORD_INSTANCEOF,
    KEYWORD_TYPEOF,
    KEYWORD_VOID,
    KEYWORD_DELETE,
    KEYWORD_IN,
    KEYWORD_DO,
    KEYWORD_SWITCH,
    KEYWORD_CASE,
    KEYWORD_BREAK,
    KEYWORD_CONTINUE,
    KEYWORD_DEBUGGER
    KEYWORD_WITH,
    KEYWORD_YIELD

    INDENTIFIER,
    NUMBER_LITERAL,
    STRING_LITERAL,
    BOOLEAN_LITERAL,            // true/false keyword
    NULL_LITERAL,               // keyword
    UNDEFINED_LITERAL           // keyword

    // operators
    OP_PLUS,                    // +
    OP_MINUS,                   // -
    OP_MULTIPLY,                // *
    OP_DIVIDE,                  // /
    OP_MODULE,                  // %
    OP_ASSIGN,                  // =
    OP_PLUS_ASSIGN,             // +=
    OP_MINUS_ASSIGN,            // -=
    OP_MULTIPLY_ASSIGN,         // *=
    OP_DIVIDE_ASSIGN,           // /=
    OP_MODULO_ASSIGN,           // %=
    OP_EQUAL,                   // ==
    OP_STRICT_EQUAL,            // ===
    OP_NOT_EQUAL,               // !=
    OP_STRICT_NOT_EQUAL,        // !==
    OP_LESS,                    // <
    OP_LESS_EQUAL,              // <=
    OP_GREATER,                 // >
    OP_GREATER_EQUAL,           // >=
    OP_LOGICAL_AND,             // &
    OP_LOGICAL_OR,              // ||
    OP_LOGICAL_NOT,             // !
    OP_BITWISE_AND,             // &
    OP_BITWISE_OR,              // |
    OP_BITWISE_XOR,             // ^
    OP_BITWISE_NOT,             // ~
    OP_LEFT_SHIFT,              // <<
    OP_RIGHT_SHIFT,             // >>
    OP_UNSIGNED_RIGHT_SHIFT,    // >>>
    OP_INCREMENT,               // ++
    OP_DECREMENT,               // --
    OP_QUESTION_MARK,           // ?
    OP_COLON,                   // :
    OP_SPREAD,                  // ...
    OP_OPTIONAL_CHAINING_       // ?.
    OP_NULLISH_COALESCING       // ??

    // punctuation
    PUNCT_LPAREN,               // (
    PUNCT_RPAREN,               // )
    PUNCT_LBRACE,               // {
    PUNCT_RBRACE,               // }
    PUNCT_LBRACKET,             // [
    PUNCT_RBRACKET,             // ]
    PUNCT_COMMA,                // ,
    PUNCT_SEMICOLON,            // ;
    PUNCT_DOT,                  // .

    COMMENT_SIGNLE_LINE,        // // ...
    COMMENT_MULTI_LINE,         // /* ... */
    WHITESPACE,

    END_OF_FILE,
    ERROR
};

std::string tokenTypeToString(TokenType type);

struct Token {
    TokenType type;
    std::string lexeme;
    std::string value;
    int line;
    int col;

    Token(TokenType t, std::string l, std::string v, int ln, int c)
        : type(t), lexeme(std::move(l)), value(std::move(v)), line(ln), col(c) {}
};

#endif // TOKEN_H