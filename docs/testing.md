# Testing Strategy

## 1. Testing Goals

- Validate correctness of each stage independently.
- Validate module contracts and error propagation.
- Confirm REPL recovers after failures.

## 2. Stage Checkpoint Testing

### Stage 1
- Build succeeds.
- REPL starts.
- `:help` and `:quit` work.

### Stage 2
- Token sequences match expected outputs.
- Invalid characters produce precise status.
- Integer literal overflow is rejected safely.

### Stage 3
- Parser builds AST for valid expressions.
- Grammar precedence and associativity are respected.
- Syntax failures include useful position data.

### Stage 4
- Evaluator returns expected numeric results.
- Division by zero fails with explicit status.

### Stage 5
- Error formatting is consistent across all modules.
- REPL continues loop after errors.

### Stage 6
- Overloads/default args/inline helpers compile and function.
- Optional debug flags do not break normal flow.

## 3. Core Functional Test Matrix

### Happy Path
- `3 + 4 * (2 - 1)` => `7`
- `-5 + 2 * 3` => `1`
- `((1+2)*3)-4` => `5`
- `8 / 2 * 2` => `8`
- `7 - 3 - 1` => `3`

### Error Path
- `3 + * 4` => parser error
- `(1 + 2` => missing `)`
- `10 / 0` => division by zero error
- `12a + 3` => tokenizer error

## 4. Contract Tests

- Any failure must set `status.ok == false`.
- Failures should include clear `message`.
- Position should be valid when source location exists.
- `main()` should not include parsing/evaluating logic.

## 5. Manual REPL Test Script

1. Start program.
2. Run `:help`.
3. Enter malformed input.
4. Verify error prints and REPL continues.
5. Enter `:quit` and verify clean exit.

## 6. Automation Plan

Planned structure:
- tokenizer unit tests
- parser unit tests
- evaluator unit tests
- controller integration tests

Suggested tools:
- Catch2 or GoogleTest
- CI with compiler matrix (g++, clang++)

## 7. Regression Focus Areas

- operator precedence regressions
- unary minus handling regressions
- error position off-by-one issues
- recovery logic in REPL loop
