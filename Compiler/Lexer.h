#ifndef LEXER_H
#define LEXER_H

#include <map>
#include "Parser.h"

namespace F4 {
    class Lexer {
    private:
        map<string, TokenType> keywords;
    public:
        Lexer();

        void analyse(vector<Token> &tokens);

        void checkForKeywords(vector<Token> &tokens);

        void checkForNumbers(vector<Token> &tokens);
    };
}
#endif