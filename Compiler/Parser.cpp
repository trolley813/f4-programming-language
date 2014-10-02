#include "Parser.h"
#include <boost/spirit/include/qi_char_class.hpp>

namespace bs = boost::spirit;
namespace qi = boost::spirit::qi;

namespace F4 {
    Parser::Parser(ifstream *ifile) : ifile(ifile) {
        rules[TT_IDENT] = bs::lexeme[qi::alpha >> *qi::alnum];
        rules[TT_INTLITERAL] = bs::lexeme[+qi::digit];
        rules[TT_REALLITERAL] = bs::lexeme[(-(qi::char_('+') | qi::char_('-')) >> +qi::digit) >> ((qi::char_(',') | qi::char_('.')) >> +qi::digit)];
        rules[TT_LPAREN] = qi::char_('(');
        rules[TT_RPAREN] = qi::char_(')');
        rules[TT_LBRACKET] = qi::char_('[');
        rules[TT_RBRACKET] = qi::char_(']');
        rules[TT_COLON] = qi::char_(':');
//      rules[TT_ARROW] = qi::string("->");
    }
    
    vector<Token> Parser::parse() {
        vector<Token> v;
        return v;
    }
}