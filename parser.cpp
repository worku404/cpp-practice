#include "parser.h"

ParseResult parse(const std::vector<Token>& tokens) {
    (void)tokens;

    ParseResult result;
    result.root = nullptr;
    result.status = make_error("Parser not implemented yet.", 0);
    return result;
}
