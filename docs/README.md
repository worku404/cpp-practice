# Documentation Hub

This folder contains complete project documentation for the Mini Expression Evaluator.

## What This Project Is

Mini Expression Evaluator is a C++17 command-line project built as a teaching-quality system for expression processing using a modular pipeline:

`tokenizer -> parser (AST) -> evaluator -> controller/repl`

## Documentation Map

- [requirements.md](requirements.md) - functional and non-functional requirements, assumptions, and acceptance criteria
- [user-guidance.md](user-guidance.md) - install/build/run instructions and CLI usage
- [technical.md](technical.md) - architecture, grammar, data flow, and core design decisions
- [api-reference.md](api-reference.md) - public API contracts for each module
- [error-model.md](error-model.md) - failure contracts, error propagation, and formatting conventions
- [testing.md](testing.md) - stage verification and test matrix
- [developer.md](developer.md) - development workflow, coding standards, and implementation guidance
- [roadmap.md](roadmap.md) - stage-by-stage execution plan and milestones
- [glossary.md](glossary.md) - shared terms and definitions

## Current Implementation Snapshot

As of 2026-03-02:
- `utilities` is implemented
- `tokenizer` is implemented (including integer overflow detection)
- `controller` REPL basics are implemented (`:help`, `:quit`)
- `parser` and `evaluator` are stubbed and return not-implemented status

Read [roadmap.md](roadmap.md) for completion path.

## Reading Order

1. `requirements.md`
2. `technical.md`
3. `api-reference.md`
4. `error-model.md`
5. `testing.md`
6. `developer.md`
7. `roadmap.md`

## Audience

- Portfolio reviewers who need system-level understanding
- Developers onboarding to the codebase
- Students using this project to learn modular C++ design
