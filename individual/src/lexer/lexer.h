#ifndef LEXER_H
#define LEXER_H

#include "../token/Token.h"
#include <string>
#include <unordered_map>
#include <vector>

class Lexer {
public:
    Lexer(const std::string& source);
    std::vector<Token> tokenize();

private:
    std::string source_code;
    size_t current_pos = 0;
    int current_line = 1;
    int current_col = 1;

    std::unordered_map<std::string, TokenType> keywords;

    char peek(size_t offset = 0) const;
    char advance();
    bool match(char expected);
    bool is_at_end();
    void skip_whitespaces_and_comments();

    Token scan_identifier_or_keyword();
    Token scan_number_literal();
    Token scan_string_literal();
    Token scan_string_literal(char quote_type);
    Token scan_operator_or_punctuator();
    Token scan_comment_single_line();
    Token scan_comment_multi_line();

    Token make_error_token(const std::string& message);

    void update_position(char c);
};

#endif // LEXER_H