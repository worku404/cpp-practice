#include "evaluator.h"

EvalResult evaluate(const AstNode& root) {
    (void) root;
    EvalResult result;
    result.value = 0;
    result.status = make_error("Evaluator not implemented yet.", 0);
    return result;
}
