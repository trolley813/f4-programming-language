#include "Parser.h"
#include <boost/log/trivial.hpp>
#include <boost/spirit/include/qi.hpp>
#include <boost/bind.hpp>
#include "Errors.h"

namespace bs = boost::spirit;
namespace qi = boost::spirit::qi;
using namespace std;

namespace F4 {
    Parser::Parser(ifstream *ifile) : ifile(ifile) {
        rules[TT_IDENT] = bs::lexeme[qi::alpha >> *qi::alnum];
        rules[TT_INTLITERAL] = bs::lexeme[+qi::digit];
        rules[TT_REALLITERAL] = bs::lexeme[(-(qi::char_('+') | qi::char_('-')) >> +qi::digit) >> ((qi::char_(',') | qi::char_('.')) >> +qi::digit)];
        rules[TT_STRINGLITERAL] = bs::lexeme[qi::char_('"') >> (*qi::char_ - '"') >> qi::char_('"')];
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
        mainRule = rules[0].copy()[boost::bind(&Parser::addToken, this, 0, _1)];
        for (int i = 1; i < TT_COUNT; i++) {
            mainRule = mainRule.copy() | rules[i].copy()[boost::bind(&Parser::addToken, this, i, _1)];
        }
    }

    vector<Token> Parser::parse() {
        // Clear the parsedTokens
        parsedTokens = vector<Token>();
        string s;
        int i = 1;
        qi::rule < std::string::iterator, vector<std::string>(), ascii::space_type > rule = +(mainRule.copy());
        while (std::getline(*ifile, s)) {
            vector<string> v;
            BOOST_LOG_TRIVIAL(debug) << "Parsing line " << i++;
            // TODO More interesting deal with comments
            size_t end = s.find_first_of("%", 0);
            if (end != string::npos) {
                s = s.substr(0, end);
                BOOST_LOG_TRIVIAL(debug) << "Ignoring comment after position " << end;
            }
            auto b = s.begin(), e = s.end();
            if (b == e) continue;
            bool r = qi::phrase_parse(b, e, rule, qi::ascii::space, v);
            if (!r) message(ECW_PARTPARSE);
            addToken(TT_NEWLINE, "\n");
            BOOST_LOG_TRIVIAL(debug) << "Total parsed: " << parsedTokens.size() << " token(s)";
        }
        return parsedTokens;
    }

    void Parser::debugPrintTokens() {
        int i = 1;
        for (Token t : parsedTokens) {
            BOOST_LOG_TRIVIAL(debug) << "Token " << i++ << ": " << (t.token != "\n" ? t.token : "[newline]") << " with type " << t.tokenType;
        }
    }
}