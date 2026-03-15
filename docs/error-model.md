# Error Model

## 1. Philosophy

The project uses explicit status-return contracts instead of exceptions in baseline stages.

This makes failure flow visible at every call site and is aligned with the teaching objective.

## 2. Core Structure

```cpp
struct Status {
    bool ok;
    std::string message;
    std::size_t position;
};
```

Meaning:
- `ok` : success flag
- `message` : human-readable error explanation
- `position` : source offset in input when relevant

## 3. Error Propagation Rule

For each layer:
1. Call dependency.
2. If dependency failed, return failure immediately.
3. Do not continue processing invalid intermediate state.

## 4. Module-specific Failure Ownership

- tokenizer: lexical errors, invalid characters, number overflow
- parser: unexpected token, missing operand, missing `)`
- evaluator: division by zero, invalid AST shape
- controller: formatting and display, but not deep module logic

## 5. Message Style Guideline

Use concise, position-aware, deterministic messages.

Preferred examples:
- `Invalid character in expression`
- `Expected ')'`
- `Unexpected token '*'`
- `Division by zero`

## 6. Position Semantics

- Position is zero-based index into original input.
- For user-facing display, decide and document whether conversion to one-based view is applied.

Current code note:
- Controller currently prints position only when `position != 0`.
- This can hide valid errors at input index `0`.
- Recommended fix: print position for all failures, including zero.

## 7. Contract Checklist

- If `ok == false`, message must not be empty.
- If lexical/syntax/runtime source is known, position should be set.
- Success statuses should carry empty message.

## 8. Why Not Exceptions (Baseline)

Tradeoff summary:
- Status objects improve explicitness for learning flow.
- Exceptions may reduce boilerplate but hide control transfer.

The project can introduce exceptions later as an advanced extension.
