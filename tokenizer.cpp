#include "tokenizer.h"

TokenizeResult tokenize(const std::string& expression) {
    (void)expression;

    TokenizeResult result;
    result.tokens = {};
    result.status = make_error("Tokenizer not implimented yet.", 0)
    return result;
}
