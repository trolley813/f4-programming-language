#ifndef COMPILER_H
#define COMPILER_H

#include <string>
#include "Parser.h"
#include "Lexer.h"
#include "SyntaxAnalyser.h"

using namespace std;
namespace F4 {
    enum CompilerOutputFormat {
        COF_UNDEFINED,
        COF_OBJECT,
        COF_ASSEMBLER,
        COF_CPLUSPLUS
    };

    class Compiler {
    private:
        string ifile, ofile;
        CompilerOutputFormat cof;
        Parser *parser;
        Lexer *lexer;
        SyntaxAnalyser *analyser;
//        Generator *generator;
    public:
        Compiler(string ifile, string ofile, CompilerOutputFormat cof);

        void compile();
    };
}
#endif