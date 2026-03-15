# Roadmap

## Overview

This roadmap follows the decision-complete six-stage teaching plan.

## Stage 1 - Project Structure and Modular Decomposition

Deliverables:
- Header/source split created
- `Status` contract introduced
- Controller stubs and thin `main()`
- `:help` command path

Status:
- Partially complete and present in repository

## Stage 2 - Tokenization

Deliverables:
- `tokenize(...)` implementation
- whitespace and operator scanning
- integer scanning and overflow detection
- explicit `End` token

Status:
- Implemented in repository

## Stage 3 - Recursive Parsing

Deliverables:
- recursive descent parser
- AST node model with operator representation
- parse errors with positions

Status:
- Pending (stub currently)

## Stage 4 - Expression Evaluation

Deliverables:
- recursive AST evaluator
- arithmetic helper operations
- divide-by-zero handling via `Status`

Status:
- Pending (stub currently)

## Stage 5 - Error Handling Normalization

Deliverables:
- consistent error style across modules
- boundary contract checks
- REPL recovery verification

Status:
- Pending

## Stage 6 - Language Feature Enhancements

Deliverables:
- overloads for string conversion helpers
- default args for error printing/debug entrypoints
- justified inline helper predicates
- optional debug token/AST display

Status:
- Pending

## Milestone Exit Criteria

1. All planned stages implemented.
2. Test matrix passes.
3. Documentation reflects final behavior.
4. Portfolio-ready README and docs alignment complete.

## Risks and Mitigations

- Risk: parser complexity increases quickly
  - Mitigation: implement grammar functions incrementally and test each
- Risk: error contracts diverge across modules
  - Mitigation: central error-style rules in `error-model.md`
- Risk: docs drift from code
  - Mitigation: update docs in same PR as behavior changes
