# User Guidance

## 1. Purpose

This guide explains how to build and use the project from a terminal.

## 2. Prerequisites

- C++17 compiler (`g++` or `clang++`)
- Terminal environment

## 3. Build

From project root:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic *.cpp -o expr_eval
```

If your compiler is `clang++`:

```bash
clang++ -std=c++17 -Wall -Wextra -pedantic *.cpp -o expr_eval
```

## 4. Run

Linux/macOS:

```bash
./expr_eval
```

Windows PowerShell:

```powershell
.\expr_eval.exe
```

## 5. CLI Commands

- `:help` - show help text
- `:quit` - exit REPL

## 6. Current Runtime Behavior

Current implementation status is partial:
- `:help` and `:quit` work.
- Non-command input currently returns `Not implemented yet in Stage 1`.

This is expected until parser and evaluator stages are completed.

## 7. Future Expression Usage (Target Behavior)

When all planned stages are complete, these should work:

- `3 + 4 * (2 - 1)` -> `7`
- `-5 + 2 * 3` -> `1`
- `((1+2)*3)-4` -> `5`

## 8. Common Error Scenarios (Target)

- `12a + 3` -> tokenizer error
- `3 + * 4` -> parser error
- `(1 + 2` -> missing parenthesis error
- `10 / 0` -> evaluator division by zero error

## 9. Troubleshooting

### Build fails with missing standard support
Use explicit C++17 flag:

```bash
-std=c++17
```

### Warnings are noisy
Warnings are useful during development. Keep `-Wall -Wextra -pedantic` enabled.

### Program exits immediately
Check if input stream reached EOF (for example, redirected input finished).

## 10. Recommended Usage Pattern

1. Start REPL.
2. Try `:help`.
3. Test one expression at a time.
4. If error appears, note message and position.
5. Continue without restarting REPL.
