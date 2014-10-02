#include "Parser.h"

namespace bs = boost::spirit
namespace qi = boost::spirit::qi;

namespace F4 {
    Parser::Parser(ifstream *ifile) : ifile(ifile) {
        q[TT_IDENT] = bs::lexeme[qi::alpha >> *qi::alnum];
        q[TT_INTLITERAL] = bs::lexeme[+qi::digit];
        q[TT_REALLITERAL] = bs::lexeme[(-(qi::char_('+') | qi::char_('-')) >> +qi::digit) >> ((qi::char_(',') | qi::char_('.')) >> +qi::digit)];
        q[TT_LPAREN] = qi::char_('(');
        q[TT_RPAREN] = qi::char_(')');
        q[TT_LBRACKET] = qi::char_('[');
        q[TT_RBRACKET] = qi::char_(']');
        q[TT_COLON] = qi::char_(':');
///     q[TT_ARROW] = qi::string("->");
    }
    
    vector<Token> Parser::parse() {
        vector<Token> v;
        return v;
    }
}