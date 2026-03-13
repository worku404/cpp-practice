@pragma once

#include <cstddef>
#include <vector>
#include "utilities.h"
#include <string>

enum class TokenType {
    Number,
    Plus,
    Minus,
    Star,
    Slash,
    LParen,
    RParen,
    End
};

struct Token {
    long long value;
    TokenType type;
    std::size_t err_position;
};

struct TokenizeResult {
    std::vector<Token> tokens;
    Status status;
};

TokenizeResult tokenize(const std::string& expression);
