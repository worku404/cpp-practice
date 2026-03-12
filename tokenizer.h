@pragma once
#include <cstddef>

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
    TokenType type;
    long long value;
    std::size_t err_position;
}
