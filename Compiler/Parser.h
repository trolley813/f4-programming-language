#include <iostream>
#include <fstream>
#include <vector>
#include <boost/spirit/include/qi.hpp>

using namespace std;
namespace qi = boost::spirit::qi;
namespace ascii = boost::spirit::qi::ascii;

namespace F4 {
    enum TokenType {
        // Identifiers and literals
                TT_IDENT,
        TT_INTLITERAL,
        TT_DOUBLELITERAL,
        TT_STRINGLITERAL, // TODO String types
        // Punctuation
                TT_LPAREN,
        TT_RPAREN,
        TT_LBRACKET,
        TT_RBRACKET,
        TT_COLON,
        // Operators
                TT_ASSIGN,
        // Keywords
                TT_KW_IF,
        TT_KW_ENDIF,
        TT_KW_LOOP,
        TT_KW_ENDLOOP,
        // Total count
                TT_COUNT
    };

    struct Token {
        TokenType tokenType;
        string token;
    };

    class Parser {
    private:
        ifstream *ifile;
        qi::rule<string::iterator, string(), ascii::space_type> rules[TT_COUNT];
    public:
        Parser(ifstream *ifile);
        vector<Token> parse();
    };
}