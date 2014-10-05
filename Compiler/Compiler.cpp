#include "Compiler.h"
#include "Errors.h"
#include <boost/log/trivial.hpp>

namespace F4 {
    Compiler::Compiler(string ifile, string ofile, CompilerOutputFormat cof) : ifile(ifile), ofile(ofile), cof(cof) {

    }

    void Compiler::compile() {
        ifstream *i = new ifstream(ifile.c_str());
        if (!i->is_open()) message(ECF_CANNOTOPEN);
        BOOST_LOG_TRIVIAL(info) << "Compiling file " << ifile << "...";
        BOOST_LOG_TRIVIAL(info) << "Parsing...";
        parser = new Parser(i);
//        TODO Class Lexer, GeneratorCPP
        std::vector<Token> tokens = parser->parse();
//        TODO Remove debug print
        parser->debugPrintTokens();
        BOOST_LOG_TRIVIAL(info) << "Analysing...";
        lexer = new Lexer();
        lexer->analyse(tokens);
        BOOST_LOG_TRIVIAL(info) << "Generating code...";
        switch (cof) {
            case COF_OBJECT:
//                generator = new GeneratorObject(tokens);
                BOOST_LOG_TRIVIAL(error) << "Sorry, generating format " << cof << " is not supported yet :(";
                return;
                break;
            case COF_ASSEMBLER:
//                generator = new GeneratorAsm(tokens);
                BOOST_LOG_TRIVIAL(error) << "Sorry, generating format " << cof << " is not supported yet :(";
                return;
                break;
            case COF_CPLUSPLUS:
//                generator = new GeneratorCpp(tokens);
                BOOST_LOG_TRIVIAL(error) << "Sorry, generating format " << cof << " is not supported yet :(";
                return;
                break;
            default:
//                TODO Error
                break;
        }
//      generator->setOutputFile(ofile);
//      generator->generate();
    }
}