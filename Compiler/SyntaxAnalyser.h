#include "Parser.h"

namespace F4 {
    class SyntaxAnalyser {
    private:
        vector<Token> tokens;
    public:
        SyntaxAnalyser(vector<Token> tokens) : tokens(tokens) {
        }

        void analyseSyntax();
    };
}