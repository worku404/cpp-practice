#include "tokenizer.h"
#include <cctype>

namespace {
    void skip_whitespace(const std::string& expression, std::size_t& index) {
        while (index < expression.size() && std::isspace(static_cast<unsigned char>(expression[index])))
        {
            ++index;
        }
    }
}
TokenizeResult tokenize(const std::string& expression) {
    (void)expression;

    TokenizeResult result;
    result.tokens = {};
    result.status = make_error("Tokenizer not implimented yet.", 0)
    return result;
}
