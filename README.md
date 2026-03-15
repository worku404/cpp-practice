Use this as your `README.md` (portfolio-oriented and aligned to your plan):

# Mini Expression Evaluator (C++17)

[![C++17](https://img.shields.io/badge/C%2B%2B-17-blue.svg)](#)
[![Build](https://img.shields.io/badge/build-g%2B%2B%20%7C%20clang%2B%2B-success.svg)](#)
[![Architecture](https://img.shields.io/badge/architecture-AST%20pipeline-orange.svg)](#)
[![Error%20Model](https://img.shields.io/badge/error%20handling-Status%20objects-lightgrey.svg)](#)

A modular command-line expression evaluator built in modern C++17 with a clean pipeline:

`tokenizer -> parser (AST) -> evaluator -> controller/repl`

This project was designed as a teaching-quality implementation that emphasizes software engineering fundamentals:
- interface vs implementation (`.h` vs `.cpp`)
- recursion through recursive descent parsing
- explicit error contracts (`Status`, no exceptions in baseline)
- separation of concerns and testable modules

## Table of Contents
1. [Project Overview](#project-overview)
2. [Feature Scope](#feature-scope)
3. [Architecture](#architecture)
4. [Grammar](#grammar)
5. [Public API Contracts](#public-api-contracts)
6. [Build and Run](#build-and-run)
7. [Usage Examples](#usage-examples)
8. [Testing Strategy](#testing-strategy)
9. [Design Decisions and Tradeoffs](#design-decisions-and-tradeoffs)
10. [Roadmap](#roadmap)
11. [Portfolio Highlights](#portfolio-highlights)
12. [Limitations](#limitations)
13. [Future Improvements](#future-improvements)
14. [License](#license)

---

## Project Overview

**Goal:** Build a reliable, modular arithmetic expression evaluator for integers with strong error reporting and clear contracts between modules.

**Baseline capabilities:**
- `long long` integer arithmetic
- unary minus
- binary operators: `+ - * /`
- parentheses
- precedence and left associativity
- position-aware lexical, parse, and evaluation errors
- REPL loop that continues safely after errors

**Primary learning objective:** demonstrate engineering rigor.

---

## Feature Scope

### Supported
- Integer literals (base-10)
- Whitespace-insensitive input
- Expressions like:
  - `3 + 4 * (2 - 1)`
  - `-5 + 2 * 3`
  - `((1+2)*3)-4`

### Error handling examples
- invalid token: `12a + 3`
- malformed syntax: `3 + * 4`
- missing parenthesis: `(1 + 2`
- runtime arithmetic error: `10 / 0`

### Explicitly deferred
- floating-point numbers
- variables and assignment
- functions (`sin`, `max`, etc.)
- exception-based error flow (baseline uses `Status` objects)

---

## Architecture

## Pipeline

text
Input string
   |
   v
[Tokenizer] -> vector<Token>
   |
   v
[Parser] -> AST (AstNode tree)
   |
   v
[Evaluator] -> long long
   |
   v
[Controller/REPL] -> user-facing output


## Module responsibilities

| Module | Responsibility | Public Output |
|---|---|---|
| `utilities` | Shared status/error contract | `Status`, helpers |
| `tokenizer` | Convert input text to tokens | `TokenizeResult` |
| `parser` | Build AST from token stream | `ParseResult` |
| `evaluator` | Evaluate AST recursively | `EvalResult` |
| `controller` | Orchestrate pipeline and output formatting | `run_once`, `repl` |
| `main` | Thin entrypoint only | calls `repl(...)` |

## File layout

text
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


---

## Grammar

Recursive descent grammar used by the parser:

```ebnf
expression -> term ((+|-) term)*
term       -> factor ((*|/) factor)*
factor     -> NUMBER | '(' expression ')' | '-' factor
```

This grammar enforces:
- multiplication/division precedence over addition/subtraction
- left associativity for binary operations
- unary minus binding at factor level

---

## Public API Contracts

## `utilities`

```cpp
struct Status {
    bool ok;
    std::string message;
    size_t position;
};

Status make_ok();
Status make_error(const std::string& message, size_t position);
inline bool is_ok(const Status& status);
```

## `tokenizer`

```cpp
enum class TokenType { Number, Plus, Minus, Star, Slash, LParen, RParen, End };

struct Token {
    TokenType type;
    long long value;
    size_t position;
};

struct TokenizeResult {
    std::vector<Token> tokens;
    Status status;
};

TokenizeResult tokenize(const std::string& expression);
```

## `parser`

```cpp
struct ParseResult {
    std::unique_ptr<AstNode> root;
    Status status;
};

ParseResult parse(const std::vector<Token>& tokens);
```

## `evaluator`

```cpp
struct EvalResult {
    long long value;
    Status status;
};

EvalResult evaluate(const AstNode& root);
```

## `controller`

```cpp
Status run_once(const std::string& line, std::ostream& out);
void repl(std::istream& in, std::ostream& out);
```

---

## Build and Run

## Prerequisites
- C++17-compatible compiler (`g++` or `clang++`)
- terminal/console environment

## Compile

```bash
g++ -std=c++17 -Wall -Wextra -pedantic src/*.cpp -o expr_eval
```

## Run

```bash
./expr_eval
```

On Windows (MinGW), executable is typically:

```powershell
.\expr_eval.exe
```

---

## Usage Examples

## Happy path

| Input | Output |
|---|---|
| `3 + 4 * (2 - 1)` | `7` |
| `-5 + 2 * 3` | `1` |
| `((1+2)*3)-4` | `5` |
| `8 / 2 * 2` | `8` |
| `7 - 3 - 1` | `3` |

## Error path

| Input | Expected behavior |
|---|---|
| `3 + * 4` | parser error with position |
| `(1 + 2` | parse error: missing `)` |
| `10 / 0` | evaluator error: division by zero |
| `12a + 3` | tokenizer error with position |

---

## Testing Strategy

## Stage-based verification
- Stage 1: stubs compile, REPL loop runs
- Stage 2: token stream correctness
- Stage 3: AST shape and parse correctness
- Stage 4: evaluation correctness and divide-by-zero guard
- Stage 5: uniform error formatting and safe REPL recovery
- Stage 6: overload/default-arg/inline helpers compile and behave correctly

## Contract checks
- Every failed operation returns `Status.ok == false`
- Every failure includes message and position
- `main()` contains orchestration only (no parsing/evaluation logic)

---

## Design Decisions and Tradeoffs

| Decision | Alternative | Why chosen |
|---|---|---|
| Recursive descent parser | Shunting-yard | clearer recursion teaching and direct grammar mapping |
| AST-first pipeline | direct evaluate-while-parse | better separation of concerns, easier extension/debugging |
| `Status` result objects | exceptions | explicit contracts and predictable teaching flow |
| Return result structs | output-parameter mutation | composability and readability |
| Iterative tokenizer | recursive tokenizer | simpler control flow and better performance clarity |
| Thin `main()` | fat entrypoint | maintainability and modular testing |

---

## Roadmap

| Stage | Focus | Outcome |
|---|---|---|
| 1 | Structure and contracts | modular headers/sources, thin `main` |
| 2 | Tokenizer | lexical scanner with positions and `End` token |
| 3 | Parser | AST via recursive descent |
| 4 | Evaluator | recursive post-order evaluation |
| 5 | Error model | consistent cross-module failure propagation |
| 6 | C++ features | overloads, default args, inline helpers, optional debug modes |

---

## Portfolio Highlights

This project demonstrates:
- clean modular C++ project structure
- practical compiler front-end concepts (lexing, parsing, AST)
- recursive algorithm design in production-style code
- explicit API contracts and error propagation
- maintainable architecture where modules evolve independently
- technical communication and stage-driven implementation planning

---

## Limitations

Current baseline intentionally limits scope to:
- integer arithmetic only (`long long`)
- no overflow detection policy yet
- no variables/functions
- no decimal or scientific notation

These limits keep core design and correctness visible and teachable.

---

## Future Improvements

1. Overflow-safe arithmetic policies.
2. Decimal support with configurable numeric type.
3. Variables and assignment.
4. Built-in functions (`abs`, `min`, `max`).
5. AST visualization mode.
6. Unit test suite with automated CI.
7. CMake build integration.
8. Benchmarking for large expression inputs.

---

## License

`This project is licensed under the MIT License - see LICENSE file for details.`

---

## Author

**Worku Wondoson**  
Software Engineering Student | C++ Developer  
- GitHub: `https://github.com/worku404`
- LinkedIn: `https://linkedin.com/in/`
- Email: `accworku@gmail.com`
