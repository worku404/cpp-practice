#include "tokenizer.h"
#include <cctype>
#include <limits>
#include <winscard.h>

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

    out_token = Token{value, TokenType::Number, start};
    return make_ok();
    }
}

TokenizeResult tokenize(const std::string& expression) {
    TokenizeResult result;
    std::size_t index = 0;

    while (index < expression.size()) {
        skip_whitespace(expression, index);
        if (index >= expression.size()) {
            break;
        }

        const std::size_t position = index;
        const char ch = expression[index];

        if (std::isdigit(static_cast<unsigned char>(ch))) {
            if (!result.tokens.empty() &&
                result.tokens.back().type == TokenType::Number) {
                    result.tokens.clear();
                    result.status = make_error("Missing operator between numbers", position);
                    return result;
                }

            Token number_token;
            Status status = scan_number(expression, index, number_token);

            if(!is_ok(status)) {
                result.tokens.clear();
                result.status = status;
                return result;
            }

            result.tokens.push_back(number_token);
            continue;
        }

        switch(ch) {
            case '+':
                result.tokens.push_back(Token{0, TokenType::Plus, position});
                ++index;
                break;
            case '-':
                result.tokens.push_back(Token{0, TokenType::Minus, index});
                ++index;
                break;
            case '*':
            result.tokens.push_back(Token{0, TokenType::Star, index});
            ++index;
            break;
            case '/':
            result.tokens.push_back(Token{0, TokenType::Slash, index});
            ++index;
            break;
            case '(':
            result.tokens.push_back(Token{0, TokenType::LParen, index});
            ++index;
            break;
            case ')':
            result.tokens.push_back(Token{0, TokenType::RParen, index});
            ++index;
            break;
            default:
            result.tokens.clear();
                result.status = make_error("Unexpected character",  position);
                return result;

        }
    }
    result.tokens.push_back(Token{0, TokenType::End, expression.size()});
    result.status = make_ok();
    return result;
}
