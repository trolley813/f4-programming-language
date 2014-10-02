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
        TT_REALLITERAL,
        TT_STRINGLITERAL, // TODO String types
        // Punctuation
        TT_LPAREN,     // (
        TT_RPAREN,     // )
        TT_LBRACKET,   // [
        TT_RBRACKET,   // ]
        TT_COLON,      // :
        TT_ARROW,      // ->
        // Operators
        TT_ASSIGN,     // =
        TT_PLUS,       // +
        TT_MINUS,      // -
        TT_MULTIPLY,   // *
        TT_DIVIDE,     // /
        TT_AND,        // &
        TT_OR,         // |
        TT_NOT,        // !
        TT_ASPLUS,     // +=
        TT_ASMINUS,    // -=
        TT_ASMULT,     // *=
        TT_ASDIV,      // /=
        TT_ASAND,      // &=
        TT_ASOR,       // |=
        TT_UNARYPLUS,  // +
        TT_UNARYMINUS  // -
        // Keywords
        TT_KW_IF,
        TT_KW_ENDIF,
        TT_KW_LOOP,
        TT_KW_ENDLOOP,
        TT_KW_VAR,
        TT_KW_INT,
        TT_KW_REAL,
        TT_KW_LOGICAL,
        TT_KW_FUN,
        TT_KW_ENDFUN,
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