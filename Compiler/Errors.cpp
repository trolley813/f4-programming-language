#include "Errors.h"

namespace F4 {
    map<ErrorCode, string> desc =
            {
                    {ECW_PARTPARSE, "Partial parse"},
                    {ECW_TOOBIG, "Constant number is too big"},
                    {ECE_INVEXPR, "Invalid expression"},
                    {ECF_CANNOTOPEN, "Cannot open file"},
                    {ECF_UNSPECIFIEDFILE, "File not specified"},
                    {ECF_INVALIDFORMAT, "Invalid output format"}
            };

    void message(ErrorCode ec) {
        // If it's a fatal error
        if (ec >= ECF_CANNOTOPEN) {
            BOOST_LOG_TRIVIAL(fatal) << "F4PL fatal error: " << desc[ec] << " (code: " << ec << ")";
            throw 1;
        }
        //If it's a nonfatal error
        if (ec >= ECE_INVEXPR) {
            BOOST_LOG_TRIVIAL(error) << "F4PL error: " << desc[ec] << " (code: " << ec << ")";
            return;
        }
        //If it's a warning
        if (ec >= ECW_PARTPARSE) {
            BOOST_LOG_TRIVIAL(warning) << "F4PL warning: " << desc[ec] << " (code: " << ec << ")";
        }
    }
}