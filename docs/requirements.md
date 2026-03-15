# Requirements

## 1. Scope Summary

The system evaluates arithmetic expressions entered in a CLI REPL with explicit, position-aware error reporting and modular architecture.

## 2. Functional Requirements

### FR-001 Input Handling
- The system shall read one line at a time from standard input.
- The system shall continue accepting input until a quit command or EOF.

### FR-002 Commands
- The system shall support `:help` to display usage guidance.
- The system shall support `:quit` to terminate REPL loop safely.

### FR-003 Tokenization
- The system shall tokenize integer literals.
- The system shall tokenize operators `+`, `-`, `*`, `/`.
- The system shall tokenize parentheses `(` and `)`.
- The system shall ignore whitespace between tokens.
- The tokenizer shall append an explicit `End` token.

### FR-004 Parsing
- The parser shall consume token stream and build AST.
- The parser shall enforce operator precedence and associativity.
- The parser shall support unary minus in factor position.

### FR-005 Evaluation
- The evaluator shall recursively evaluate AST to `long long`.
- Division by zero shall produce an error status.

### FR-006 Error Reporting
- Every module failure shall return `Status{ok=false,...}`.
- Errors shall include message and position when applicable.
- The controller shall format user-facing error output.

### FR-007 Modular Boundaries
- `main()` shall remain orchestration-only.
- Tokenizer, parser, and evaluator logic shall remain outside `main()`.

## 3. Non-Functional Requirements

### NFR-001 Clarity and Teachability
- Code should prioritize readability and explicit contracts over cleverness.

### NFR-002 Maintainability
- Interfaces and implementations should be separated (`.h` and `.cpp`).
- Module responsibilities must remain distinct.

### NFR-003 Portability
- Build target is C++17 compatible toolchains (g++, clang++).

### NFR-004 Safety
- No unhandled exceptions required in baseline path.
- Failures should be explicit via result/status objects.

### NFR-005 Diagnostics
- Error positions should be deterministic and reproducible.

## 4. Constraints

- Language: C++17
- Numeric domain: `long long` integers only
- Error model: `Status` structs (not exceptions) in baseline
- API style: namespace-level free functions
- Parser style: recursive descent

## 5. Assumptions

- Input is plain text from terminal.
- Users may enter malformed expressions frequently.
- REPL must recover from errors and continue.

## 6. Out of Scope (Baseline)

- Floating point parsing/evaluation
- Variables and assignment
- User-defined functions
- Symbol tables
- Optimization passes

## 7. Acceptance Criteria by Stage

### Stage 1
- Headers and source files compile.
- `main()` calls `repl()` only.
- `:help` and `:quit` command paths work.

### Stage 2
- Valid token streams emitted for expected inputs.
- Invalid characters and overflow return position-aware errors.

### Stage 3
- Parser builds AST according to grammar.
- Parser failures include message and token position.

### Stage 4
- Evaluator returns correct integer results.
- Division by zero returns status error.

### Stage 5
- Error style is normalized across modules.
- REPL continues safely after any module error.

### Stage 6
- Optional ergonomics features (overloads/default args/inline helpers) compile and behave.
