#include <boost/log/trivial.hpp>
#include <boost/lexical_cast.hpp>
#include "Lexer.h"
#include "Errors.h"

namespace F4 {

    Lexer::Lexer() {
        keywords["if"] = TT_KW_IF;
        keywords["endif"] = TT_KW_ENDIF;
        keywords["loop"] = TT_KW_IF;
        keywords["endloop"] = TT_KW_ENDLOOP;
        keywords["var"] = TT_KW_VAR;
        keywords["int"] = TT_KW_INT;
        keywords["real"] = TT_KW_REAL;
        keywords["logical"] = TT_KW_LOGICAL;
        keywords["fun"] = TT_KW_FUN;
        keywords["endfun"] = TT_KW_ENDFUN;
        keywords["return"] = TT_KW_RETURN;
    }

    void Lexer::analyse(vector<Token> &tokens) {
        checkForKeywords(tokens);
        checkForNumbers(tokens);
    }

    void Lexer::checkForKeywords(vector<Token> &tokens) {
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i].tokenType == TT_IDENT && keywords.find(tokens[i].token) != keywords.end()) {
                tokens[i].tokenType = keywords[tokens[i].token];
                BOOST_LOG_TRIVIAL(debug) << "Changed token " << i + 1 << " type to " << keywords[tokens[i].token];
            }
        }
    }

    void Lexer::checkForNumbers(vector<Token> &tokens) {
        using boost::conversion::try_lexical_convert;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i].tokenType == TT_INTLITERAL) {
                int64_t res;
                if (!try_lexical_convert(tokens[i].token, res)) {
                    message(ECW_TOOBIG);
                }
            }
        }
    }
}