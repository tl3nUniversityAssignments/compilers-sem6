#include "src/lexer/lexer.h"
#include <iostream>
#include <fstream>
#include <sstream>

void printUsage(const char* programName) {
    std::cerr << "Usage: " << programName << " <input_file>" << std::endl;
    std::cerr << "Example: " << programName << " script.js" << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printUsage(argv[0]);
        return 1;
    }

    std::string js_code;
    std::ifstream file(argv[1]);
    std::stringstream buffer;

    if (!file) {
        std::cerr << "Error: Could not open file '" << argv[1] << "'!" << std::endl;
        return 1;
    }

    buffer << file.rdbuf();
    js_code = buffer.str();
    file.close();

    Lexer lexer(js_code);
    std::vector<Token> tokens = lexer.tokenize();

    std::cout << "Tokens from file '" << argv[1] << "':\n";
    std::cout << "----------------------------------------------------------\n";
    std::cout << "LINE:COL  TYPE                 LEXEME               VALUE\n";
    std::cout << "----------------------------------------------------------\n";

    for (const auto& token : tokens) {
        std::cout.width(3); std::cout << std::left << token.line << ":";
        std::cout.width(3); std::cout << std::left << token.col << "  ";
        std::cout.width(20); std::cout << std::left << tokenTypeToString(token.type);
        std::cout.width(20); std::cout << std::left << token.lexeme;
        std::cout << token.value << std::endl;
    }
    std::cout << "----------------------------------------------------------\n";

    return 0;
}