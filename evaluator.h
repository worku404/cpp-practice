@pragma once
#include "parser.h"

struct EvalResult {
    long long value;
    Status status;
};

EvalResult evaluate(const AstNode& node);
