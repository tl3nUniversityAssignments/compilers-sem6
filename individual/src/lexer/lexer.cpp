#include "lexer.h"
#include <cctype>
#include <vector>

std::string tokenTypeToString(TokenType type) {
    switch (type) {
        case TokenType::KEYWORD_LET: return "KEYWORD_LET";
        case TokenType::KEYWORD_CONST: return "KEYWORD_CONST";
        case TokenType::KEYWORD_VAR: return "KEYWORD_VAR";
        case TokenType::KEYWORD_FUNCTION: return "KEYWORD_FUNCTION";
        case TokenType::KEYWORD_IF: return "KEYWORD_IF";
        case TokenType::KEYWORD_ELSE: return "KEYWORD_ELSE";
        case TokenType::KEYWORD_FOR: return "KEYWORD_FOR";
        case TokenType::KEYWORD_WHILE: return "KEYWORD_WHILE";
        case TokenType::KEYWORD_RETURN: return "KEYWORD_RETURN";
        case TokenType::KEYWORD_TRUE: return "KEYWORD_TRUE";
        case TokenType::KEYWORD_FALSE: return "KEYWORD_FALSE";
        case TokenType::KEYWORD_NULL: return "KEYWORD_NULL";
        case TokenType::KEYWORD_UNDEFINED: return "KEYWORD_UNDEFINED";
        case TokenType::KEYWORD_NEW: return "KEYWORD_NEW";
        case TokenType::KEYWORD_THIS: return "KEYWORD_THIS";
        case TokenType::KEYWORD_CLASS: return "KEYWORD_CLASS";
        case TokenType::KEYWORD_SUPER: return "KEYWORD_SUPER";
        case TokenType::KEYWORD_EXTENDS: return "KEYWORD_EXTENDS";
        case TokenType::KEYWORD_IMPORT: return "KEYWORD_IMPORT";
        case TokenType::KEYWORD_EXPORT: return "KEYWORD_EXPORT";
        case TokenType::KEYWORD_DEFAULT: return "KEYWORD_DEFAULT";
        case TokenType::KEYWORD_ASYNC: return "KEYWORD_ASYNC";
        case TokenType::KEYWORD_AWAIT: return "KEYWORD_AWAIT";
        case TokenType::KEYWORD_TRY: return "KEYWORD_TRY";
        case TokenType::KEYWORD_CATCH: return "KEYWORD_CATCH";
        case TokenType::KEYWORD_FINALLY: return "KEYWORD_FINALLY";
        case TokenType::KEYWORD_THROW: return "KEYWORD_THROW";
        case TokenType::KEYWORD_INSTANCEOF: return "KEYWORD_INSTANCEOF";
        case TokenType::KEYWORD_TYPEOF: return "KEYWORD_TYPEOF";
        case TokenType::KEYWORD_VOID: return "KEYWORD_VOID";
        case TokenType::KEYWORD_DELETE: return "KEYWORD_DELETE";
        case TokenType::KEYWORD_IN: return "KEYWORD_IN";
        case TokenType::KEYWORD_DO: return "KEYWORD_DO";
        case TokenType::KEYWORD_SWITCH: return "KEYWORD_SWITCH";
        case TokenType::KEYWORD_CASE: return "KEYWORD_CASE";
        case TokenType::KEYWORD_BREAK: return "KEYWORD_BREAK";
        case TokenType::KEYWORD_CONTINUE: return "KEYWORD_CONTINUE";
        case TokenType::KEYWORD_DEBUGGER: return "KEYWORD_DEBUGGER";
        case TokenType::KEYWORD_WITH: return "KEYWORD_WITH";
        case TokenType::KEYWORD_YIELD: return "KEYWORD_YIELD";

        case TokenType::IDENTIFIER: return "IDENTIFIER";
        case TokenType::NUMBER_LITERAL: return "NUMBER_LITERAL";
        case TokenType::STRING_LITERAL: return "STRING_LITERAL";
        case TokenType::BOOLEAN_LITERAL: return "BOOLEAN_LITERAL";
        case TokenType::NULL_LITERAL: return "NULL_LITERAL";
        case TokenType::UNDEFINED_LITERAL: return "UNDEFINED_LITERAL";

        case TokenType::OP_PLUS: return "OP_PLUS";
        case TokenType::OP_MINUS: return "OP_MINUS";
        case TokenType::OP_MULTIPLY: return "OP_MULTIPLY";
        case TokenType::OP_DIVIDE: return "OP_DIVIDE";
        case TokenType::OP_MODULO: return "OP_MODULO";
        case TokenType::OP_ASSIGN: return "OP_ASSIGN";
        case TokenType::OP_PLUS_ASSIGN: return "OP_PLUS_ASSIGN";
        case TokenType::OP_MINUS_ASSIGN: return "OP_MINUS_ASSIGN";
        case TokenType::OP_MULTIPLY_ASSIGN: return "OP_MULTIPLY_ASSIGN";
        case TokenType::OP_DIVIDE_ASSIGN: return "OP_DIVIDE_ASSIGN";
        case TokenType::OP_MODULO_ASSIGN: return "OP_MODULO_ASSIGN";
        case TokenType::OP_EQUAL: return "OP_EQUAL";
        case TokenType::OP_STRICT_EQUAL: return "OP_STRICT_EQUAL";
        case TokenType::OP_NOT_EQUAL: return "OP_NOT_EQUAL";
        case TokenType::OP_STRICT_NOT_EQUAL: return "OP_STRICT_NOT_EQUAL";
        case TokenType::OP_LESS: return "OP_LESS";
        case TokenType::OP_LESS_EQUAL: return "OP_LESS_EQUAL";
        case TokenType::OP_GREATER: return "OP_GREATER";
        case TokenType::OP_GREATER_EQUAL: return "OP_GREATER_EQUAL";
        case TokenType::OP_LOGICAL_AND: return "OP_LOGICAL_AND";
        case TokenType::OP_LOGICAL_OR: return "OP_LOGICAL_OR";
        case TokenType::OP_LOGICAL_NOT: return "OP_LOGICAL_NOT";
        case TokenType::OP_BITWISE_AND: return "OP_BITWISE_AND";
        case TokenType::OP_BITWISE_OR: return "OP_BITWISE_OR";
        case TokenType::OP_BITWISE_XOR: return "OP_BITWISE_XOR";
        case TokenType::OP_BITWISE_NOT: return "OP_BITWISE_NOT";
        case TokenType::OP_LEFT_SHIFT: return "OP_LEFT_SHIFT";
        case TokenType::OP_RIGHT_SHIFT: return "OP_RIGHT_SHIFT";
        case TokenType::OP_UNSIGNED_RIGHT_SHIFT: return "OP_UNSIGNED_RIGHT_SHIFT";
        case TokenType::OP_INCREMENT: return "OP_INCREMENT";
        case TokenType::OP_DECREMENT: return "OP_DECREMENT";
        case TokenType::OP_QUESTION_MARK: return "OP_QUESTION_MARK";
        case TokenType::OP_COLON: return "OP_COLON";
        case TokenType::OP_SPREAD: return "OP_SPREAD";
        case TokenType::OP_OPTIONAL_CHAINING: return "OP_OPTIONAL_CHAINING";
        case TokenType::OP_NULLISH_COALESCING: return "OP_NULLISH_COALESCING";

        case TokenType::PUNCT_LPAREN: return "PUNCT_LPAREN";
        case TokenType::PUNCT_RPAREN: return "PUNCT_RPAREN";
        case TokenType::PUNCT_LBRACE: return "PUNCT_LBRACE";
        case TokenType::PUNCT_RBRACE: return "PUNCT_RBRACE";
        case TokenType::PUNCT_LBRACKET: return "PUNCT_LBRACKET";
        case TokenType::PUNCT_RBRACKET: return "PUNCT_RBRACKET";
        case TokenType::PUNCT_COMMA: return "PUNCT_COMMA";
        case TokenType::PUNCT_SEMICOLON: return "PUNCT_SEMICOLON";
        case TokenType::PUNCT_DOT: return "PUNCT_DOT";

        case TokenType::COMMENT_SIGNLE_LINE: return "COMMENT_SIGNLE_LINE";
        case TokenType::COMMENT_MULTI_LINE: return "COMMENT_MULTI_LINE";
        case TokenType::WHITESPACE: return "WHITESPACE";

        case TokenType::END_OF_FILE: return "END_OF_FILE";
        case TokenType::ERROR: return "ERROR";
    }
    return "UNKNOWN_TOKEN_TYPE";
}

Lexer::Lexer(const std::string& source) : source_code(source) {
    keywords["let"] = TokenType::KEYWORD_LET;
    keywords["const"] = TokenType::KEYWORD_CONST;
    keywords["var"] = TokenType::KEYWORD_VAR;
    keywords["function"] = TokenType::KEYWORD_FUNCTION;
    keywords["if"] = TokenType::KEYWORD_IF;
    keywords["else"] = TokenType::KEYWORD_ELSE;
    keywords["for"] = TokenType::KEYWORD_FOR;
    keywords["while"] = TokenType::KEYWORD_WHILE;
    keywords["return"] = TokenType::KEYWORD_RETURN;
    keywords["true"] = TokenType::KEYWORD_TRUE;
    keywords["false"] = TokenType::KEYWORD_FALSE;
    keywords["null"] = TokenType::KEYWORD_NULL;
    keywords["undefined"] = TokenType::KEYWORD_UNDEFINED;
    keywords["new"] = TokenType::KEYWORD_NEW;
    keywords["this"] = TokenType::KEYWORD_THIS;
    keywords["class"] = TokenType::KEYWORD_CLASS;
    keywords["super"] = TokenType::KEYWORD_SUPER;
    keywords["extends"] = TokenType::KEYWORD_EXTENDS;
    keywords["import"] = TokenType::KEYWORD_IMPORT;
    keywords["export"] = TokenType::KEYWORD_EXPORT;
    keywords["default"] = TokenType::KEYWORD_DEFAULT;
    keywords["async"] = TokenType::KEYWORD_ASYNC;
    keywords["await"] = TokenType::KEYWORD_AWAIT;
    keywords["try"] = TokenType::KEYWORD_TRY;
    keywords["catch"] = TokenType::KEYWORD_CATCH;
    keywords["finally"] = TokenType::KEYWORD_FINALLY;
    keywords["throw"] = TokenType::KEYWORD_THROW;
    keywords["instanceof"] = TokenType::KEYWORD_INSTANCEOF;
    keywords["typeof"] = TokenType::KEYWORD_TYPEOF;
    keywords["void"] = TokenType::KEYWORD_VOID;
    keywords["delete"] = TokenType::KEYWORD_DELETE;
    keywords["in"] = TokenType::KEYWORD_IN;
    keywords["do"] = TokenType::KEYWORD_DO;
    keywords["switch"] = TokenType::KEYWORD_SWITCH;
    keywords["case"] = TokenType::KEYWORD_CASE;
    keywords["break"] = TokenType::KEYWORD_BREAK;
    keywords["continue"] = TokenType::KEYWORD_CONTINUE;
    keywords["debugger"] = TokenType::KEYWORD_DEBUGGER;
    keywords["with"] = TokenType::KEYWORD_WITH;
    keywords["yield"] = TokenType::KEYWORD_YIELD;
}

char Lexer::peek(size_t offset) const {
    if (current_pos + offset >= source_code.length()) {
        return '\0'; // eof
    }
    return source_code[current_pos + offset];
}

char Lexer::advance() {
    char current_char = source_code[current_pos];
    current_pos++;
    update_position(current_char);
    return current_char;
}

void Lexer::update_position(char c) {
    if (c == '\n') {
        current_line++;
        current_col = 1;
    } else {
        current_col++;
    }
}

bool Lexer::match(char expected) {
    if (is_at_end() || peek() != expected) {
        return false;
    }
    current_pos++;
    update_position(expected);
    return true;
}

bool Lexer::is_at_end() const {
    return current_pos >= source_code.length();
}

Token Lexer::make_error_token(const std::string& message) {
    return Token(TokenType::ERROR, message, message, current_line, current_col - message.length());
}

void Lexer::skip_whitespaces_and_comments() {
    while(!is_at_end()) {
        char c = peek();
        if (std::isspace(c)) {
            advance();
        } else if(c == '/' && peek(1) == '/') {
            scan_comment_single_line();
        } else if(c == '/' && peek(1) == '*') {
            scan_comment_multi_line();
        } else {
            break;
        }
    }
}

std::vector<Token> Lexer::tokenize() {
    std::vector<Token> tokens;
    while (!is_at_end()) {
        skip_whitespaces_and_comments();

        if (is_at_end()) break;

        char current_char = peek();
        int start_line = current_line;
        int start_col = current_col;

        if (std::isalpha(current_char) || current_char == '_' || current_char == '$') {
            tokens.push_back(scan_identifier_or_keyword());
        } else if (std::isdigit(current_char)) {
            tokens.push_back(scan_number_literal());
        } else if (current_char == '"' || current_char == '\'') {
            tokens.push_back(scan_string_literal(current_char));
        } else {
            Token op_or_punct = scan_operator_or_punctuator();
            if (op_or_punct.type != TokenType::ERROR) {
                tokens.push_back(op_or_punct);
            } else {
                std::string lexeme_str;
                lexeme_str += advance();
                tokens.push_back(Token(TokenType::ERROR, lexeme_str, "Unknown character", start_line, start_col));
            }
        }
    }
    tokens.push_back(Token(TokenType::END_OF_FILE, "", "", current_line, current_col));
    return tokens;
}

/**
 *  S_START: starting state.
 *  S_IDENT: reading identifier symbols.
 *
 *  S_START -- [a-zA-Z_$]       ---> S_IDENT
 *  S_IDENT -- [a-zA-Z0-0_$]    ---> S_IDENT
 *  S_IDENT -- other symbol     ---> ACCEPT
 *  S_START -- other symbol     ---> REJECT
 */
Token Lexer::scan_identifier_or_keyword() {
    std::string lexeme;
    int start_line = current_line;
    int start_col = current_col;

    // S_START ---> S_IDENT
    lexeme += advance();

    // S_IDENT
    while (!is_at_end() && (std::isalnum(peek()) || peek() == '_' || peek() == '$')) {
        lexeme += advance();
    }

    // ACCEPT
    auto it = keywords.find(lexeme);
    if (it != keywords.end()) {
        return Token(it->second, lexeme, lexeme, start_line, start_col);
    }

    return Token(TokenType::IDENTIFIER, lexeme, lexeme, start_line, start_col);
}

/**
 * S_START: starting state.
 * S_INT_PART: reading int part.
 * S_FRAC_PART_DOT: reading dot.
 * S_FRAC_PART: reading fraction.
 *
 * S-START -- [0-9] ---> S_INT_PART
 * S_INT_PART -- [0-9] ---> S_INT_PART
 * S_INT_PART -- other symbol ---> ACCEPT
 * S_FRAC_PART_DOT -- [0-9] ---> S_FRAC_PART
 * S_FRAC_PART_DOT -- other symbol ---> REJECT/ERROR
 * S_FRAC_PART -- [0-9] ---> S_FRAC_PART
 * S_FRAC_PART -- other symbol ---> ACCEPT
 */
Token Lexer::scan_number_literal() {
    std::string lexeme;
    int start_line = current_line;
    int start_col = current_col;
    bool has_dot = false;

    // S_START -> S_INT_PART
    while (!is_at_end() && std::isdigit(peek())) {
        lexeme += advance();
    }

    // S_INT_PART -> S_FRAC_PART_DOT
    if (!is_at_end() && peek() == '.') {
        if (std::isdigit(peek(1))) {
            lexeme += advance();
            has_dot = true;
            // S_FRAC_PART_DOT -> S_FRAC_PART
            while (!is_at_end() && std::isdigit(peek())) {
                lexeme += advance();
            }
        }
    }

    return Token(TokenType::NUMBER_LITERAL, lexeme, lexeme, start_line, start_col);
}

/**
 * S_START: starting state.
 * S_IN_STRING: reading symbols inside string.
 * S_ESCAPE: found backslash (start of escape sequence).
 *
 * S_START -- [",' ] --> S_IN_STRING
 * S_IN_STRING -- not [",' ] and not '\' --> S_IN_STRING
 * S_IN_STRING -- '\' --> ESCAPE
 * S_IN_STRING -- closing [", '] of the same type --> ACCEPT
 * S_IN_STRING -- EOF or '\n' --> ERROR
 * S_ESCAPE -- any symbol ---> S_IN_STRING
 * S_ESCAPE -- EOF ---> ERROR
*/
Token Lexer::scan_string_literal(char quote_type) {
    std::string lexeme;
    std::string value;
    int start_line = current_line;
    int start_col = current_col;

    lexeme += advance();

    // S_IN_STRING
    while (!is_at_end() && peek() != quote_type) {
        char current_char = peek();
        if (current_char == '\0') {
            lexeme += value;
            return Token(TokenType::ERROR, lexeme, "Unterminated string literal", start_line, start_col);
        }
        if (current_char == '\n') {
            lexeme += value;
            return Token(TokenType::ERROR, lexeme, "Unterminated string literal (newline in string)", start_line, start_col);
        }

        if (current_char == '\\') { // S_ESCAPE
            lexeme += advance();
            if (is_at_end()) {
                return Token(TokenType::ERROR, lexeme, "Unterminated string literal (EOF)", start_line, start_col);
            }
            char escaped_char = advance();
            lexeme += escaped_char;
            switch (escaped_char) {
                // not a full list of escaped characters, but can be added
                case 'n': value += '\n'; break;
                case 't': value += '\t'; break;
                case 'r': value += '\r'; break;
                case '\\': value += '\\'; break;
                case '\'': value += '\''; break;
                case '"': value += '"'; break;
                default: value += escaped_char;
            } 
        } else {
            char c = advance();
            lexeme += c;
            value += c;
        }
    }

    if (is_at_end()) {
        return Token(TokenType::ERROR, lexeme, "Unterminated string literal", start_line, start_col);
    }

    lexeme += advance();
    // ACCEPT
    return Token(TokenType::STRING_LITERAL, lexeme, value, start_line, start_col);
}

Token Lexer::scan_operator_or_punctuator() {
    int start_line = current_line;
    int start_col = current_col;
    char c = advance();

    switch (c) {
        case '(': return Token(TokenType::PUNCT_LPAREN, "(", "(", start_line, start_col);
        case ')': return Token(TokenType::PUNCT_RPAREN, ")", ")", start_line, start_col);
        case '{': return Token(TokenType::PUNCT_LBRACE, "{", "{", start_line, start_col);
        case '}': return Token(TokenType::PUNCT_RBRACE, "}", "}", start_line, start_col);
        case '[': return Token(TokenType::PUNCT_LBRACKET, "[", "[", start_line, start_col);
        case ']': return Token(TokenType::PUNCT_RBRACKET, "]", "]", start_line, start_col);
        case ',': return Token(TokenType::PUNCT_COMMA, ",", ",", start_line, start_col);
        case ';': return Token(TokenType::PUNCT_SEMICOLON, ";", ";", start_line, start_col);
        case '~': return Token(TokenType::OP_BITWISE_NOT, "~", "~", start_line, start_col);

        case '+':
            if (match('+')) return Token(TokenType::OP_INCREMENT, "++", "++", start_line, start_col);
            if (match('=')) return Token(TokenType::OP_PLUS_ASSIGN, "+=", "+=", start_line, start_col);
            return Token(TokenType::OP_PLUS, "+", "+", start_line, start_col);
        case '-':
            if (match('-')) return Token(TokenType::OP_DECREMENT, "--", "--", start_line, start_col);
            if (match('=')) return Token(TokenType::OP_MINUS_ASSIGN, "-=", "-=", start_line, start_col);
            return Token(TokenType::OP_MINUS, "-", "-", start_line, start_col);
        case '*':
            if (match('=')) return Token(TokenType::OP_MULTIPLY_ASSIGN, "*=", "*=", start_line, start_col);
            return Token(TokenType::OP_MULTIPLY, "*", "*", start_line, start_col);
        case '/':
            if (match('/')) return scan_comment_single_line();
            if (match('*')) return scan_comment_multi_line();
            if (match('=')) return Token(TokenType::OP_DIVIDE_ASSIGN, "/=", "/=", start_line, start_col);
            return Token(TokenType::OP_DIVIDE, "/", "/", start_line, start_col);
        case '%':
            if (match('=')) return Token(TokenType::OP_MODULO_ASSIGN, "%=", "%=", start_line, start_col);
            return Token(TokenType::OP_MODULO, "%", "%", start_line, start_col);
        case '=':
            if (match('=')) {
                if (match('=')) return Token(TokenType::OP_STRICT_EQUAL, "===", "===", start_line, start_col);
                return Token(TokenType::OP_EQUAL, "==", "==", start_line, start_col);
            }
            return Token(TokenType::OP_ASSIGN, "=", "=", start_line, start_col);
        case '!':
            if (match('=')) {
                if (match('=')) return Token(TokenType::OP_STRICT_NOT_EQUAL, "!==", "!==", start_line, start_col);
                return Token(TokenType::OP_NOT_EQUAL, "!=", "!=", start_line, start_col);
            }
            return Token(TokenType::OP_LOGICAL_NOT, "!", "!", start_line, start_col);
        case '<':
            if (match('=')) return Token(TokenType::OP_LESS_EQUAL, "<=", "<=", start_line, start_col);
            if (match('<')) {
                return Token(TokenType::OP_LEFT_SHIFT, "<<", "<<", start_line, start_col);
            }
            return Token(TokenType::OP_LESS, "<", "<", start_line, start_col);
        case '>':
            if (match('=')) return Token(TokenType::OP_GREATER_EQUAL, ">=", ">=", start_line, start_col);
            if (match('>')) {
                if (match('>')) {
                    return Token(TokenType::OP_UNSIGNED_RIGHT_SHIFT, ">>>", ">>>", start_line, start_col);
                }
                return Token(TokenType::OP_RIGHT_SHIFT, ">>", ">>", start_line, start_col);
            }
            return Token(TokenType::OP_GREATER, ">", ">", start_line, start_col);
        case '&':
            if (match('&')) return Token(TokenType::OP_LOGICAL_AND, "&&", "&&", start_line, start_col);
            return Token(TokenType::OP_BITWISE_AND, "&", "&", start_line, start_col);
        case '|':
            if (match('|')) return Token(TokenType::OP_LOGICAL_OR, "||", "||", start_line, start_col);
            return Token(TokenType::OP_BITWISE_OR, "|", "|", start_line, start_col);
        case '^':
            return Token(TokenType::OP_BITWISE_XOR, "^", "^", start_line, start_col);
        case '.':
            if (match('.')) {
                if (match('.')) return Token(TokenType::OP_SPREAD, "...", "...", start_line, start_col);
                current_pos--;
                update_position('\b');
                return Token(TokenType::PUNCT_DOT, ".", ".", start_line, start_col);
            }
            return Token(TokenType::PUNCT_DOT, ".", ".", start_line, start_col);
        case '?':
            if (match('.')) return Token(TokenType::OP_OPTIONAL_CHAINING, "?.", "?.", start_line, start_col);
            if (match('?')) return Token(TokenType::OP_NULLISH_COALESCING, "??", "??", start_line, start_col);
            return Token(TokenType::OP_QUESTION_MARK, "?", "?", start_line, start_col);
        case ':':
            return Token(TokenType::OP_COLON, ":", ":", start_line, start_col);
        default:
            current_pos--;
            current_col--;
            return Token(TokenType::ERROR, "", "Internal: Not an operator/punctuator", start_line, start_col);
    }
}

Token Lexer::scan_comment_single_line() {
    std::string lexeme = "//";
    std::string value;
    int start_line = current_line;
    int start_col = current_col - 2;

    while (!is_at_end() && peek() != '\n') {
        char c = advance();
        lexeme += c;
        value += c;
    }
    return Token(TokenType::COMMENT_SIGNLE_LINE, lexeme, value, start_line, start_col);
}

Token Lexer::scan_comment_multi_line() {
    std::string lexeme = "/*";
    std::string value;
    int start_line = current_line;
    int start_col = current_col - 2;

    while (!is_at_end()) {
        if (peek() == '*' && peek(1) == '/') {
            lexeme += advance();
            lexeme += advance();
            break;
        }
        if (is_at_end()) {
            return Token(TokenType::ERROR, lexeme, "Unterminated multi-line comment", start_line, start_col);
        }
        char c = advance();
        lexeme += c;
        if (!(lexeme.size() > 2 && lexeme[lexeme.size() - 2] == '*' && c == '/')) {
            value += c;
        }
    }
    if (lexeme.length() > 2 && value.length() >= 2 && value.substr(value.length() - 2) == "*/") {
        value.erase(value.length() - 2);
    }

    return Token(TokenType::COMMENT_MULTI_LINE, lexeme, value, start_line, start_col);
}
