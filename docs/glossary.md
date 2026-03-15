# Glossary

## AST (Abstract Syntax Tree)
Tree representation of expression structure after parsing.

## Token
Smallest meaningful lexical unit produced by tokenizer (number, operator, parenthesis, end marker).

## Recursive Descent Parser
Parser built from mutually recursive functions that mirror grammar rules.

## Precedence
Rule that determines operation order, for example `*` before `+`.

## Associativity
Rule for same-precedence chaining, for example `7 - 3 - 1` is `(7 - 3) - 1`.

## REPL
Read-Eval-Print Loop. Repeatedly reads input, processes it, and prints output.

## Contract
Explicit promise of function/module behavior, inputs, outputs, and failure model.

## Status Object
Struct carrying success/failure info (`ok`, message, position).

## Lexical Analysis
Conversion of input characters into tokens.

## Syntax Analysis
Validation of token sequence against grammar and AST construction.

## Post-order Evaluation
Recursive evaluation strategy where child nodes are evaluated before parent operation.

## Modular Decomposition
Design practice of splitting a system into focused, independent components.
