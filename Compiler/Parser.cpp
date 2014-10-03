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
        rules[TT_ARROW] = qi::string("->");
        rules[TT_ASSIGN] = qi::char_('=');
        rules[TT_PLUS] = qi::char_('+');
        rules[TT_MINUS] = qi::char_('-');
        rules[TT_MULTIPLY] = qi::char_('*');
        rules[TT_DIVIDE] = qi::char_('/');
        rules[TT_AND] = qi::char_('&');
        rules[TT_OR] = qi::char_('|');
        rules[TT_NOT] = qi::char_('~');
        rules[TT_ASPLUS] = qi::string("+=");
        rules[TT_ASMINUS] = qi::string("-=");
        rules[TT_ASMULT] = qi::string("*=");
        rules[TT_ASDIV] = qi::string("/=");
        rules[TT_ASAND] = qi::string("&=");
        rules[TT_ASOR] = qi::string("|=");
    }
    
    vector<Token> Parser::parse() {
        vector<Token> v;
        return v;
    }
}