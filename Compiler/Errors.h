#ifndef ERRORS_H
#define ERRORS_H

#include <boost/log/trivial.hpp>
#include <map>

using namespace std;
namespace F4 {
    enum ErrorCode {
        EC_ZERO,
        // These are warnings (begin with ECW)
                ECW_PARTPARSE,
        ECW_TOOBIG,
        // These are errors (begin with ECE)
                ECE_INVEXPR,
        // And these are fatal errors (begin with ECF)
                ECF_CANNOTOPEN,
        ECF_INVALIDFORMAT
    };

    extern map<ErrorCode, string> desc;

    void message(ErrorCode ec);
}
#endif