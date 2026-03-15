#include "tokenizer.h"
#include <cctype>
#include <limits>

namespace {
    void skip_whitespace(const std::string& expression, std::size_t& index) {
        while (index < expression.size() &&
            std::isspace(static_cast<unsigned char>(expression[index])))
        {
            ++index;
        }
    }

    Status scan_number(const std::string& expression, std::size_t& index, Token& out_token) {
        if (index >= expression.size() ||
            !std::isdigit(static_cast<unsigned char)(expression[index])) {
        return make_error("Expected digit at start of number", index);
    }

    const std::size_t start = index;
    long long value = 0;

    while (index < expression.size() &&
        std::isdigit(static_cast<unsigned char>(expression[index]))) {
            const int digit = expression[index] - '0';

            if (value > (std::numeric_limits<long long>::max() - digit) / 10)
                return make_error("Integer literal out of range", start);

            value = value * 10 + digit;
            ++index;
        }

    out_token = Token{TokenType::Number, value, start};
    return make_ok();
    }
}

TokenizeResult tokenize(const std::string& expression) {
    (void)expression;

    TokenizeResult result;
    result.tokens = {};
    result.status = make_error("Tokenizer not implimented yet.", 0)
    return result;
}
