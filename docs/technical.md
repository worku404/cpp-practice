# Technical Design

## 1. System Architecture

Target pipeline:

```text
Input line
  -> Tokenizer (lexical analysis)
  -> Parser (recursive descent AST construction)
  -> Evaluator (post-order recursion)
  -> Controller (output formatting)
```

Current pipeline in code:

```text
Input line
  -> Controller::run_once
     - handles :help
     - returns not-implemented for normal expressions
```

## 2. Design Principles

- Separation of concerns across modules
- Explicit contracts through result/status structs
- Small focused functions
- Keep `main()` thin
- Prefer composability over side effects

## 3. Planned Grammar

```ebnf
expression -> term ((+|-) term)*
term       -> factor ((*|/) factor)*
factor     -> NUMBER | '(' expression ')' | '-' factor
```

Effects:
- Correct precedence (`*` and `/` before `+` and `-`)
- Left associativity for binary operators
- Unary minus support

## 4. Module Responsibilities

### utilities
- Defines common `Status` contract.
- Offers helper factories (`make_ok`, `make_error`).

### tokenizer
- Converts raw text into `Token` sequence.
- Detects lexical failures (invalid char, integer overflow).

### parser
- Converts token sequence into AST.
- Owns grammar enforcement and syntax diagnostics.

### evaluator
- Recursively computes `long long` result from AST.
- Owns runtime arithmetic checks (for example, division by zero).

### controller
- Orchestrates module calls.
- Formats user-facing output.
- Maintains REPL recovery loop.

### main
- Delegates to `repl()` only.

## 5. Data Contracts

- `Status` conveys success/failure with message and source position.
- Module result structs combine payload with `Status`.

Recommended propagation pattern:
1. Call module.
2. If `!status.ok`, return early.
3. Do not ignore failure from lower layers.

## 6. Parsing Strategy Tradeoff

Chosen: recursive descent.

Alternative: shunting-yard.

Reason for chosen approach:
- Better pedagogical value for recursion training.
- Grammar maps directly to parser function structure.
- Easier to reason about function boundaries at early-intermediate level.

## 7. Evaluation Strategy Tradeoff

Chosen: return `EvalResult`.

Alternative: mutate `long long& out` plus separate status return.

Reason for chosen approach:
- Stronger function contracts.
- Cleaner composition.
- Fewer mutable output paths.

## 8. File Layout

Current:
- Flat root-level `*.h` and `*.cpp`

Planned:

```text
include/
  utilities.h
  tokenizer.h
  parser.h
  evaluator.h
  controller.h
src/
  utilities.cpp
  tokenizer.cpp
  parser.cpp
  evaluator.cpp
  controller.cpp
  main.cpp
```

## 9. Extension Strategy

Planned Stage 6 enhancements should not alter core parser/evaluator behavior:
- overloads for token string conversion
- default argument for error printer
- tiny inline helper predicates
- optional debug toggles (token dump / AST shape)
