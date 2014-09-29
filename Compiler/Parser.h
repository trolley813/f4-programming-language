#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
namespace F4 {
    enum TokenType {

    };

    struct Token {
        TokenType tokenType;
        string token;
    };

    class Parser {
    private:
        ifstream *ifile;
    public:
        Parser(ifstream *ifile);
        vector<Token> parse();
    };
}