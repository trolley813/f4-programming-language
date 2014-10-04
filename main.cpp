#include <iostream>
#include <boost/program_options.hpp>
#include "version.h"
#include "Compiler.h"
#include <boost/log/trivial.hpp>

using namespace std;
using namespace F4;
namespace po = boost::program_options;

int main(int argc, char *argv[]) {
    po::options_description description("Available options");
    string of;
    // Input and output file streams
    string ifs, ofs;
    // Adding available options
    description.add_options()
            ("help,h", "show this help message")
            ("out-format", po::value<string>(&of)->default_value("f4o"), "specify output format (f4o, asm, cpp)")
            ("in-file,i", po::value<string>(&ifs), "specify input file")
            ("out-file,o", po::value<string>(&ofs), "specify output file")
            ("link,L", "link the file (only when f4o output selected)")
            ("version,v", "show version")
            ;
    // Adding positional options for file names
    po::positional_options_description pod;
    pod.add("in-file", 1);
    pod.add("out-file", 1);
    // Creating variable map
    po::variables_map vm;
    po::store(po::command_line_parser(argc, argv).options(description).positional(pod).run(), vm);
    po::notify(vm);
    // Show help
    if (vm.count("help") || argc == 1) {
        cout << description << endl;
        return 0;
    }
    if (vm.count("version")) {
        // Write version info
        cout << "f4 Programming Language v" << F4_VERSION_STRING << endl;
        return 0;
    }
    // Checking for input file name
    if (!vm.count("in-file")) {
        cout << "No input file specified" << endl;
        return 1;
    }
    // Checking for output file name
    if (!vm.count("out-file")) {
        size_t pp = ifs.find_last_of(".", ifs.size());
        ofs = (pp != string::npos ? ifs.substr(0, pp + 1) : ifs) + of;
    }
    //Checking the output format
    CompilerOutputFormat cof = COF_UNDEFINED;
    if (of == "f4o") cof = COF_OBJECT;
    if (of == "asm") cof = COF_ASSEMBLER;
    if (of == "cpp") cof = COF_CPLUSPLUS;
    if (cof == COF_UNDEFINED) {
        cout << "Unknown output file format" << endl;
        return 1;
    }
    //Creating the compiler
    Compiler compiler(ifs, ofs, cof);
    compiler.compile();
    return 0;
}