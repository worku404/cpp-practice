# API Reference

All APIs are in namespace `expr`.

## 1. utilities.h

```cpp
struct Status {
    bool ok;
    std::string message;
    std::size_t position;
};

Status make_ok();
Status make_error(const std::string& message, std::size_t position = 0);
inline bool is_ok(const Status& status);
```

### Behavior
- `make_ok()` creates success status.
- `make_error(...)` creates failure status.
- `is_ok(...)` returns `status.ok`.

## 2. tokenizer.h

```cpp
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
    std::size_t position;
};

struct TokenizeResult {
    std::vector<Token> tokens;
    Status status;
};

TokenizeResult tokenize(const std::string& expression);
```

### Token Rules
- `Number` uses `value`.
- Non-number tokens set `value` to `0` by convention.
- `End` token marks stream completion.

## 3. parser.h (current + planned)

Current header:

```cpp
struct AstNode {
    int placeholder;
};

struct ParseResult {
    AstNode* root;
    Status status;
};

ParseResult parse(const std::vector<Token>& tokens);
```

Planned API evolution:

```cpp
struct ParseResult {
    std::unique_ptr<AstNode> root;
    Status status;
};
```

Rationale:
- explicit ownership and leak safety

## 4. evaluator.h

```cpp
struct EvalResult {
    long long value;
    Status status;
};

EvalResult evaluate(const AstNode& root);
```

### Behavior
- On success: valid `value`, `status.ok == true`
- On failure: `status.ok == false`, `value` can be ignored

## 5. controller.h

```cpp
Status run_once(const std::string& line, std::ostream& out);
void repl(std::istream& in, std::ostream& out);
```

### Behavior
- `run_once`: process one input line and return status
- `repl`: read loop with command handling and error output

## 6. Invariants

- Every module returns status-aware result object.
- Errors should never be silently swallowed.
- Public APIs should remain stable and minimal.
