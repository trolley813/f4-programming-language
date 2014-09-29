#include "Compiler.h"

namespace F4 {
    Compiler::Compiler(string ifile, string ofile, CompilerOutputFormat cof) : ifile(ifile), ofile(ofile), cof(cof) {

    }

    void Compiler::compile() {
        ifstream *i = new ifstream(ifile.c_str());
        cout << "Compiling file " << ifile << "...\n";
        cout << "Parsing...\n";
        parser = new Parser(i);
//        TODO Class Lexer, GeneratorCPP
        std::vector<Token> tokens = parser->parse();
//        lexer = new Lexer(tokens);
//        lexer->analyse(tokens);
        switch (cof) {
            case COF_OBJECT:
//                generator = new GeneratorObject(tokens);
                break;
            case COF_ASSEMBLER:
//                generator = new GeneratorAsm(tokens);
                break;
            case COF_CPLUSPLUS:
//                generator = new GeneratorCpp(tokens);
                break;
            default:
//                TODO Error
                break;
        }
//      generator->setOutputFile(ofile);
//      generator->generate();
    }
}