# Developer Guide

## 1. Purpose

This guide is for contributors implementing or extending the project.

## 2. Local Development Setup

- Install C++17 compiler.
- Clone repository.
- Build from project root.

Compile command:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic *.cpp -o expr_eval
```

## 3. Development Principles

- Keep interfaces stable and explicit.
- Add logic to correct module only.
- Avoid coupling parser and evaluator internals.
- Keep `main()` and controller orchestration-focused.

## 4. Coding Standards

- Use clear names and short functions.
- Prefer `const` where possible.
- Use `std::size_t` for indices.
- Keep helper functions in anonymous namespace inside `.cpp`.
- Avoid hidden side effects.

## 5. Implementation Workflow by Stage

1. Define function contract in header.
2. Implement function in source file.
3. Verify compile.
4. Run focused tests for that stage.
5. Add one small exercise/extension.

## 6. Suggested Parser Implementation Order

- `parse_expression`
- `parse_term`
- `parse_factor`
- final `parse` wrapper checks full consumption at `End`

## 7. Error Handling Checklist

- Return immediately on failure.
- Preserve failure position from source module.
- Keep message concise and deterministic.

## 8. Review Checklist Before Merge

- No new warnings under `-Wall -Wextra -pedantic`
- Module boundaries respected
- Public API documentation updated
- Tests updated for changed behavior
- README/docs still match code reality

## 9. Common Pitfalls

- Evaluating while parsing (breaks separation)
- Losing token position during error propagation
- Forgetting `End` token validation
- Inconsistent associativity handling

## 10. Recommended Next Refactors

- Move to `include/` and `src/` structure.
- Replace raw AST pointer with `std::unique_ptr` ownership.
- Add unit tests before adding new features.
