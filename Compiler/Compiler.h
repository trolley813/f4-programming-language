#include <string>
#include "Parser.h"
#include "Lexer.h"

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
//        Generator *generator;
    public:
        Compiler(string ifile, string ofile, CompilerOutputFormat cof);

        void compile();
    };
}