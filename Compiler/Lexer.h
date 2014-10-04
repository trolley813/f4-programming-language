#ifndef LEXER_H
#define LEXER_H

#include "Parser.h"

namespace F4 {
    class Lexer {
    private:
    public:
        Lexer();

        void analyse(vector<Token> &tokens);
    };
}
#endif